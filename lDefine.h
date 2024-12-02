#pragma once

#pragma region Desktop Family
//#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef signed char GLbyte;
typedef short GLshort;
typedef int GLint;
typedef int GLsizei;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;
typedef unsigned int GLuint;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void GLvoid;

#define GLTRUE    1
#define GLFALSE   0

#define glBufferSize 0x8764
#define glBufferUsage 0x8765
#define glQueryCount 0x8864
#define glCurrentQuery 0x8865
//#define GL_QUERY_RESULT                   0x8866
//#define GL_QUERY_RESULT_AVAILABLE         0x8867
#define glElementArrayBuffer 0x8893
//#define GL_ARRAY_BUFFER_BINDING           0x8894
#define glElementArrayBufferBinding 0x8895
//#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
//#define GL_READ_ONLY                      0x88B8
//#define GL_WRITE_ONLY                     0x88B9
//#define GL_READ_WRITE                     0x88BA
//#define GL_BUFFER_ACCESS                  0x88BB
//#define GL_BUFFER_MAPPED                  0x88BC
//#define GL_BUFFER_MAP_POINTER             0x88BD
//#define GL_STREAM_DRAW                    0x88E0
//#define GL_STREAM_READ                    0x88E1
//#define GL_STREAM_COPY                    0x88E2
//#define GL_STATIC_DRAW                    0x88E4
//#define GL_STATIC_READ                    0x88E5
//#define GL_STATIC_COPY                    0x88E6
//#define GL_DYNAMIC_DRAW                   0x88E8
//#define GL_DYNAMIC_READ                   0x88E9
//#define GL_DYNAMIC_COPY                   0x88EA
//#define GL_SAMPLES_PASSED                 0x8914
//#define GL_SRC1_ALPHA                     0x8589
//#define GL_VERTEX_ARRAY_BUFFER_BINDING    0x8896
//#define GL_NORMAL_ARRAY_BUFFER_BINDING    0x8897
//#define GL_COLOR_ARRAY_BUFFER_BINDING     0x8898
//#define GL_INDEX_ARRAY_BUFFER_BINDING     0x8899
//#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING 0x889A
//#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING 0x889B
//#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING 0x889C
//#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING 0x889D
//#define GL_WEIGHT_ARRAY_BUFFER_BINDING    0x889E
//#define GL_FOG_COORD_SRC                  0x8450
//#define GL_FOG_COORD                      0x8451
//#define GL_CURRENT_FOG_COORD              0x8453
//#define GL_FOG_COORD_ARRAY_TYPE           0x8454
//#define GL_FOG_COORD_ARRAY_STRIDE         0x8455
//#define GL_FOG_COORD_ARRAY_POINTER        0x8456
//#define GL_FOG_COORD_ARRAY                0x8457
//#define GL_FOG_COORD_ARRAY_BUFFER_BINDING 0x889D
//#define GL_SRC0_RGB                       0x8580
//#define GL_SRC1_RGB                       0x8581
//#define GL_SRC2_RGB                       0x8582
//#define GL_SRC0_ALPHA                     0x8588
//#define GL_SRC2_ALPHA                     0x858A

#define glByte 0x1400
#define glUnsignedByte 0x1401
#define glShort 0x1402
#define glUnsignedShort 0x1403
#define glInt 0x1404
#define glUnsignedInt 0x1405
#define glFloat 0x1406
#define gl2Byte 0x1407
#define gl3Byte 0x1408
#define gl4Byte 0x1409
#define glDouble 0x140A

#define glArrayBuf 0x8892 
#define glStatDraw 0x88E4

#define glPoints 0x0000
#define glLines  0x0001
#define glLineLoop 0x0002
#define glLineStrip 0x0003
#define glTriangles 0x0004
#define glTrianglesStrip 0x0005
#define glTrianglesFan 0x0006
#define glQuards 0x0007
#define glQuarStrip 0x0008
#define glPolygon 0x0009
#define infoLogLeng 0x8B84

// GL_STREAM_DRAW
#define streamDRaw	  0x88E0
#define uniformBuffer 0x8A11

#define glFrameBuffer  0x8D40
#define glREadFrameBuf 0x8CA8
#define glDRawFrameBuf 0x8CA9
#define glTex2D        0x0DE1
#define glTex2DMulti   0x9100
#define glColorBufBit  0x00004000
#define glNearest      0x2600
#define glTex0        0x84C0      //GL_TEXTURE0
#define glTex1		  0x84C1	  //GL_TEXTURE1
#define glTex2        0x84C2 
#define glTex3        0x84C3      // GL_TEXTURE3
#define glTex_3D      0x806F      // GL_TEXTURE_3D     


#define glBlend        0x0BE2
#define glDepthTest    0x0B71
#define glCullFa       0x0B44
#define srcAlpha       0x0302
#define srcAlphaMinus  0x0303
#define glFrameBufferComp 0x8CD5 // GL_FRAMEBUFFER_COMPLETE
#define glFrameBuffer     0x8D40
//shader 
#define fragShader  0x8B30//GL_FRAGMENT_SHADER                0x8B30
#define vertShader 0x8B31 //GL_VERTEX_SHADER                  0x8B31

#define shaderStorageBuffer   0x90D2
#define glStreamDraw          0x88E0

#define glAlpha                          0x1906
#define glRGB                            0x1907
#define glRGBA                           0x1908

/* PixelFormat */
//#define GL_COLOR_INDEX                    0x1900
//#define GL_STENCIL_INDEX                  0x1901
//#define GL_DEPTH_COMPONENT                0x1902
//#define GL_RED                            0x1903
//#define GL_GREEN                          0x1904
//#define GL_BLUE                           0x1905
//#define GL_ALPHA                          0x1906
#define glRGB                            0x1907
//#define GL_RGBA                           0x1908
//#define GL_LUMINANCE                      0x1909
//#define GL_LUMINANCE_ALPHA                0x190A

using myUnsignedInt = unsigned int;