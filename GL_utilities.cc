

import lMath;
import lOpenGL;

using namespace losMath;
using namespace losGraphics;


#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "GL_utilities.h"

#include "lDefine.h"




void SetAssetsManager() {
 //   mgr = initMgr;
    //const char* temp = getenv("EXTERNAL_STORAGE");
}

// Load asset folder to file

void LoadAssetFolder(const char* folderName) {
    //AAssetDir* assetDir = AAssetManager_openDir(mgr, folderName);
   

}

// Shader loader

char* readFile(const char* file) {
    size_t length;
    char* buf;
    if (file == NULL) {
        return NULL;
    }

    // Null terminator

    return buf; // Return the buffer
}

// Infolog: Show result of shader compilation
GLint printShaderInfoLog(GLuint obj, const char* fn) {
    GLint infologLength = 0;
    GLint charsWritten = 0;
    char* infoLog;

    GLint wasError = 0;

    glGetShaderiv(obj, infoLogLeng, &infologLength);

    if (infologLength > 2) {
        //LOGE("[From %s:]\n", fn);
        infoLog = (char*)malloc((size_t)infologLength);
        glGetShaderInfoLog(obj, infologLength, &charsWritten, infoLog);
        //LOGE("%s\n", infoLog);
        free(infoLog);
        wasError = 1;
    }

    return wasError;
}

GLint printProgramInfoLog(GLuint obj, const char* vfn, const char* ffn,
    const char* gfn, const char* tcfn, const char* tefn) {
    GLint infologLength = 0;
    GLint charsWritten = 0;
    char* infoLog;

    GLint wasError = 0;

    glGetProgramiv(obj, infoLogLeng, &infologLength);

    if (infologLength > 2) {
      //  LOGE("[From %s", vfn);
        if (ffn != NULL)
        //    LOGE("+%s", ffn);
        if (gfn != NULL)
        //    LOGE("+%s", gfn);
        if (tcfn != NULL && tefn != NULL)
        //    LOGE("+%s+%s", tcfn, tefn);
        //LOGE(":]\n");

        infoLog = (char*)malloc((size_t)infologLength);
        GL_CHECK(glGetProgramInfoLog(obj, infologLength, &charsWritten, infoLog));
        //LOGE("%s\n", infoLog);
        free(infoLog);

        wasError = 1;
    }

    return wasError;
}

// Compile a shader, return reference to it
GLuint compileShaders(const char* vs, const char* fs, const char* gs, const char* tcs,
    const char* tes,
    const char* vfn, const char* ffn, const char* gfn, const char* tcfn,
    const char* tefn) {
    GLuint v, f, g, tc, te, p;

    p = glCreateProgramm();

    v = glCreateShaderm(0x8B31); // GL_VERTEX_SHADER
    f = glCreateShaderm(0x8B30); // GL_FRAGMENT_SHADER
    g = glCreateShaderm(0x8DD9); // GL_GEOMETRY_SHADER
    tc = glCreateShaderm(0x8E88); // GL_TESS_CONTROL_SHADER
    te = glCreateShaderm(0x8E87);//  GL_TESS_EVALUATION_SHADER
     
   /* glShaderSource(v, 1, &vs, NULL);
    glCompileShader(v);
    glAttachShader(p, v);
    glDeleteShader(v);*/

    shaderAllComplete(p, v, vs);

    printShaderInfoLog(v, vfn);

    if (fs != NULL) {
 /*       GL_CHECK(glShaderSource(f, 1, &fs, NULL));
        GL_CHECK(glCompileShader(f));
        GL_CHECK(glAttachShader(p, f));
        GL_CHECK(glDeleteShader(v));*/

        shaderAllComplete(p, f, fs);
        printShaderInfoLog(f, ffn);
    }
    if (gs != NULL) {
        /*GL_CHECK(glShaderSource(g, 1, &gs, NULL));
        GL_CHECK(glCompileShader(g));
        GL_CHECK(glAttachShader(p, g));
        GL_CHECK(glDeleteShader(g));*/

        shaderAllComplete(p, g, gs);
        printShaderInfoLog(g, gfn);
    }
//#ifdef GL_TESS_CONTROL_SHADER_EXT
    if (tcs != NULL) {
     /*   GL_CHECK(glShaderSource(tc, 1, &tcs, NULL));
        GL_CHECK(glCompileShader(tc));
        GL_CHECK(glAttachShader(p, tc));
        GL_CHECK(glDeleteShader(tc));*/

        shaderAllComplete(p, tc, tcs);
        printShaderInfoLog(tc, tcfn);
    }
    if (tes != NULL) {
     /*   GL_CHECK(glShaderSource(te, 1, &tes, NULL));
        GL_CHECK(glCompileShader(te));
        GL_CHECK(glAttachShader(p, te));
        GL_CHECK(glDeleteShader(te));*/

        shaderAllComplete(p, te, tes);
        printShaderInfoLog(te, tefn);
    }
//#endif

    if (fs != NULL) {
       /* glLinkProgram(p);
        glUseProgram(p);*/
        linkAndUse(p);
        printProgramInfoLog(p, vfn, ffn, gfn, tcfn, tefn);
    }

    if (vs != NULL) glDetachShaderm(p, v);
    if (fs != NULL) glDetachShaderm(p, f);
    if (gs != NULL) glDetachShaderm(p, g);
    if (tcs != NULL) glDetachShaderm(p, tc);
    if (tes != NULL) glDetachShaderm(p, te);

    return p;
}

GLuint loadShaders(const char* vertFileName, const char* fragFileName) {
    return loadShadersGT(vertFileName, fragFileName, NULL, NULL, NULL);
}

GLuint loadShadersG(const char* vertFileName, const char* fragFileName, const char* geomFileName)
// With geometry shader support
{
    return loadShadersGT(vertFileName, fragFileName, geomFileName, NULL, NULL);
}

GLuint loadShadersGT(const char* vertFileName, const char* fragFileName, const char* geomFileName,
    const char* tcFileName, const char* teFileName)
    // With tesselation shader support
{
    char* vs, * fs, * gs, * tcs, * tes;
    GLuint p = 0;

    vs = readFile((char*)vertFileName);
    fs = readFile((char*)fragFileName);
    gs = readFile((char*)geomFileName);
    tcs = readFile((char*)tcFileName);
    tes = readFile((char*)teFileName);
    if (vs == NULL)
       // LOGE("Failed to read %s from disk.\n", vertFileName);
    if ((fs == NULL) && (fragFileName != NULL))
       // LOGE("Failed to read %s from disk.\n", fragFileName);
    if ((gs == NULL) && (geomFileName != NULL))
       // LOGE("Failed to read %s from disk.\n", geomFileName);
    if ((tcs == NULL) && (tcFileName != NULL))
       // LOGE("Failed to read %s from disk.\n", tcFileName);
    if ((tes == NULL) && (teFileName != NULL))
       // LOGE("Failed to read %s from disk.\n", teFileName);
    if (vs != NULL)
        p = compileShaders(vs, fs, gs, tcs, tes, vertFileName, fragFileName, geomFileName,
            tcFileName, teFileName);
    if (vs != NULL) free(vs);
    if (fs != NULL) free(fs);
    if (gs != NULL) free(gs);
    if (tcs != NULL) free(tcs);
    if (tes != NULL) free(tes);
    return p;
}

GLuint CompileComputeShader(const char* compFileName) {
    GLuint program = glCreateProgramm();
    GLuint computeShader = glCreateShaderm(0x91B9);

    const char* cs = readFile((char*)compFileName);
    if (cs == NULL) {
       // printf("Error reading shader!\n");
    }

    GL_CHECK(glShaderSource(computeShader, 1, &cs, NULL));
    GL_CHECK(glCompileShader(computeShader));

    printShaderInfoLog(computeShader, compFileName);

    GL_CHECK(glAttachShader(program, computeShader));
    GL_CHECK(glDeleteShader(computeShader));
    GL_CHECK(glLinkProgram(program));
    GL_CHECK(glDetachShader(program, computeShader));

    printProgramInfoLog(program, compFileName, NULL, NULL, NULL, NULL);

    return program;
}

// End of Shader loader

void dumpInfo(void) {
   // LOGI("Vendor: %s\n", glGetString(GL_VENDOR));
   // LOGI("Renderer: %s\n", glGetString(GL_RENDERER));
   // LOGI("Version: %s\n", glGetString(GL_VERSION));
   // LOGI("GLSL: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
    //    LOGI("Extensions: %s\n", glGetString(GL_EXTENSIONS));
}

static GLenum lastError = 0;
static char lastErrorFunction[1024] = "";


const char* getGLErrorMsg(GLenum error) {
    switch (error) {
    case 0:
        return "NO_ERROR";
    case 0x0500:
        return "INVALID_ENUM";
    case 0x0501:
        return "INVALID_VALUE";
    case 0x0502:
        return "INVALID_OPERATION";
    case 0x0503:
        return "STACK_OVERFLOW";
    case 0x0504:
        return "STACK_UNDERFLOW";
    case 0x0505:
        return "OUT_OF_MEMORY";
    case 0x0506:
        return "INVALID_FRAMEBUFFER_OPERATION";
    default:
        return "UNKNOWN";
    }
}

/* report GL errors, if any, to stderr */
GLint printError(const char* functionName, const char* file, int line) {
    GLenum error;
    GLint wasError = 0;
    //while ((error = glGetError()) != GL_NO_ERROR) {
    //    if ((lastError != error) || (strcmp(functionName, lastErrorFunction))) {
    //       // LOGE("GL error %s detected in %s, %s:%i\n", getGLErrorMsg(error), functionName, file, line);
    //        strcpy(lastErrorFunction, functionName);
    //        lastError = error;
    //        wasError = 1;
    //    }
    //}
    return wasError;
}


// Keymap mini manager
// Important! Uses glutKeyboardFunc/glutKeyboardUpFunc so you can't use them
// elsewhere or they will conflict.
// (This functionality is built-in in MicroGlut, as "glutKeyIsDown" where this conflict should not exist.)

char keymap[256];
char keydownmap[256];
char keyupmap[256];

char keyIsDown(unsigned char c) {
    return keymap[(unsigned int)c];
}

char keyPressed(unsigned char c) {
    char is_pressed = keydownmap[(unsigned int)c];
    keydownmap[(unsigned int)c] = 0;
    return is_pressed;
}

void keyUp(unsigned char key, int x, int y) {
    keymap[(unsigned int)key] = 0;
    keydownmap[(unsigned int)key] = 0;
    keyupmap[(unsigned int)key] = 1;
}

void keyDown(unsigned char key, int x, int y) {
    keymap[(unsigned int)key] = 1;
    keydownmap[(unsigned int)key] = keyupmap[(unsigned int)key] != 0;
    keyupmap[(unsigned int)key] = 0;
}

void initKeymapManager() {
    int i;
    for (i = 0; i < 256; i++) keymap[i] = 0;
    for (i = 0; i < 256; i++) keydownmap[i] = 0;
    for (i = 0; i < 256; i++) keyupmap[i] = 1;

    //	glutKeyboardFunc(keyDown);
    //	glutKeyboardUpFunc(keyUp);
}


// FBO

//----------------------------------FBO functions-----------------------------------
void CHECK_FRAMEBUFFER_STATUS() {
    GLenum status;
    status = glCheckFramebufferStatus(glFrameBuffer);
    if (status != glFrameBufferComp)
       // LOGE("Framebuffer not complete\n");
}

// create FBO
// FP buffer, suitable for HDR
FBOstruct* initFBO(int width, int height, int int_method) {
    FBOstruct* fbo = (FBOstruct*)malloc(sizeof(FBOstruct));

    if (fbo == NULL) {
        //LOGE("initFBO could not allocate memory for FBO!\n");
        return NULL;
    }

    fbo->width = width;
    fbo->height = height;

    // create objects
    GL_CHECK(glGenFramebuffers(1, &fbo->fb)); // frame buffer id
    GL_CHECK(glBindFramebuffer(glFrameBuffer, fbo->fb));
    GL_CHECK(glGenTextures(1, &fbo->texid));
    //LOGE("%u \n", fbo->texid);
    GL_CHECK(glBindTexture(GL_TEXTURE_2D, fbo->texid));
    GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
    GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
   
    if (int_method == 0) {
        GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
        GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
    }
    else {
        GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
        GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    }
    GL_CHECK(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL));
    GL_CHECK(glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, fbo->texid, 0));

    // Renderbuffer
    // initialize depth renderbuffer
    GL_CHECK(glGenRenderbuffers(1, &fbo->rb));
    GL_CHECK(glBindRenderbuffer(GL_RENDERBUFFER, fbo->rb));
    GL_CHECK(glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT24, fbo->width, fbo->height));
    GL_CHECK(glFramebufferRenderbuffer(glFrameBuffer, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, fbo->rb));
    CHECK_FRAMEBUFFER_STATUS();

    LOGE("Framebuffer object %u\n", fbo->fb);
    GL_CHECK(glBindFramebuffer(glFrameBuffer, 0));
    return fbo;
}

// create FBO, optionally with depth
// Integer buffer, not suitable for HDR!
FBOstruct* initFBO2(int width, int height, int int_method, int create_depthimage) {
    FBOstruct* fbo = (FBOstruct*)malloc(sizeof(FBOstruct));

    if (fbo == NULL) {
       // LOGE("initFBO could not allocate memory for FBO!\n");
        return NULL;
    }

    fbo->width = width;
    fbo->height = height;

    // create objects
    GL_CHECK(glGenRenderbuffers(1, &fbo->rb));
    GL_CHECK(glGenFramebuffers(1, &fbo->fb)); // frame buffer id
    GL_CHECK(glBindFramebuffer(glFrameBuffer, fbo->fb));
    GL_CHECK(glGenTextures(1, &fbo->texid));
    LOGE("%u \n", fbo->texid);
    GL_CHECK(glBindTexture(GL_TEXTURE_2D, fbo->texid));
    GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
    GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
    if (int_method == 0) {
        GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
        GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
    }
    else {
        GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
        GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    }
    GL_CHECK(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL));

    GL_CHECK(glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, fbo->texid, 0));
    if (create_depthimage != 0) {
        GL_CHECK(glGenTextures(1, &fbo->depth));
        GL_CHECK(glBindTexture(GL_TEXTURE_2D, fbo->depth));
        GL_CHECK(glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT16, width, height, 0, GL_DEPTH_COMPONENT,
            GL_UNSIGNED_BYTE, 0L));
        GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
        GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
        GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
        GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
        GL_CHECK(glBindTexture(GL_TEXTURE_2D, 0));
        GL_CHECK(glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, fbo->depth, 0));
        LOGE("depthtexture: %u", fbo->depth);
    }

    // Renderbuffer
    // initialize depth renderbuffer
    GL_CHECK(glBindRenderbuffer(GL_RENDERBUFFER, fbo->rb));
    CHECK_FRAMEBUFFER_STATUS();

    LOGE("Framebuffer object %u\n", fbo->fb);
    GL_CHECK(glBindFramebuffer(GL_FRAMEBUFFER, 0));
    return fbo;
}

static int lastw = 0;
static int lasth = 0;

// Obsolete
void updateScreenSizeForFBOHandler(int w, int h) {
    lastw = w;
    lasth = h;
}

// choose input (textures) and output (FBO)
void useFBO(FBOstruct* out, FBOstruct* in1, FBOstruct* in2) {
    GLint curfbo;

    // This was supposed to catch changes in viewport size and update lastw/lasth.
    // It worked for me in the past, but now it causes problems to I have to
    // fall back to manual updating.
    GL_CHECK(glGetIntegerv(GL_FRAMEBUFFER_BINDING, &curfbo));
    if (curfbo == 0) {
        GLint viewport[4] = { 0, 0, 0, 0 };
        GLint w, h;
        GL_CHECK(glGetIntegerv(GL_VIEWPORT, viewport));
        w = viewport[2] - viewport[0];
        h = viewport[3] - viewport[1];
        if ((w > 0) && (h > 0) && (w < 65536) &&
            (h < 65536)) // I don't believe in 64k pixel wide frame buffers for quite some time
        {
            lastw = viewport[2] - viewport[0];
            lasth = viewport[3] - viewport[1];
        }
    }

    if (out != 0L) {
        GL_CHECK(glViewport(0, 0, out->width, out->height));
    }
    else {
        GL_CHECK(glViewport(0, 0, lastw, lasth));
    }

    if (out != 0L) {
        GL_CHECK(glBindFramebuffer(GL_FRAMEBUFFER, out->fb));
        GL_CHECK(glViewport(0, 0, out->width, out->height));
    }
    else {
        GL_CHECK(glBindFramebuffer(GL_FRAMEBUFFER, 0));
    }
    GL_CHECK(glActiveTexture(GL_TEXTURE1));
    if (in2 != 0L) {
        GL_CHECK(glBindTexture(GL_TEXTURE_2D, in2->texid));
    }
    else {
        GL_CHECK(glBindTexture(GL_TEXTURE_2D, 0));
    }
    GL_CHECK(glActiveTexture(GL_TEXTURE0));
    if (in1 != 0L) {
        GL_CHECK(glBindTexture(GL_TEXTURE_2D, in1->texid));
    }
    else {
        GL_CHECK(glBindTexture(GL_TEXTURE_2D, 0));
    }
}


// ===== Timer =====

//PFNGLGENQUERIESEXTPROC glGenQueriesEXT_2;
//PFNGLDELETEQUERIESEXTPROC glDeleteQueriesEXT_2;
//PFNGLISQUERYEXTPROC glIsQueryEXT_2;
//PFNGLBEGINQUERYEXTPROC glBeginQueryEXT_2;
//PFNGLENDQUERYEXTPROC glEndQueryEXT_2;
//PFNGLQUERYCOUNTEREXTPROC glQueryCounterEXT_2;
//PFNGLGETQUERYIVEXTPROC glGetQueryivEXT_2;
//
//PFNGLGETQUERYOBJECTIVEXTPROC glGetQueryObjectivEXT_2;
//PFNGLGETQUERYOBJECTUIVEXTPROC glGetQueryObjectuivEXT_2;
//PFNGLGETQUERYOBJECTI64VEXTPROC glGetQueryObjecti64vEXT_2;
//PFNGLGETQUERYOBJECTUI64VEXTPROC glGetQueryObjectui64vEXT_2;

void InitTimer() {
    //    glGenQueriesEXT_2 = (PFNGLGENQUERIESEXTPROC) eglGetProcAddress("glGenQueriesEXT");
    //    glDeleteQueriesEXT_2 = (PFNGLDELETEQUERIESEXTPROC) eglGetProcAddress("glDeleteQueriesEXT");
    //    glIsQueryEXT_2 = (PFNGLISQUERYEXTPROC) eglGetProcAddress("glIsQueryEXT");
    //    glBeginQueryEXT_2 = (PFNGLBEGINQUERYEXTPROC) eglGetProcAddress("glBeginQueryEXT");
    //    glEndQueryEXT_2 = (PFNGLENDQUERYEXTPROC) eglGetProcAddress("glEndQueryEXT");
    //    glQueryCounterEXT_2 = (PFNGLQUERYCOUNTEREXTPROC) eglGetProcAddress("glQueryCounterEXT");
    //    glGetQueryivEXT_2 = (PFNGLGETQUERYIVEXTPROC) eglGetProcAddress("glGetQueryivEXT");
    //
    //    glGetQueryObjectivEXT_2 = (PFNGLGETQUERYOBJECTIVEXTPROC) eglGetProcAddress("glGetQueryObjectivEXT");
    //    glGetQueryObjectuivEXT_2 = (PFNGLGETQUERYOBJECTUIVEXTPROC) eglGetProcAddress("glGetQueryObjectuivEXT");
    //    glGetQueryObjecti64vEXT_2 = (PFNGLGETQUERYOBJECTI64VEXTPROC) eglGetProcAddress("glGetQueryObjecti64vEXT");
    //    glGetQueryObjectui64vEXT_2 = (PFNGLGETQUERYOBJECTUI64VEXTPROC) eglGetProcAddress("glGetQueryObjectui64vEXT");
}

//GLTimer::GLTimer() {
//
//
//    glGenQueriesEXT_2(1, &queryID);
//    time = 0;
//}
//
//GLTimer::~GLTimer() {
//    glDeleteQueriesEXT_2(1, &queryID);
//}
//
//void GLTimer::startTimer() {
//    glBeginQueryEXT_2(GL_TIME_ELAPSED_EXT, queryID);
//}
//
//void GLTimer::endTimer() {
//    glEndQueryEXT_2(GL_TIME_ELAPSED_EXT);
//
//    GLint done = 0;
//    while (!done) {
//        glGetQueryObjectivEXT_2(queryID, GL_QUERY_RESULT_AVAILABLE_EXT, &done);
//    }
//    glGetQueryObjectui64vEXT_2(queryID, GL_QUERY_RESULT_EXT, &time);
//}
//
//GLfloat GLTimer::getTime() {
//    return (GLfloat)time / 1000.0f;
//}
//
//GLfloat GLTimer::getTimeMS() {
//    return (GLfloat)time / 1000000.0f;
//}


Timer::Timer() {
    time = 0;
    lapTime = 0;
}

void Timer::startTimer() {
    startTime = myTime::now();
}

void Timer::endTimer() {
    GLfloat tempTime = fsec(myTime::now() - startTime).count();
    lapTime = tempTime - time;
    time = tempTime;
}

GLfloat Timer::getTime() {
    return time;
}

GLfloat Timer::getTimeMS() {
    return time * 1000.0f;
}

GLfloat Timer::getLapTime() {
    return lapTime;
}
