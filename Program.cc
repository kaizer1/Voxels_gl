#include "Program.h"

#include "lDefine.h"

import lOpenGL;

using namespace losGraphics;



Program::Program() {
    // Set all pointers to null
    cam = NULL;

    // Window init size
    winWidth = 0;
    winHeight = 0;

    // Time init
    time.startTimer();

    // Set program parameters
    cameraStartPos = lv3(0.0f, 0.0f, 3.0f);
    cameraFrustumFar = 500.0f;

    sceneSelect = 0;
    useOrtho = false;
    drawVoxelOverlay = false;
}

Program::~Program() {
    Clean();
}

void Program::Step() {
    //LOGD("Step called");
//    glTime.startTimer();
    Update();
    //    glTime.endTimer();
    //    LOGD("Update time: %f ms", glTime.getTimeMS());
    //    glTime.startTimer();
    Render();
    //    glTime.endTimer();
    //    LOGD("Draw time: %f ms", glTime.getTimeMS());
}

void Program::Resize(int width, int height) {
   // LOGD("Resize called, width: %d, height: %d", width, height);

    winWidth = width;
    winHeight = height;
    setGLViewPort(0, 0, width, height);
    cam->SetFrustum();
    GetCurrentScene()->SetupSceneTextures();
    //    GetCurrentScene()->Voxelize();
}

/*
void Program::timeUpdate() {
    time.endTimer();
    param.deltaT = time.getLapTime();
    param.currentT = time.getTime();
    FPS = 1.0f / time.getLapTime();
}
*/

bool Program::Init() {
   // LOGD("Init called");

    // Activate depth test and blend for masking textures
    glEnablem(glDepthTest);
    glEnablem(glCullFa);
    //glEnable(GL_TEXTURE_3D);
    glEnablem(glBlend);
    glBlendFuncm(srcAlpha, srcAlphaMinus);
   // glClearColor(0.3f, 0.0f, 0.3f, 1.0f);
    callClear(0.3f, 0.0f, 0.3f, 1.0f);
    dumpInfo();

    glGenBuffersm(1, &programBuffer);
    glBindBufferBasem(uniformBuffer, PROGRAM, programBuffer);
    glBufferDatam(uniformBuffer, sizeof(ProgramStruct), &param, streamDRaw);

    // Load shaders for drawing
    shaders.drawScene = loadShaders(SHADER_PATH("drawModel.vert"), SHADER_PATH("drawModel.frag"));
    shaders.drawData = loadShaders(SHADER_PATH("drawData.vert"), SHADER_PATH("drawData.frag"));

    // Load shaders for voxelization
    shaders.voxelize = loadShadersG(SHADER_PATH("voxelization.vert"),
        SHADER_PATH("voxelization.frag"),
        SHADER_PATH("voxelization.geom"));

    // Single triangle shader for deferred shading etc.
    shaders.singleTriangle = loadShaders(SHADER_PATH("drawTriangle.vert"),
        SHADER_PATH("drawTriangle.frag"));

    // Draw voxels from 3D texture
    shaders.voxel = loadShaders(SHADER_PATH("drawVoxel.vert"), SHADER_PATH("drawVoxel.frag"));

    // Calculate mipmaps
    shaders.mipmap = CompileComputeShader(SHADER_PATH("mipmap.comp"));

    // Create shadowmap
    shaders.shadowMap = loadShaders(SHADER_PATH("shadowMap.vert"), SHADER_PATH("shadowMap.frag"));

    InitTimer();

    // Set up the camera
    cam = new CameraL(cameraStartPos, &winWidth, &winHeight, cameraFrustumFar);
    if (!cam->Init()) {
       // LOGE("Camera not initialized!");
        return false;
    }

    // Load Asset folders
    LoadAssetFolder("models");

    // Load scenes
    Scene* cornell = new Scene();
    if (!cornell->Init(MODEL_PATH("cornell.obj"), &shaders)) {
        ///LOGE("Error loading scene: Cornell!");
        return false;
    }
    scenes.push_back(cornell);

    //    Scene *sponza = new Scene();
    //    if (!sponza->Init(MODEL_PATH("sponza.obj"), &shaders)) return false;
    //    scenes.push_back(sponza);

        // Initial Voxelization of the scenes
    cornell->CreateShadow();
    cornell->RenderData();
    cornell->Voxelize();
    cornell->MipMap();

    //    sponza->CreateShadow();
    //    sponza->RenderData();
    //    sponza->Voxelize();
    //    sponza->MipMap();

    return true;
}

void Program::Update() {
    // Upload program params (incl time update)
    UploadParams();

    // Update the camera
    cam->UpdateCamera();
}

void Program::Render() {
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    callClearPure();

    GetCurrentScene()->CreateShadow();
    GetCurrentScene()->RenderData();
    GetCurrentScene()->Voxelize();
    GetCurrentScene()->MipMap();
    GetCurrentScene()->Draw();
}

void Program::Clean() {
    glDeleteBuffersm(1, &programBuffer);
}

void Program::UploadParams() {
    // Update program parameters
    glBindBufferBasem(uniformBuffer, PROGRAM, programBuffer);
    glBufferSubDatam(uniformBuffer, NULL, sizeof(ProgramStruct), &param);
}
