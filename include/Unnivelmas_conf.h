/* 
 * File:   Unnivelmas_conf.h
 * Author: francisco
 *
 * Created on 7 de febrero de 2014, 18:45
 */

#ifndef UNNIVELMAS_CONF_H
#define	UNNIVELMAS_CONF_H

#define GLM_FORCE_RADIANS
#define GLM_FORCE_RADIANS
#define KAIKAI_NOGLEW

#include "../external/include/GL/glew.h"
#include "../external/include/SDL.h"
#include "../external/include/SDL_opengl.h"
#include "../external/include/SDL_syswm.h"
#include "../external/include/SDL_mixer.h"
#include "../external/include/SDL_thread.h"
#include "../external/include/SDL_timer.h"
#include "../external/include/SDL_ttf.h"
#include "../external/include/SDL_joystick.h"
#include "../external/include/SDL_net.h"
#include "../external/include/SDL_image.h"
#include "../external/include/glm/glm.hpp"
#include "../external/include/glm/gtx/euler_angles.hpp"
#include "../external/include/glm/gtc/type_ptr.hpp"
#include "../external/include/glm/gtc/matrix_transform.hpp"
extern "C"
{
    #include "../external/include/lua.hpp"      
}

#ifndef KAIKAI_NOGLEW
static PFNGLGENBUFFERSPROC glGenBuffers;
static PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
static PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
static PFNGLBINDBUFFERPROC glBindBuffer;
static PFNGLBUFFERDATAPROC glBufferData;
static PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv;
static PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
static PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
static PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;
static PFNGLVALIDATEPROGRAMPROC glValidateProgram;
static PFNGLGETPROGRAMIVPROC glGetProgramiv;
static PFNGLCREATESHADERPROC glCreateShader;
static PFNGLSHADERSOURCEPROC glShaderSource;
static PFNGLCOMPILESHADERPROC glCompileShader;
static PFNGLCREATEPROGRAMPROC glCreateProgram;
static PFNGLATTACHSHADERPROC glAttachShader;
static PFNGLLINKPROGRAMPROC glLinkProgram;
static PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation;
static PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
static PFNGLGETSHADERIVPROC glGetShaderiv;
static PFNGLUSEPROGRAMOBJECTARBPROC glUseProgramObjectARB;
static PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
static PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
static PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
static PFNGLGENERATEMIPMAPPROC glGenerateMipmap;
#endif

#endif	/* UNNIVELMAS_CONF_H */

