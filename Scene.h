#pragma once


import lMath;
import lOpenGL;


using namespace losMath;
using namespace losGraphics;


#include "Mdel.h"
#include "GL_utilities.h"
#include "tiny_obj_loader.h"

#define MAX_MIP_MAP_LEVELS 8
#define MAX_VOXEL_RES 256
// 256 ^ 3
#define MAX_SPARSE_BUFFER_SIZE 16777216

// Values the should exist on the GPU
struct SceneParam {
    lm44 MTOmatrix[3]; // Centers and scales scene to fit inside +-1 from three different rotations
    lm44 MTWmatrix; // Matrix for voxel data
    lm44 MTShadowMatrix; // Matrix that transforms scene to lightview
    lv3 lightDir;
    lUnsignedInt voxelDraw; // Which texture to draw
    lUnsignedInt view;
    lUnsignedInt voxelRes;
    lUnsignedInt voxelLayer;
    lUnsignedInt numMipLevels;
    lUnsignedInt mipLevel;
};

// Scene Options struct
struct SceneOptions {
    bool skipNoTexture;
    bool drawVoxels;
    bool drawModels;
    bool drawTextures;
    lUnsignedInt shadowRes;
};

// The different view directions
enum ViewDirection {
    VIEW_X,
    VIEW_Y,
    VIEW_Z
};

// Voxel Resolutions used
enum VoxelResolutions {
    RES16 = 16,
    RES32 = 32,
    RES64 = 64,
    RES128 = 128,
    RES256 = 256
};

// ===== ModelLoader class =====

class Scene {
private:
    // All models contained in the scene
    std::vector<Mdel*>* models;
    Mdel* voxelModel;

    // Programs used to draw models
    ShaderList* shaders;

    // Scene Options
    SceneOptions options;

    // Uniform buffer with scene settings
    SceneParam param;
    lUnsignedInt sceneBuffer;

    // Draw indirect buffer and struct
    DrawElementsIndirectCommand drawIndCmd[10];
    lUnsignedInt drawIndBuffer;

    // Compute indirect buffer and struct
    ComputeIndirectCommand compIndCmd[10];
    lUnsignedInt compIndBuffer;

    // Sparse List Buffer
    lUnsignedInt sparseListBuffer;

    // FBOs
    lUnsignedInt voxelFBO; //		Empty framebuffer for voxelization
    lUnsignedInt shadowFBO; //	Framebuffer with depth texture for shadowmap
    lUnsignedInt sceneFBO; //		Framebuffer for deferred rendering

    // Scene textures
    lUnsignedInt voxel2DTex;
    lUnsignedInt voxelTex;
    lUnsignedInt shadowTex;
    lUnsignedInt sceneTex[2]; // Color array and depth texture

    // Scene information
    lv3* maxVertex, * minVertex, centerVertex;
    lFloat scale;

    // Init functions
    void InitBuffers();

    bool InitVoxel();

    // Setup functions
    void SetupDrawInd();

    void SetupCompInd();

    bool SetupScene(const char* path);

    void SetupVoxelTextures();

    void SetupShadowTexture();

    void SetupShadowMatrix();

    // Draw functions
    void DrawTextures();

    void DrawScene();

    void DrawVoxels();

public:
    Scene();

    bool Init(const char* path, ShaderList* initShaders);

    void CreateShadow();

    void RenderData();

    void Voxelize();

    void MipMap();

    void Draw();

    void UpdateBuffers();

    void SetupSceneTextures();
};


