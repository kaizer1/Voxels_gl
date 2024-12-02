#version 450

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inNormal;
layout(location = 3) in uint inVoxelPos;

out vec4 outPosition;
out vec3 outNormal;
out vec4 outColor;

layout(binding = 3) uniform highp usampler3D voxelData;

struct Camera {
	mat4 WTVmatrix;
	mat4 VTPmatrix;
	vec3 position;
};

layout (std140, binding = 0) uniform CameraBuffer {
	Camera cam;
};

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

struct VoxelData {
	vec4 color;
	uint light;
	uint count;
};

VoxelData unpackARGB8(uint bytesIn) {
	VoxelData data;
	uvec3 uiColor;


	data.light = (bytesIn & uint(0xF0000000)) >> 28;
	data.count = (bytesIn & uint(0x0F000000)) >> 24;
	uiColor.r =  (bytesIn & uint(0x00FF0000)) >> 16;
	uiColor.g =  (bytesIn & uint(0x0000FF00)) >> 8;
	uiColor.b =  (bytesIn & uint(0x000000FF));

	data.color.rgb = vec3(uiColor) / float(data.count) / 31.0f;
	data.color.a = 1.0f;

	return data;
}

uvec3 unpackRG11B10(uint bytesIn) {
	uvec3 outVec;

	outVec.r = (bytesIn & uint(0xFFE00000)) >> 21;
	outVec.g = (bytesIn & uint(0x001FFC00)) >> 10;
	outVec.b = (bytesIn & uint(0x000003FF));

	return outVec;
}

void main(void)
{
	float size = float(scene.voxelRes >> scene.mipLevel);
	vec3 voxelPos = vec3(unpackRG11B10(inVoxelPos)) / size;

	VoxelData data = unpackARGB8(textureLod(voxelData, voxelPos, float(scene.mipLevel)).r);
	data.color.rgb *= float(sign(int(data.light)));
	outColor = /*vec4(data.color.rgb * 0.5f, 1.0f);//*/ data.color;
	
	outNormal = mat3(cam.WTVmatrix) * inNormal;
	vec4 temp = cam.WTVmatrix * scene.MTWmatrix * vec4(inPosition / size + 2.0f * voxelPos - vec3(1.0f), 1.0f);
	outPosition = temp;
	gl_Position = cam.VTPmatrix * temp;
}

