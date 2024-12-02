#pragma once


import lMath;
import lOpenGL;


using namespace losMath;
using namespace losGraphics;



#include "Camera.h"
#include "Scene.h"

#include "GL_utilities.h"


struct ProgramStruct {
    lFloat currentT;
    lFloat deltaT;
};

class Program {
private:
    GLint winWidth, winHeight;

    Timer time;
    //    GLTimer glTime;
    lFloat FPS;
    ProgramStruct param;
    GLuint programBuffer;

    bool useOrtho;
    bool drawVoxelOverlay;
    CameraL* cam;
    // Shaders
    ShaderList shaders;

    // Model
    GLuint sceneSelect;
    std::vector<Scene*> scenes;

    // Program params
    lv3 cameraStartPos;
    lFloat cameraFrustumFar;

    // Methods
    void UploadParams();

    Scene* GetCurrentScene() { return scenes[sceneSelect]; }

public:
    Program();
    ~Program();

    //void SetAssetMgr(AAssetManager* mgr);
    bool Init();
    void Resize(int width, int height);
    void Step();

    //void timeUpdate();
    //void OnEvent(SDL_Event *Event);
    //void OnKeypress(SDL_Event *Event);
    //void OnMouseMove(SDL_Event *Event);
    //void CheckKeyDowns();

    void Update();
    void Render();

    void Clean();

};

