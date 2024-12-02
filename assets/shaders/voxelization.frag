#version 450

precision highp float;
precision highp int;

in vec2 intTexCoords;
in vec4 shadowCoord;
in vec3 exNormal;

flat in uint domInd;

layout(location = 0) uniform vec3 diffColor;
layout(location = 10) uniform int colorPicker;

layout(binding = 0) uniform sampler2D diffuseUnit;
layout(binding = 2, r32ui) uniform highp uimage2DArray voxelTextures;
layout(binding = 3, r32ui) uniform highp uimage3D voxelData;
layout(binding = 5) uniform sampler2D shadowMap;

struct SceneParams {
	mat4 MTOmatrix[3];
	mat4 MTWmatrix;
	mat4 MTShadowMatrix;
	vec3 lightDir;
	uint voxelDraw;
	uint view;
	uint voxelRes;
	uint voxelLayer;
	uint numMipLevels;
	uint mipLevel;
};

layout (std140, binding = 1) uniform SceneBuffer {
	SceneParams scene;
};

struct DrawElementsIndirectCommand {
	uint vertexCount;
	uint instanceCount;
	uint firstVertex;
	uint baseVertex;
	uint baseInstance;
};

layout(std430, binding = 0) buffer DrawCmdBuffer {
	DrawElementsIndirectCommand drawCmd[10];
};

struct ComputeIndirectCommand {
	uint workGroupSizeX;
	uint workGroupSizeY;
	uint workGroupSizeZ;
};

layout(std430, binding = 1) buffer ComputeCmdBuffer {
	ComputeIndirectCommand compCmd[10];
};

layout(std430, binding = 2) writeonly buffer SparseBuffer {
	uint sparseList[];
};

struct VoxelData {
	vec4 color;
	uint light;
	uint count;
};

uint packARGB8(VoxelData dataIn) {
	uint result = uint(0);

	uvec3 uiColor = uvec3(dataIn.color.rgb * 31.0f * float(dataIn.count));

	result |= (dataIn.light & uint(0x0F)) << 28;
	result |= (dataIn.count & uint(0x0F)) << 24;
	result |= (uiColor.r & uint(0xFF)) << 16;
	result |= (uiColor.g & uint(0xFF)) << 8;
	result |= (uiColor.b & uint(0xFF));

	return result;
}

uint packRG11B10(uvec3 dataIn) {
	uint result = uint(0);

	result |= (dataIn.r & uint(0x7FF)) << 21;
	result |= (dataIn.g & uint(0x7FF)) << 10;
	result |= (dataIn.b & uint(0x3FF));

	return result;
}



vec4 DiffuseColor() {
	return vec4(diffColor, 1.0f);
}



vec4 TextureColor() {
	return vec4(texture(diffuseUnit, intTexCoords).rgb, 1.0f);
}

vec4 GetColor() {
    switch(colorPicker) {
        case 0: return DiffuseColor();
        case 1: return TextureColor();
        default: return vec4(1.0f, 0.0f, 0.0f, 1.0f);
    }
    return vec4(1.0f, 0.0f, 0.0f, 1.0f);
}

void main()
{	

	VoxelData data = VoxelData(GetColor(), uint(0x0), uint(0x8));

	ivec3 voxelCoord;
	float res = float(scene.voxelRes);
	float depthCoord = gl_FragCoord.z * res;


	if(domInd == uint(0)) {
		voxelCoord = ivec3(depthCoord, gl_FragCoord.y, res - gl_FragCoord.x);
	} else if (domInd == uint(1)) {
		voxelCoord = ivec3(gl_FragCoord.x, depthCoord, res - gl_FragCoord.y);
	} else {
		voxelCoord = ivec3(gl_FragCoord.x, gl_FragCoord.y, depthCoord);
	}


	vec3 lightCoord = shadowCoord.xyz / 2.0f;
	lightCoord += vec3(0.5f);

	float shadowDepth = texture(shadowMap, lightCoord.xy).r;
	float cosTheta = clamp(dot(normalize(exNormal), normalize(scene.lightDir)), 0.0f, 1.0f);
	float bias = 0.005f*tan(acos(cosTheta));
	bias = clamp(bias, 0.0f, 0.01f);

	if((shadowDepth > lightCoord.z - bias) && (dot(normalize(scene.lightDir), normalize(exNormal)) > 0.0f)) {
		data.light = uint(0x8);
	}

	uint outData = packARGB8(data);

	imageAtomicMax(voxelTextures, ivec3(ivec2(gl_FragCoord.xy), domInd), outData);
	uint prevData = imageAtomicMax(voxelData, voxelCoord, outData);


	if(prevData == uint(0)) {

		uint nextIndex = atomicAdd(drawCmd[0].instanceCount, uint(1));
		

		uint compWorkGroups = ((nextIndex + uint(1)) >> 6) + uint(1); // 6 = log2(workGroupSize = 64)
		atomicMax(compCmd[0].workGroupSizeX, compWorkGroups);

		// final
		sparseList[nextIndex + drawCmd[0].baseInstance] = packRG11B10(uvec3(voxelCoord));
	}
}