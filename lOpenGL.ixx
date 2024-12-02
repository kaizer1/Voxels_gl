module;

#define GL_GLEXT_PROTOTYPES


#include <windows.h>
#include <Gl/GL.h>
#include <glext.h>
#include <fstream>
#include <iostream>

//import lWinApi;
import lMath;
import lLog;
#pragma comment(lib, "opengl32.lib")


export module lOpenGL;





namespace losGraphics {



#define MAX_SOURCE_SIZE (0x100000)
#define INFOLOG_SIZE 4096
#define GET_INFOLOG_SIZE INFOLOG_SIZE - 1
#define STRINGIFY(s) #s

   // void GLAPI dkfjlksdjf



    

    export using lUnsignedInt = GLuint;
    export using lInt = GLint;
    static constexpr auto VERTEX_OFFSET = 0;
    export void loadASTC(const char* nameTexture, GLuint* texID);
    export void LoadingStaticNormalsExist(GLuint& losM, const char* nameLoadModel, bool vaoExist);
    export using uint16 = unsigned short;// uint16;
    export void linkAndValidateProgram(unsigned int& enterProgram);

    export void setTextureDataForFrameBuffer(unsigned int& mTexture, unsigned int enumTextureType, int level, int format, int width, int height, int border, unsigned int type_byte, void* pixelWrapper);
    export void setRenderBuffer(unsigned int& renderVBO, int width, int height);
    export bool checkFrameBufferLos();
    export void enableMultiSample();
    export void enableDepth();
    export void diSableDepth();
    export void setTextureDataForFrameBufferNormal(unsigned int& mTexture, unsigned int enumTextureType, int level, int format, int width, int height, int border, unsigned int type_byte, void* pixelWrapper);
    export unsigned int loadShaderFromFilesAndReturnShader(unsigned int shaderType, const char* asstsShader);
    export void glRemoveRenderBuffer(unsigned int& removeRenderBuffer);
    export GLuint loadShaderLos(GLenum enu, const char* shaderSource);


    export template <typename T>
        auto callingM(const char* namesCall, T t) -> auto {
        //losWin::LosOutputStringConvert(namesCall, t);
    }







    void* GetAnyGLFuncAddress(const char* name)
    {
        void* p = (void*)wglGetProcAddress(name);
        if (p == 0 ||
            (p == (void*)0x1) || (p == (void*)0x2) || (p == (void*)0x3) ||
            (p == (void*)-1))
        {
            HMODULE module = LoadLibraryA("opengl32.dll");
            p = (void*)GetProcAddress(module, name);
        }

        return p;
    }



#define GL_INVALID_ENUM                   0x0500
#define GL_INVALID_VALUE                  0x0501
#define GL_INVALID_OPERATION              0x0502
#define GL_STACK_OVERFLOW                 0x0503
#define GL_STACK_UNDERFLOW                0x0504
#define GL_OUT_OF_MEMORY                  0x0505



    export void checkErrorLos(int numberError) {

        auto storeError = glGetError();

        if (storeError != GL_NO_ERROR) {



            if (storeError == GL_INVALID_ENUM) {
                lLogs::logPrintWindowsClear("ERROR: invalied enum !", numberError);

            }
            else if (storeError == GL_INVALID_VALUE) {
                lLogs::logPrintWindowsClear("ERROR: invalid value  !", numberError);

            }
            else if (storeError == GL_STACK_OVERFLOW) {
                lLogs::logPrintWindowsClear("ERROR: stack overflow ", numberError);

            }
            else if (storeError == GL_STACK_UNDERFLOW) {
                lLogs::logPrintWindowsClear("ERROR: stack underflow  !", numberError);

            }
            else if (storeError == GL_OUT_OF_MEMORY) {
                lLogs::logPrintWindowsClear("ERROR: out of memory !", numberError);

            }
            else if (storeError == GL_INVALID_OPERATION) {
                lLogs::logPrintWindowsClear("ERROR: invalid operation ! ", numberError);

            }


        }
        else {
            //lLogs::logPrintWindowsClear("no GLERRROR", numberError);
        }

    }


    export void loadShaderFromFiles(unsigned int& programGL, unsigned int shaderType, const char* asstsShader);



   

    //typedef void (* MYGLEXTFP_GLGENERATEMIPMAPS)(GLenum);
    //typedef  myglextGenerateMipmaps(WINAPI* MYGLEXTFP_GLGENERATEMIPMAP) (GLenum);
    //#define glGenerateMipmaps myglextGenerateMipmaps;

   

    /* typedef BOOL(WINAPI* PFNWGLCHOOSEPIXELFORMATARBPROC) (HDC hdc, const int* piAttribIList, const FLOAT* pfAttribFList, UINT nMaxFormats,
         int* piFormats, UINT* nNumFormats);

     typedef HGLRC(WINAPI* PFNWGLCREATECONTEXTATTRIBSARBPROC) (HDC hDC, HGLRC hShareContext, const int* attribList);
     typedef BOOL(WINAPI* PFNWGLSWAPINTERVALEXTPROC) (int interval);*/

     /*  export PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB;
       export PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB;*/
    export PFNGLUSEPROGRAMPROC glUseProgram;
    //export void glUseProgram;
    export PFNGLCREATEPROGRAMPROC glCreateProgram;
    //export void glCreateProgram;
    export PFNGLCREATESHADERPROC glCreateShader;

    export PFNGLSHADERSOURCEPROC  glShaderSource;
    export PFNGLCOMPILESHADERPROC  glCompileShader;
    export PFNGLDELETESHADERPROC glDeleteShader;
    export PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
    export PFNGLGETSHADERIVPROC glGetShaderiv;
    export PFNGLATTACHSHADERPROC glAttachShader;
    export PFNGLLINKPROGRAMPROC glLinkProgram;
    export PFNGLVALIDATEPROGRAMPROC glValidateProgram;
    export PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation;
    export PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
    export PFNGLBUFFERDATAPROC glBufferData;
    export PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
    export PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
    export PFNGLBINDBUFFERPROC glBindBuffer;
    export PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
    //export void glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices);
    //PFNGLDRAWELEMENTSPROC glDrawElements;
    export PFNGLGENBUFFERSPROC glGenBuffers;
    export PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
    //export PFNGLDRAWARRAYSPROC glDrawArrays;
    export PFNGLACTIVETEXTUREPROC glActiveTexture;
    export PFNGLUNIFORM1IPROC glUniform1i;
    export PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
    export PFNGLDELETEPROGRAMPROC glDeleteProgram;
    export PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;
    export PFNGLUNIFORM4FPROC glUniform4f;
    PFNGLUNIFORM4FVPROC glUniform4fv;
    PFNGLUNIFORM3FVPROC glUniform3fv;
    PFNGLUNIFORM2FPROC  glUniform2f;  //  (GLint location, GLfloat v0, GLfloat v1);
    export PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D;
    PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers;
    PFNGLBINDFRAMEBUFFEREXTPROC glBindFramebufferEXT;
    PFNGLDELETEFRAMEBUFFERSEXTPROC glDeleteFrameBuffer;
    PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D;
    PFNGLGENRENDERBUFFERSPROC glGenRenderBuffers;
    export PFNGLBINDRENDERBUFFERPROC glBindRenderBuffer;
    PFNGLRENDERBUFFERSTORAGEPROC glRenderBufferStorage;
    PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glRenderBufferStorageMultisample;
    PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFrameBufferStatusLos;
    PFNGLTEXIMAGE2DMULTISAMPLEPROC glTexImage2DMultisample;
    PFNGLBINDFRAMEBUFFEREXTPROC  glBindFramebuffer;
    PFNGLBLITFRAMEBUFFERPROC glBlitFramebuffer;
    PFNGLGETPROGRAMIVARBPROC glGetProgramiv;
    PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;
    PFNGLDELETEBUFFERSPROC  glDeleteBuffers;
    PFNGLUNIFORM3FPROC  glUniform3f;
    PFNGLDRAWELEMENTSINDIRECTPROC glDrawElementsIndirect;
    PFNGLBINDBUFFERBASEPROC glBindBufferBase;
    PFNGLVERTEXATTRIBIPOINTERPROC glVertexAttribIPointer;
    PFNGLBUFFERSUBDATAPROC glBufferSubData;
    PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisor;        
    PFNGLDETACHSHADERPROC  glDetachShader;
    PFNGLGENERATEMIPMAPEXTPROC glGenerateMipmap;
    //MYGLEXTFP_GLGENERATEMIPMAP myglextGenerateMipmaps;
    

    //PFNGLGENERATEMIPMAP glGenerateMipmap;

    export using losuin64 = GLuint64;

    export void callClear(float r, float g, float b, float a) {
        //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(r, g, b, 1.0F);
    }
    export void callClearPure() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    export void CallingLoadingExtension() {

        //losWin::LosOutputStringConvert(" we  openGL  ", 4);
        glCreateProgram = (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
        glUseProgram = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
        glCreateShader = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
        glShaderSource = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
        glCompileShader = (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
        glDeleteShader = (PFNGLDELETESHADERPROC)wglGetProcAddress("glDeleteShader");
        glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");
        glGetShaderiv = (PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");
        glAttachShader = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
        glLinkProgram = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
        glValidateProgram = (PFNGLVALIDATEPROGRAMPROC)wglGetProcAddress("glValidateProgram");
        glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)wglGetProcAddress("glBindAttribLocation");
        glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)wglGetProcAddress("glGetUniformLocation");
        glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
        glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");
        glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glEnableVertexAttribArray");
        glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
        glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)wglGetProcAddress("glBindVertexArray");
        glGenBuffers = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
        glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)wglGetProcAddress("glGenVertexArrays");
        glActiveTexture = (PFNGLACTIVETEXTUREPROC)wglGetProcAddress("glActiveTexture");
        glUniform1i = (PFNGLUNIFORM1IPROC)wglGetProcAddress("glUniform1i");
        glUniform2f = (PFNGLUNIFORM2FPROC)wglGetProcAddress("glUniform2f");
        //    PFNGLUNIFORM2FPROC  glUniform2fv;  //  (GLint location, GLfloat v0, GLfloat v1);
        glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)wglGetProcAddress("glUniformMatrix4fv");
        glDeleteProgram = (PFNGLDELETEPROGRAMPROC)wglGetProcAddress("glDeleteProgram");
        glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)wglGetProcAddress("glDeleteVertexArrays");
        glCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)wglGetProcAddress("glCompressedTexImage2D");
        glUniform4f = (PFNGLUNIFORM4FPROC)wglGetProcAddress("glUniform4f");
        glUniform4fv = (PFNGLUNIFORM4FVPROC)wglGetProcAddress("glUniform4fv");
        glUniform3fv = (PFNGLUNIFORM3FVPROC)wglGetProcAddress("glUniform3fv");
        glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)wglGetProcAddress("glGenFramebuffers");
        glBindFramebufferEXT = (PFNGLBINDFRAMEBUFFEREXTPROC)wglGetProcAddress("glBindFramebufferEXT");
        glDeleteFrameBuffer = (PFNGLDELETEFRAMEBUFFERSEXTPROC)wglGetProcAddress("glDeleteFramebuffersEXT");
        glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)wglGetProcAddress("glFramebufferTexture2D");

        glGenRenderBuffers = (PFNGLGENRENDERBUFFERSPROC)wglGetProcAddress("glGenRenderbuffers");
        glBindRenderBuffer = (PFNGLBINDRENDERBUFFERPROC)wglGetProcAddress("glBindRenderbuffer");
        glRenderBufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC)wglGetProcAddress("glRenderbufferStorage");
        glCheckFrameBufferStatusLos = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)wglGetProcAddress("glCheckFramebufferStatus");
        glTexImage2DMultisample = (PFNGLTEXIMAGE2DMULTISAMPLEPROC)wglGetProcAddress("glTexImage2DMultisample");
        glRenderBufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)wglGetProcAddress("glRenderbufferStorageMultisample");

        glBindFramebuffer = (PFNGLBINDFRAMEBUFFEREXTPROC)wglGetProcAddress("glBindFramebufferEXT");
        glBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC)wglGetProcAddress("glBlitFramebuffer");


        glGetProgramiv = (PFNGLGETPROGRAMIVARBPROC)wglGetProcAddress("glGetProgramiv");
        glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)wglGetProcAddress("glGetProgramInfoLog");
        glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)wglGetProcAddress("glDeleteBuffers");
        glUniform3f = (PFNGLUNIFORM3FPROC)wglGetProcAddress("glUniform3f");
        glDrawElementsIndirect = (PFNGLDRAWELEMENTSINDIRECTPROC)wglGetProcAddress("glDrawElementsIndirect");
        glBindBufferBase = (PFNGLBINDBUFFERBASEPROC)wglGetProcAddress("glBindBufferBase"); // glBindBufferBase;
        glVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTERPROC)wglGetProcAddress("glVertexAttribIPointer");
        glBufferSubData = (PFNGLBUFFERSUBDATAPROC)wglGetProcAddress("glBufferSubData");
        glVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISORPROC)wglGetProcAddress("glVertexAttribDivisor");
        glDetachShader = (PFNGLDETACHSHADERPROC)wglGetProcAddress("glDetachShader");
        glGenerateMipmap = (PFNGLGENERATEMIPMAPEXTPROC)wglGetProcAddress("glGenerateMipmap");
        // myglextGenerateMipmaps = (MYGLEXTFP_GLGENERATEMIPMAP)wglGetProcAddress("glGenerateMipmaps");

    }


    export inline void linkAndUse(GLuint p) {
        glLinkProgram(p);
        glUseProgram(p);
    }
   

    export inline void  shaderAllComplete(GLuint p, GLuint v,  const char* vs) {

        glShaderSource(v, 1, &vs, NULL);
        glCompileShader(v);
        glAttachShader(p, v);
        glDeleteShader(v);

     //   return true;
   }

    
    export inline void loadTexturetoData(int type, size_t width, size_t height, 
        void* textureData) {

        // GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels
        glTexImage2D(GL_TEXTURE_2D, 0, type, width, height, 0, type,
            GL_UNSIGNED_BYTE, textureData);

        // Mipmaps
        glGenerateMipmap(GL_TEXTURE_2D); // ??? 
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    }



   

    GLuint loadShaderLos(GLenum enu, const char* shaderSource)
    {
        GLuint shaderL;
        GLint compiled;

        shaderL = glCreateShader(enu);

        if (shaderL != 0)
        {
            checkErrorLos(101);
            glShaderSource(shaderL, 1, &shaderSource, NULL);

            glCompileShader(shaderL);
            compiled = 0;
            glGetShaderiv(shaderL, GL_COMPILE_STATUS, &compiled);
            if (compiled != GL_TRUE)
            {

                //LosOutputStringConvert("sdf");
                GLint infoLen = 0;
                glGetShaderiv(shaderL, GL_INFO_LOG_LENGTH, &infoLen);
                if (infoLen > 0)
                {

                    char* logBuffer = (char*)malloc(infoLen);
                    if (logBuffer != NULL)
                    {
                        glGetShaderInfoLog(shaderL, infoLen, NULL, logBuffer);
                        // LosOutputStringConvert(" error my this ", 4);
                        free(logBuffer);
                        logBuffer = NULL;
                    }
                    glDeleteShader(shaderL);
                    shaderL = 0;
                }
            }
            //LosOutputStringConvert("final loading ", 2);
        }
        return shaderL;
    }


    //static char* readShaderSource(std::string_view shaderFile)
    //{
       // FILE* fp = std::fopen(shaderFile.data(), "rb");

        //if (fp == NULL) {
            //LosOutputStringConvert(" null my shaders ");
          //  return NULL;
        //}

        //std::SEEK_ENS 

       //std:: fseek(fp, 0L, SEEK_END);
       // long size = std::ftell(fp);

       // long size = 1024;
        // std::fseek(fp, 0L, SEEK_SET);
        //char* buf = new char[size + 1];
        // fread(buf, 1, size, fp);

        // buf[size] = '\0';
        //std::fclose(fp);


     //   return buf;
    //}

    unsigned int loadShaderFromFilesAndReturnShader(unsigned int shaderType, const char* asstsShader)
    {
        GLuint shaderback;
        std::string baseAssets = "assets/Shaders/";
        baseAssets += asstsShader;

        std::ifstream f(baseAssets);

        std::string str((std::istreambuf_iterator<char>(f)),
            std::istreambuf_iterator<char>());


        GLchar infolog[INFOLOG_SIZE];

        shaderback = glCreateShader(shaderType);
        //std::string str = text;
        //str = additional_str + str;
        const char* c = str.c_str();
        glShaderSource(shaderback, 1, &c, 0);
        glCompileShader(shaderback);

        GLint success;
        glGetShaderiv(shaderback, GL_COMPILE_STATUS, &success);

        if (!success)
        {
            //losWin::LosOutputStringConvert("Not success shader build ");
            glGetShaderInfoLog(shaderback, GET_INFOLOG_SIZE, 0, infolog);
            //losWin::LosOutputStringConvert(infolog);

        }
        else
        {
            //glAttachShader(programGL, shaderback);
            //glDeleteShader(id);
            //losWin::LosOutputStringConvert("Success load and attach shares ! ");
        }


        return shaderback;
    }

    /*  GLuint loadShaderLos(GLenum enu, const char* shaderSource)
      {
          GLuint shaderL;
          GLint compiled;

          shaderL = glCreateShader(enu);

          if (shaderL != 0)
          {
              glShaderSource(shaderL, 1, &shaderSource, NULL);

              glCompileShader(shaderL);
              compiled = 0;
              glGetShaderiv(shaderL, GL_COMPILE_STATUS, &compiled);
              if (compiled != GL_TRUE)
              {

                  std::cout << " shader error ! " << " \n";
                  GLint infoLen = 0;
                  glGetShaderiv(shaderL, GL_INFO_LOG_LENGTH, &infoLen);
                  if (infoLen > 0)
                  {

                      char* logBuffer = (char*)malloc(infoLen);
                      if (logBuffer != NULL)
                      {
                          glGetShaderInfoLog(shaderL, infoLen, NULL, logBuffer);
                          std::cout << " error my this " << " \n";
                          free(logBuffer);
                          logBuffer = NULL;
                      }
                      glDeleteShader(shaderL);
                      shaderL = 0;
                  }
              }
              std::cout << "final loading " << " \n";
          }
          return shaderL;
      }*/



    void loadShaderFromFiles(unsigned int& programGL, unsigned int shaderType, const char* asstsShader) {

        std::string baseAssets = "assets/Shaders/";
        baseAssets += asstsShader;

        std::ifstream f(baseAssets);

        std::string str((std::istreambuf_iterator<char>(f)),
            std::istreambuf_iterator<char>());



        GLchar infolog[INFOLOG_SIZE];

        if (shaderType == GL_VERTEX_SHADER) {
            std::cout << " this vertex shader " << " \n";
        }
        else {
            std::cout << " this fragment shader " << " \n";
        }

        GLuint id = glCreateShader(shaderType);
        //std::string str = text;
        //str = additional_str + str;
        const char* c = str.c_str();
        std::cout << " \n " << c << " \n";
        glShaderSource(id, 1, &c, 0);
        glCompileShader(id);

        GLint success;
        glGetShaderiv(id, GL_COMPILE_STATUS, &success);

        if (!success)
        {
            glGetShaderInfoLog(id, GET_INFOLOG_SIZE, 0, infolog);
            //losWin::LosOutputStringConvert(infolog);

        }
        else
        {
            glAttachShader(programGL, id);
            glDeleteShader(id);
            //losWin::LosOutputStringConvert("Success load and attach shares ! ");
        }

    }



    export class ETCHeader
    {
    private:
        unsigned char paddenWidthMSB;
        unsigned char paddenWidthLSB;
        unsigned char paddenHeightMSB;
        unsigned char paddenHeightLSB;
        unsigned char widthMSB;
        unsigned char widthLSB;
        unsigned char heightMSB;
        unsigned char heightLSB;

    public:
        ETCHeader() {}


        ETCHeader(unsigned char* data) {
            paddenWidthMSB = data[8];
            paddenWidthLSB = data[9];
            paddenHeightMSB = data[10];
            paddenHeightLSB = data[11];
            widthMSB = data[12];
            widthLSB = data[13];
            heightMSB = data[14];
            heightLSB = data[15];
        }

        unsigned short getWidth(void)
        {
            return (widthMSB << 8) | widthLSB;
        }


        unsigned short getHeight(void)
        {
            return (heightMSB << 8) | heightLSB;
        }


        unsigned short getPaddedWidth(void)
        {
            return (paddenWidthMSB << 8) | paddenWidthLSB;
        }

        unsigned short getPaddedHeight(void)
        {
            return (paddenHeightMSB << 8) | paddenHeightLSB;
        }

        //      GLsizei getSize();
        GLsizei getSize()
        {
            /* if (internalFormat != GL_COMPRESSED_RG11_EAC && internalFormat != GL_COMPRESSED_SIGNED_RG11_EAC &&
                 internalFormat != GL_COMPRESSED_RGBA8_ETC2_EAC && internalFormat != GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC)
             {
                 return (getPaddedWidth() * getPaddedHeight()) >> 1;
             }*/
             // else
              //{
            return (getPaddedWidth() * getPaddedHeight());
            //}
        }
    };


    export typedef struct
    {
        unsigned char  magic[4];
        unsigned char  blockdim_x;
        unsigned char  blockdim_y;
        unsigned char  blockdim_z;
        unsigned char  xsize[3];   /* x-size = xsize[0] + xsize[1] + xsize[2] */
        unsigned char  ysize[3];   /* x-size, y-size and z-size are given in texels */
        unsigned char  zsize[3];   /* block count is inferred */
    } astc_header;




    export void FontTextureLoad(unsigned int* texID, size_t& width, size_t& height, char* tex_data) {

        glGenTextures(1, texID); // was texid
        glBindTexture(GL_TEXTURE_2D, *texID);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // GL_CLAMP
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // was font
        // was LosFontBigs .tex_width, LosFontBigs.tex_height
        glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, width, height,
            0, GL_ALPHA, GL_UNSIGNED_BYTE, tex_data);
        glBindTexture(GL_TEXTURE_2D, *texID);

        // glClearColor( 1, 1, 1, 1 );
        // glEnable( GL_BLEND );
        // glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
        glEnable(GL_TEXTURE_2D);
    }

    void loadASTC(const char* nameTexture, GLuint* texID) {


        std::string baseAssets = "assets/textures/";
        baseAssets += nameTexture;

        //losWin::LosOutputStringConvert(baseAssets.c_str(), 8);


        //std::fstream my_file{};
        //my_file.open("my_file", std::ios::out);
        // std::fstream dis(" ", std::ifstream::in);



        std::ifstream is(baseAssets.c_str(), std::ios::binary);

        is.seekg(0, is.end);
        int length = is.tellg();
        is.seekg(0, is.beg);

        //losWin::LosOutputStringConvert("my lenght assets texture = ", length);
        char* buffers = new char[length + 1];

        is.read(buffers, length);

        is.close();


        unsigned int n_bytes_to_read = 0;
        int xblocks = 0;
        int yblocks = 0;
        int zblocks = 0;

        /* Number of bytes for each dimension. */
        int xsize = 0;
        int ysize = 0;
        int zsize = 0;

        //auto length = 1024;
        //char* buffers = new char[length + 1];
        astc_header* astc_data_ptr = (astc_header*)buffers;

        xsize = astc_data_ptr->xsize[0] + (astc_data_ptr->xsize[1] << 8) + (astc_data_ptr->xsize[2] << 16);
        ysize = astc_data_ptr->ysize[0] + (astc_data_ptr->ysize[1] << 8) + (astc_data_ptr->ysize[2] << 16);
        zsize = astc_data_ptr->zsize[0] + (astc_data_ptr->zsize[1] << 8) + (astc_data_ptr->zsize[2] << 16);

        xblocks = (xsize + astc_data_ptr->blockdim_x - 1) / astc_data_ptr->blockdim_x;
        yblocks = (ysize + astc_data_ptr->blockdim_y - 1) / astc_data_ptr->blockdim_y;
        zblocks = (zsize + astc_data_ptr->blockdim_z - 1) / astc_data_ptr->blockdim_z;

        n_bytes_to_read = xblocks * yblocks * zblocks << 4;

        (glGenTextures(1, texID));
        (glBindTexture(GL_TEXTURE_2D, *texID));

        GLenum compressed_data_internal_format;
        compressed_data_internal_format = GL_COMPRESSED_RGBA_ASTC_10x8_KHR;

        /*  switch (astcs)
          {
          case  tenForsixe:
              compressed_data_internal_format = GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR;
              break;

          case tenForEight:
              compressed_data_internal_format = GL_COMPRESSED_RGBA_ASTC_10x8_KHR;
              break;

          case tenForTen:
              compressed_data_internal_format = GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR;
              break;

          case   tenForTenNotAlpha:
              compressed_data_internal_format = GL_COMPRESSED_RGBA_ASTC_10x10_KHR;
              break;


          default:
              compressed_data_internal_format = GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR;
              break;
          }*/


          // GLenum compressed_data_internal_format = GL_COMPRESSED_RGBA_ASTC_10x8_KHR;
           /* Upload texture data to ES. */

        (glCompressedTexImage2D(GL_TEXTURE_2D,
            0,
            compressed_data_internal_format,
            xsize,
            ysize,
            0,
            n_bytes_to_read,
            (const GLvoid*)&astc_data_ptr[1]));

        (glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
        (glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
        (glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
        (glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));


        (glBindTexture(GL_TEXTURE_2D, 0));

    }



    export void loadSimpleFrameBuffer(unsigned int& texID) {

        glGenTextures(1,  &texID);
        glBindTexture(GL_TEXTURE_2D, texID);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }


    void setTextureDataForFrameBufferNormal(unsigned int& mTexture, unsigned int enumTextureType, int level, int format, int width, int height, int border, unsigned int type_byte, void* pixelWrapper) {

        glGenTextures(1, &mTexture);
        glBindTexture(enumTextureType, mTexture); // GL_TEXTURE_2D, GL_TEXTURE_3D etc



        glTexImage2D(enumTextureType, level, format, width, height, 0, format, GL_UNSIGNED_BYTE, pixelWrapper);
        checkErrorLos(61);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBindTexture(enumTextureType, 0);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, enumTextureType, mTexture, 0);

    }


    void setTextureDataForFrameBuffer(unsigned int& mTexture, unsigned int enumTextureType, int level, int format, int width, int height, int border, unsigned int type_byte, void* pixelWrapper) {




        glGenTextures(1, &mTexture);
        glBindTexture(enumTextureType, mTexture); // GL_TEXTURE_2D, GL_TEXTURE_3D etc

        checkErrorLos(11);
        //glTexImage2D(enumTextureType, level, format, width, height, 0, format, type_byte, pixelWrapper);



    //    (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);

        glTexImage2DMultisample(enumTextureType, 4, format, width, height, GL_TRUE);
        checkErrorLos(12);
        //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glBindTexture(enumTextureType, 0);

        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, enumTextureType, mTexture, 0);

    }


    void glRemoveRenderBuffer(unsigned int& removeRenderBuffer) {
        PFNGLDELETERENDERBUFFERSPROC deleteRenderBuffer;
        deleteRenderBuffer = (PFNGLDELETERENDERBUFFERSPROC)wglGetProcAddress("glDeleteRenderbuffers");
        deleteRenderBuffer(1, &removeRenderBuffer);
    }

    void setRenderBuffer(unsigned int& renderVBO, int width, int height) {


        PFNGLGENRENDERBUFFERSPROC sdfsdf;
        sdfsdf = (PFNGLGENRENDERBUFFERSPROC)wglGetProcAddress("glGenRenderbuffers");


        PFNGLBINDRENDERBUFFERPROC wefsdf;
        wefsdf = (PFNGLBINDRENDERBUFFERPROC)wglGetProcAddress("glBindRenderbuffer");

        PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer;
        glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)wglGetProcAddress("glFramebufferRenderbuffer");

        sdfsdf(1, &renderVBO);
        wefsdf(GL_RENDERBUFFER, renderVBO);
        //glRenderBufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, 1280, 720);

                                                      //          glRenderbufferStorageMultisample
    //(PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)wglGetProcAddress("glRenderbufferStorageMultisample");
        glRenderBufferStorageMultisample(GL_RENDERBUFFER, 4, GL_DEPTH24_STENCIL8, width, height);

        wefsdf(GL_RENDERBUFFER, 0);

        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, renderVBO);


    }

    bool checkFrameBufferLos() {
        if (glCheckFrameBufferStatusLos(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
            return false;
        }

        return true;
    }



    void  enableDepth() {
        glEnable(GL_DEPTH_TEST);
    }
    void  diSableDepth() {
        glDisable(GL_DEPTH_TEST);
    }
    void enableMultiSample() {
        glEnable(GL_MULTISAMPLE);
    }



    void linkAndValidateProgram(unsigned int& enterProgram) {

        checkErrorLos(49);

        glLinkProgram(enterProgram);


        GLint linkStatus = GL_FALSE;
        //losWin::LosOutputStringConvert(" setAxis 05 \n");

        glGetProgramiv(enterProgram, GL_LINK_STATUS, &linkStatus);
        if (linkStatus != GL_TRUE)
        {
            //losWin::LosOutputStringConvert("Not secsues  build program \n");
            GLint bufLength = 0;
            glGetProgramiv(enterProgram, GL_INFO_LOG_LENGTH, &bufLength);
            if (bufLength > 0)
            {
                char* logBuffer = (char*)malloc(bufLength);

                if (logBuffer != NULL)
                {
                    glGetProgramInfoLog(enterProgram, bufLength, NULL, logBuffer);
                    //losWin::LosOutputStringConvert(" Count not link program setAxis: ");
                    lLogs::logPrintWindowsClearFloat(logBuffer, 0);
                    std::cout << "ksdjhfksjadhfkjsdhf" << " \n";
                    free(logBuffer);
                    logBuffer = NULL;
                }
            }
            //losWin::LosOutputStringConvert(" not compile Programs etAxis \n");
            glDeleteProgram(enterProgram);
        }



        checkErrorLos(50);
        glValidateProgram(enterProgram);
        checkErrorLos(51);
    }



    void LoadingStaticNormalsExist(GLuint& losM, const char* nameLoadModel, bool vaoExist) {

        //losWin::LosOutputStringConvert(" in Hammer model loading ");
        //AAssetManager* loadAssets = backAssetMan(); // w "TestArray2.bin",  TestStone2 planeDes  stone3 UpTower
        //AAsset* StrawberyAssets = AAssetManager_open(loadAssets, nameLoadModel, AASSET_MODE_BUFFER); // AASSET_MODE_STREAMING
        std::string baseAssets = "assets/Model/";
        baseAssets += nameLoadModel;



        std::ifstream is(baseAssets.c_str(), std::ios::binary);

        is.seekg(0, is.end);
        int length = is.tellg();
        is.seekg(0, is.beg);

        //losWin::LosOutputStringConvert("my lenght assets model = ", length);
        //char* buffers = new char[length + 1];





        //unsigned int losJokVertex;
        //is.read(reinterpret_cast<char*>(&losJokVertex), sizeof(uint32_t));
        //AAsset_read(StrawberyAssets, reinterpret_cast<char*>(&losJokVertex), sizeof(uint32_t));
        //unsigned int losIndexesAssets;

        //AAsset_read(StrawberyAssets, reinterpret_cast<char*>(&losIndexesAssets), sizeof(uint32_t));
        //is.read(reinterpret_cast<char*>(&losIndexesAssets), sizeof(uint32_t));
        //unsigned int uvCountAssets;
        //AAsset_read(StrawberyAssets, reinterpret_cast<char*>(&uvCountAssets), sizeof(uint32_t));
        //is.read(reinterpret_cast<char*>(&uvCountAssets), sizeof(uint32_t));
        //losWin::LosOutputStringConvert(" my uvCount = ", uvCountAssets);

        //unsigned int normCountAssets;
        //AAsset_read(StrawberyAssets, reinterpret_cast<char*>(&normCountAssets), sizeof(unsigned int));
        //is.read(reinterpret_cast<char*>(&normCountAssets), sizeof(unsigned int));
        //logRun(" losIndexesAssets == %d \n", losIndexesAssets); //
        //losM.drawIndexs = losIndexesAssets;


        //unsigned short bIndexAssets[losIndexesAssets];


        //uint16 aStraw[losJokVertex];
        //int aReadOkStraw = AAsset_read(StrawberyAssets, reinterpret_cast<char*>(&aStraw), losJokVertex * sizeof(uint16));
        //CheckRead(aReadOkStraw, 1);


        //aReadOkStraw = AAsset_read(StrawberyAssets, reinterpret_cast<char*>(&bIndexAssets), losIndexesAssets * sizeof(unsigned short));
        //CheckRead(aReadOkStraw, 13);
        //logRun( "my index == %d, %d \n", bIndexAssets[7], bIndexAssets[163]);
        //uint16 bUVAssets[uvCountAssets];
        //aReadOkStraw = AAsset_read(StrawberyAssets, reinterpret_cast<char*>(&bUVAssets), uvCountAssets * sizeof(uint16));
        //CheckRead(aReadOkStraw, 23);
        // normCount
        //uint16 bNPillar[normCountAssets];
        // logRun("normCount == %d \n", normCountAssets);
        //aReadOkStraw = AAsset_read(StrawberyAssets, reinterpret_cast<char*>(&bNPillar), normCountAssets * sizeof(uint16));
       // CheckRead(aReadOkStraw, 33);
       // AAsset_close(StrawberyAssets);

        //losWin::LosOutputStringConvert(" in ArcaMila final");


        is.close();
        // if (!vaoExist)
          //   glGenVertexArrays(1, &losM.vao);


         //auto KolNio = strcmp(nameLoadModel, "PollExcelent.bin");  // PollExcelent.bin

         //if (KolNio == 0) {
         //    const auto numbC = losJokVertex / 3;

         //    auto minX = 0.0f, maxX = 0.0f, minY = 0.0f, maxY = 0.0f, minZ = 0.0f, maxZ = 0.0f;

         //    //HalfToFloat
         //    for (int i = 0; i < numbC; i += 3) {
         //        auto x = HalfToFloat(aStraw[i]);
         //        auto y = HalfToFloat(aStraw[i + 1]);
         //        auto z = HalfToFloat(aStraw[i + 2]);

         //        if (x > maxX)
         //            maxX = x;

         //        if (x < minX)
         //            minX = x;


         //        if (y > maxY)
         //            maxY = y;

         //        if (y < minY)
         //            minY = y;

         //        if (z > maxZ)
         //            maxZ = z;

         //        if (z < minZ)
         //            minZ = z;

         //    }

         //    //logRun(" My  minMax : PollExcelent \n");
         //    //logRun(" Min max  X : %f, %f \n", minX, maxX);
         //    //logRun(" Min max  Y : %f, %f \n", minY, maxY);
         //    //logRun(" Min max  Z : %f, %f \n", minZ, maxZ);
         //    //
         //    //// Moneta
         //    //// Min max  X : -0.067444, 0.067444
         //    //// Min max  Y : 0.000000, 0.164429
         //    //// Min max  Z : -0.015564, 0.000061
         //}


        // logRun(" in ArcaMila 12");
        // glBindVertexArray(losM.vao);

        // GLuint bufferf1, bufferf2, bufferf3, buUnirr4;
        // glGenBuffers(1, &bufferf1);
        // glGenBuffers(1, &bufferf2);
        // glGenBuffers(1, &bufferf3);
        // glGenBuffers(1, &buUnirr4);


        // glBindBuffer(GL_ARRAY_BUFFER, bufferf1);
        // {
        //     glBufferData(GL_ARRAY_BUFFER, losJokVertex * sizeof(uint16), aStraw, GL_STATIC_DRAW);
        //     glVertexAttribPointer(0, 3, GL_HALF_FLOAT, GL_FALSE, 0, (const void*)VERTEX_OFFSET);
        //     glEnableVertexAttribArray(0);
        // }
        // logRun(" in ArcaMila 13");
        // glBindBuffer(GL_ARRAY_BUFFER, bufferf2);
        // {
        //     glBufferData(GL_ARRAY_BUFFER, uvCountAssets * sizeof(uint16), bUVAssets, GL_STATIC_DRAW);
        //     glVertexAttribPointer(1, 2, GL_HALF_FLOAT, GL_FALSE, 0, (const void*)VERTEX_OFFSET);
        //     glEnableVertexAttribArray(1);
        // }
        // logRun(" in ArcaMila 14");
        // glBindBuffer(GL_ARRAY_BUFFER, bufferf3);
        // {
        //     glBufferData(GL_ARRAY_BUFFER, normCountAssets * sizeof(uint16), bNPillar, GL_STATIC_DRAW);
        //     glVertexAttribPointer(2, 3, GL_HALF_FLOAT, GL_FALSE, 0, (const void*)VERTEX_OFFSET);
        //     glEnableVertexAttribArray(2);
        // }

        // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buUnirr4);

        // // BIGS ERROR !!!
        // // RY glBufferData (GLenum target, GLsizeiptr size, const void *data, GLenum usage)
        //// GLsizei size = losIndexesAssets * sizeof(GL_UNSIGNED_SHORT);  // was losIndexesAssets * sizeof(GL_UNSIGNED_SHORT)
        // logRun(" Big ERROOR's !!!  ");

        // glBufferData(GL_ELEMENT_ARRAY_BUFFER, losIndexesAssets * sizeof(unsigned  short), bIndexAssets, GL_STATIC_DRAW);

        // glBindVertexArray(0);
    }




    // GL_CHECK
    export inline const void checkGLError() {
        int storeError = glGetError();

        if (storeError != GL_NO_ERROR) {

            if (storeError == GL_INVALID_ENUM) {
               // logRun(" ERROR: invalied enum ! %d ", numberError);
            }
            else if (storeError == GL_INVALID_VALUE) {
               // logRun(" ERROR: invalid value  ! %d  ", numberError);
            }
            else if (storeError == GL_INVALID_OPERATION) {

               // logRun(" ERROR: stack overflow  %d ! ", numberError);
            }
            else if (storeError == GL_OUT_OF_MEMORY) {
               // logRun(" ERROR: stack underflow %d  ! ", numberError);
            }

        }
    }


    export inline const void  drawElements(unsigned int mode, int count, unsigned int type, const void* indices) {
        glDrawElements(mode, count, type, indices);
    }

    export constexpr inline void  glUniformMatrix4fv_m(int location, int count, bool transpose, const float* value) noexcept {
        glUniformMatrix4fv((int)location, count, transpose, value);
    }


    export constexpr inline void glUseProgramm(unsigned int programM) noexcept {
        glUseProgram(programM);
    }


    export constexpr inline void glBindVertexArraym(unsigned int vao) noexcept {
        glBindVertexArray(vao);
    }



    export constexpr inline void glBindBufferm(unsigned int target, unsigned int buffer) noexcept {
        glBindBuffer(target, buffer);
    }

    export constexpr inline void glBufferDatam(unsigned int target, int size, const void* data, unsigned int usage) noexcept {
        glBufferData(target, size, data, usage);
    }



    export constexpr inline void glVertexAttribPointerm(unsigned int index, int size, unsigned int type, bool normalized, int stride, const void* pointer) noexcept {
        glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    }


    export constexpr inline void glEnableVertexAttribArraym(unsigned int index) noexcept {
        glEnableVertexAttribArray(index);
    }

    export constexpr inline void glGenBuffersm(int n, unsigned int* buffers) noexcept {
        glGenBuffers(n, buffers);
    }


    export constexpr inline void glBindAttribLocationm(unsigned int program, unsigned int index, const char* name) noexcept {
        glBindAttribLocation(program, index, name);
    }

    export constexpr inline unsigned int glGetUniformLocationm(unsigned int program, const char* name) noexcept {
        return glGetUniformLocation(program, name);
    }


    export constexpr inline void glGenVertexArraysm(int n, unsigned int* arrays) noexcept {
        glGenVertexArrays(n, arrays);
    }

    export constexpr inline void glDeleteVertexArraysm(int n, const unsigned int* arrays) noexcept {
        glDeleteVertexArrays(n, arrays);
    }

    export constexpr inline void glDeleteProgramm(unsigned int n) noexcept {
        glDeleteProgram(n);
    }

    export constexpr inline void glUniform4fm(int location, float v0, float v1, float v2, float v3) noexcept {
        glUniform4f(location, v0, v1, v2, v3);
    }

    export constexpr inline void glUniform4fvm(int location, int sizeCount, const float* value) noexcept {
        glUniform4fv(location, sizeCount, value);
    }

    export constexpr inline void glUniform3fvm(int location, int sizeCount, const float* value) noexcept {
        glUniform3fv(location, sizeCount, value);
    }

    export inline void glDrawArraysm(unsigned int mode, int first, int count) noexcept {
        glDrawArrays(mode, first, count);
    }


    export constexpr inline void glGenFramebuffersm(int n, unsigned int* framebuffer) {
        glGenFramebuffers(n, framebuffer);
    }

    export constexpr inline void glBindFramebufferm(unsigned int target, unsigned int framebuffer) {
        glBindFramebufferEXT(target, framebuffer);
    }

    export constexpr inline void glDeleteFrameBufferm(int n, const unsigned int* framebuffer) {
        glDeleteFrameBuffer(n, framebuffer);
    }

    /*export inline void glBindFramebufferm(unsigned int target,unsigned int framebuffer) {
        glBindFramebuffer(target, framebuffer);
    }*/


//    export constexpr inline void glBlitFramebufferm(int srcx0, int srcY0, int srcx1, int srcY1, int dstx0, int dsty0, int dstX1, int dstY1, unsigned int mask, unsigned int filter) {
//        glBlitFramebuffer(srcx0, srcY0, srcx1, srcY1, dstx0, dsty0, dstX1, dstY1, mask, filter);
//    }


    export constexpr inline void glActiveTexturem(unsigned int enumTex) {
        glActiveTexture(enumTex);
    }

    export inline void glBindTexturem(unsigned int target, unsigned int texture) {
        glBindTexture(target, texture);
    }
//
//    export inline void glAttachShaderm(unsigned int program, unsigned int shader) {
//        glAttachShader(program, shader);
//    }
//
//    export inline void glDeleteTexturesm(unsigned int size, unsigned int* texture) {
//        glDeleteTextures(size, texture);
//    }
//
    export inline void setGLViewPort(int x, int y, int width, int height) {
        glViewport(x, y, width, height);
    }
//
//    export inline void  glUniform2fm(int location, float v0, float v1) {
//        glUniform2f(location, v0, v1);
//    }


    export inline void  glUniform1im(int location, float v0) {
        glUniform1i(location, v0);
    }




    export inline void  glEnablem(unsigned int blend) {
        glEnable(blend);
    }

    export inline void  glDisablem(unsigned int test) {
        glDisable(test);
    }


    export inline void 	glBlendFuncmOne() {
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
//
//    /*  export inline void glDrawArraysm(GLenum mode, GLint first, GLsizei count) {
//          glDrawArrays( mode, first, count);
//      }*/
//
//
//
    export inline void glDeleteBuffersm(GLsizei n, const unsigned int* buffers) {
        glDeleteBuffers(n, buffers);
    }
//
////     glDeleteBuffersm(1, &programBuffer);
//
//
    export inline void  glBindBufferBasem(GLenum target, GLuint index, GLuint buffer) {
        glBindBufferBase(target, index, buffer);
   }
//  //  glBufferSubDatam(


    export inline void glUniform3fm(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
        glUniform3f(location, v0, v1, v2);
    }


    export inline void glDrawElementsIndirectm(GLenum mode, GLenum type, const void* indirect)  {
        glDrawElementsIndirect(mode, type, indirect);
    }


    export inline unsigned int glCreateProgramm() {
       return glCreateProgram();
    }

    export inline void glVertexAttribIPointerm(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer) {
        glVertexAttribIPointer(index, size, type, stride, pointer);
    }

    export inline void glBufferSubDatam(GLenum target, GLintptr offset, GLsizeiptr size, const void* data) {
        glBufferSubData(target, offset, size, data);
    }

    export inline void glVertexAttribDivisorm(GLuint index, GLuint divisor) {
        glVertexAttribDivisor(index, divisor);
    }

    export inline void glBlendFuncm(GLenum sfactor, GLenum dfactor) {
        glBlendFunc(sfactor, dfactor);
    }

    export inline unsigned int glCreateShaderm(GLenum type) {
       return glCreateShader(type);
    }

    export inline void glDetachShaderm(GLuint program, GLuint shader) {
        glDetachShader(program, shader);
    }


}
