#pragma once

//#include <GLES3/gl31.h>
//#include "glm/glm.hpp"

import lMath;
import lOpenGL;

using namespace losMath;
using namespace losGraphics;

// ===== Texture Struct =====

struct TextureData {
    lInt subID;
    lUnsignedInt diffuseID;
    lUnsignedInt maskID;
    lv3 diffColor;
};

// ===== Model Class =====

class Mdel {
public:
    Mdel();

    void SetStandardData(size_t numVertices, lFloat* verticeData,
        size_t numNormals, lFloat* normalData,
        size_t numIndices, lUnsignedInt* indexData,
        size_t numTangents, lFloat* tangentData,
        size_t numBiTangents, lFloat* biTangentData);

    void SetMaterial(TextureData* textureData);

    void SetTextureData(size_t numTexCoords, lFloat* texCoordData);

    // Set position buffer data, only for voxel model
    void SetPositionData(lUnsignedInt positionBufferID);

    bool hasDiffuseTex();

    bool hasMaskTex();

    void Draw();

    void Voxelize();

    void ShadowMap();

    lUnsignedInt GetVAO() { return vao; }

    lUnsignedInt GetDiffuseID() { return diffuseID; }

    lUnsignedInt GetMaskID() { return maskID; }

    lv3 GetDiffColor() { return diffColor; }

    size_t GetNumIndices() { return nIndices; }

private:
    lUnsignedInt vao;
    lUnsignedInt meshBuffers[5];
    size_t nIndices;

    // Only used by textured models
    lUnsignedInt diffuseID;
    lUnsignedInt maskID;
    lUnsignedInt texbufferID;
    lUnsignedInt subDrawID;
    lUnsignedInt subVoxelizeID;

    //
    lv3 diffColor;
};

