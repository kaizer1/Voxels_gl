

import lMath;
import lOpenGL;

using namespace losMath;
using namespace losGraphics;

#include "Mdel.h"
#include "lDefine.h"
#include "GL_utilities.h"

Mdel::Mdel() {
	subDrawID = 0;
	subVoxelizeID = 0;
	diffuseID = 0;
	maskID = 0;
	diffColor = lv3(1.0f, 0.0f, 0.0f);

	vao = 0;
}

void Mdel::SetMaterial(TextureData* textureData) {
	subDrawID = textureData->subID;
	subVoxelizeID = (lUnsignedInt)(subDrawID != 0);
	diffuseID = textureData->diffuseID;
	maskID = textureData->maskID;
	diffColor = textureData->diffColor;
}

void Mdel::SetStandardData(size_t numVertices, lFloat* verticeData,
	size_t numNormals, lFloat* normalData,
	size_t numIndices, lUnsignedInt* indexData,
	size_t numTangents, lFloat* tangentData,
	size_t numBiTangents, lFloat* biTangentData) {

	nIndices = numIndices;
	// Create buffers
	if (vao == 0) {
		//checkGLError(glGenVertexArrays(1, &vao));
		glGenVertexArraysm(1, &vao);
		checkGLError();
			
	}

	  glGenBuffersm(5, meshBuffers);
	  checkErrorLos(1);

	  // GL_ARRAY_BUFFER
	// Allocate enough memory for instanced drawing buffers
	glBindBufferm(glArrayBuf, meshBuffers[0]);
	glBufferDatam(glArrayBuf, sizeof(lFloat) * numVertices,
		verticeData, glStatDraw);

	glBindBufferm(glArrayBuf, meshBuffers[1]);
	glBufferDatam(glArrayBuf, sizeof(lFloat) * numNormals,
		normalData, glStatDraw);

	glBindBufferm(glArrayBuf, meshBuffers[2]);
	glBufferDatam(glArrayBuf, sizeof(lFloat) * numTangents,
		tangentData, glStatDraw);

	glBindBufferm(glArrayBuf, meshBuffers[3]);
	glBufferDatam(glArrayBuf, sizeof(lFloat) * numBiTangents,
		biTangentData, glStatDraw);

	glBindBufferm(glElementArrayBuffer, meshBuffers[4]);
	glBufferDatam(glElementArrayBuffer, sizeof(lFloat) * numIndices,
		indexData, glStatDraw);

	// Set the GPU pointers for drawing
	glBindVertexArraym(vao);

	glBindBufferm(glArrayBuf, meshBuffers[0]);
    glEnableVertexAttribArraym(VERT_POS);
	glVertexAttribPointerm(VERT_POS, 3, glFloat, GLFALSE, 0, 0);

	glBindBufferm(glArrayBuf, meshBuffers[1]);
	glEnableVertexAttribArraym(VERT_NORMAL);
	glVertexAttribPointerm(VERT_NORMAL, 3, glFloat, GLFALSE, 0, 0);

	glBindBufferm(glArrayBuf, meshBuffers[2]);
	glEnableVertexAttribArraym(VERT_TANGENT);
	glVertexAttribPointerm(VERT_TANGENT, 3, glFloat, GLFALSE, 0, 0);

	glBindBufferm(glArrayBuf, meshBuffers[3]);
	glEnableVertexAttribArraym(VERT_BITANGENT);
	glVertexAttribPointerm(VERT_BITANGENT, 3, glFloat, GLFALSE, 0, 0);

	glBindBufferm(glElementArrayBuffer, meshBuffers[4]);
	glBindVertexArraym(0);
	glBindBufferm(glElementArrayBuffer, 0);
}

void Mdel::SetTextureData(size_t numTexCoords, GLfloat* texCoordData) {
	if (vao == 0) {
		glGenVertexArraysm(1, &vao);
	}
	glGenBuffersm(1, &texbufferID);

	// Allocate enough memory for instanced drawing buffers
	glBindBufferm(glArrayBuf, texbufferID);
	glBufferDatam(glArrayBuf, sizeof(lFloat) * numTexCoords,
		texCoordData, glStatDraw);

	// Set the data pointer for the draw program
	glBindVertexArraym(vao);

	glBindBufferm(glArrayBuf, texbufferID);
    glEnableVertexAttribArraym(VERT_TEX_COORD);
	glVertexAttribPointerm(VERT_TEX_COORD, 2, glFloat, GLFALSE, 0, 0);

	glBindVertexArraym(0);
}

void Mdel::SetPositionData(GLuint positionBufferID) {
	if (vao == 0) {
		glGenVertexArraysm(1, &vao);
	}
	glBindVertexArraym(vao);

	glBindBufferm(glArrayBuf, positionBufferID);
	glEnableVertexAttribArraym(DATA_POS);
	glVertexAttribIPointerm(DATA_POS, 1, glUnsignedInt, 0, 0);
	glVertexAttribDivisorm(DATA_POS, 1);

	glBindVertexArraym(0);
}

bool Mdel::hasDiffuseTex() {
	return diffuseID != 0;
}

bool Mdel::hasMaskTex() {
	return maskID != 0;
}

void Mdel::Voxelize() {
	glUniform3fm(DIFF_COLOR, diffColor.x, diffColor.y, diffColor.z);

    glActiveTexturem(glTex0);
	glBindTexturem(glTex2D, diffuseID);

	glBindVertexArraym(vao);
	glUniform1im(SUBROUTINE, subVoxelizeID);

	drawElements(glTriangles, (GLsizei)nIndices, glUnsignedInt, 0L);
}

void Mdel::ShadowMap() {
	glBindVertexArraym(vao);
	drawElements(glTriangles, (GLsizei)nIndices, glUnsignedInt, 0L);
}

void Mdel::Draw() {
	glUniform3fm(DIFF_COLOR, diffColor.x, diffColor.y, diffColor.z);
	glActiveTexturem(glTex0);
	glBindTexturem(glTex2D, diffuseID);
	glActiveTexturem(glTex1);
	glBindTexturem(glTex2D, maskID);
	glBindVertexArraym(vao);
	glUniform1im(SUBROUTINE, subDrawID);
	// Disable cull faces for transparent models
	if (hasMaskTex()) {
		glDisablem(glCullFa);
	}
	else {
		glEnablem(glCullFa);
	}
	drawElements(glTriangles, (GLsizei)nIndices, glUnsignedInt, 0L);
}
