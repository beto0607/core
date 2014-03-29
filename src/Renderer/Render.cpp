#include <Renderer/Render.h>
#include <Renderer/Actor.h>
#include <Renderer/Renderable.h>
#include <Renderer/KKMeshLoader.h>
#include <Scene/SceneNull.h>
#include <Scene/SceneReal.h>
#include <Log/Logger.h>
#include <iostream>
#include <stdlib.h>
#include <map>
#include <string>
#include <sstream>

using namespace kaikai;

GLvoid activateGLFunctions()
{
    glGenBuffers = (PFNGLGENBUFFERSPROC) SDL_GL_GetProcAddress("glGenBuffers");
    if(!glGenBuffers)
        std::cout << "anda como el orto\n";
    glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC) SDL_GL_GetProcAddress("glBindVertexArray");
    if(!glBindVertexArray)
        std::cout << "anda como el orto: glBindVertexArray\n";
    glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC) SDL_GL_GetProcAddress("glGenVertexArrays");
    if(!glGenVertexArrays)
        std::cout << "anda como el orto: glGenVertexArrays\n";
    glBindBuffer = (PFNGLBINDBUFFERPROC) SDL_GL_GetProcAddress("glBindBuffer");
    if(!glBindBuffer)
        std::cout << "anda como el orto: glBindBuffer\n";
    glBufferData = (PFNGLBUFFERDATAPROC) SDL_GL_GetProcAddress("glBufferData");
    if(!glBufferData)
        std::cout << "anda como el orto: glBufferData\n";
    glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC) SDL_GL_GetProcAddress("glGetBufferParameteriv");
    if(!glGetBufferParameteriv)
        std::cout << "anda como el orto: glGetBufferParameteriv\n";
    glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC) SDL_GL_GetProcAddress("glDisableVertexAttribArray");
    if(!glDisableVertexAttribArray)
        std::cout << "anda como el orto: glDisableVertexAttribArray\n";
    glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC) SDL_GL_GetProcAddress("glGetShaderInfoLog");
    if(!glGetShaderInfoLog)
        std::cout << "anda como el orto: glGetShaderInfoLog\n";
    glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC) SDL_GL_GetProcAddress("glGetProgramInfoLog");
    if(!glGetProgramInfoLog)
        std::cout << "anda como el orto: glGetProgramInfoLog\n";
    glValidateProgram = (PFNGLVALIDATEPROGRAMPROC) SDL_GL_GetProcAddress("glValidateProgram");
    if(!glValidateProgram)
        std::cout << "anda como el ort: glValidateProgram\n";
    glGetProgramiv = (PFNGLGETPROGRAMIVPROC) SDL_GL_GetProcAddress("glGetProgramiv");
    if(!glGetProgramiv)
        std::cout << "anda como el orto: glGetProgramiv\n";
    glCreateShader = (PFNGLCREATESHADERPROC) SDL_GL_GetProcAddress("glCreateShader");
    if(!glCreateShader)
        std::cout << "anda como el orto:glCreateShader \n";
    glShaderSource = (PFNGLSHADERSOURCEPROC) SDL_GL_GetProcAddress("glShaderSource");
    if(!glShaderSource)
        std::cout << "anda como el orto: glShaderSource\n";
    glCompileShader = (PFNGLCOMPILESHADERPROC) SDL_GL_GetProcAddress("glCompileShader");
    if(!glCompileShader)
        std::cout << "anda como el orto: glCompileShader\n";
    glCreateProgram = (PFNGLCREATEPROGRAMPROC) SDL_GL_GetProcAddress("glCreateProgram");
    if(!glCreateProgram)
        std::cout << "anda como el orto: glCreateProgram\n";
    glAttachShader = (PFNGLATTACHSHADERPROC) SDL_GL_GetProcAddress("glAttachShader");
    if(!glAttachShader)
        std::cout << "anda como el orto: glAttachShader\n";
    glLinkProgram = (PFNGLLINKPROGRAMPROC) SDL_GL_GetProcAddress("glLinkProgram");
    if(!glLinkProgram)
        std::cout << "anda como el orto: glLinkProgram\n";
    glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC) SDL_GL_GetProcAddress("glGetAttribLocation");
    if(!glGetAttribLocation)
        std::cout << "anda como el orto: glGetAttribLocation\n";
    glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC) SDL_GL_GetProcAddress("glGetUniformLocation");
    if(!glGetUniformLocation)
        std::cout << "anda como el orto: glGetUniformLocation\n";
    glGetShaderiv = (PFNGLGETSHADERIVPROC) SDL_GL_GetProcAddress("glGetShaderiv");
    if(!glGetShaderiv)
        std::cout << "anda como el orto: glGetShaderiv\n";
    glUseProgramObjectARB = (PFNGLUSEPROGRAMOBJECTARBPROC) SDL_GL_GetProcAddress("glUseProgramObjectARB");
    if(!glUseProgramObjectARB)
        std::cout << "anda como el orto: glUseProgramObjectARB\n";
    glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC) SDL_GL_GetProcAddress("glUniformMatrix4fv");
    if(!glUniformMatrix4fv)
        std::cout << "anda como el orto: glUniformMatrix4fv\n";
    glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC) SDL_GL_GetProcAddress("glEnableVertexAttribArray");
    if(!glEnableVertexAttribArray)
        std::cout << "anda como el orto: glEnableVertexAttribArray\n";
    glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC) SDL_GL_GetProcAddress("glVertexAttribPointer");
    if(!glVertexAttribPointer)
        std::cout << "anda como el orto: glVertexAttribPointer\n";
    glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC) SDL_GL_GetProcAddress("glGenerateMipmap");
    if(!glGenerateMipmap)
        std::cout << "anda como el orto: glGenerateMipmap\n";
    
}

Render::Render()
{
    active_scene = new SceneNull();
    kk_mesh_loader = new KKMeshLoader();
    end_flag=true;
    vbo_count=0;
    uvbo_count=0;
    
    if(SDL_Init(SDL_INIT_VIDEO || SDL_INIT_AUDIO))
    {
        std::cout << "SDL can't be initialized: "<< SDL_GetError() <<"\n";
        exit(1);
    }   
    
    SDL_InitSubSystem(SDL_INIT_VIDEO);
    if(SDL_GetDisplayBounds(0,&display_info))
        std::cout << SDL_GetError();
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
    
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 0);

    main_window = SDL_CreateWindow("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, display_info.w,display_info.h,SDL_WINDOW_OPENGL| SDL_WINDOW_ALLOW_HIGHDPI /*| SDL_WINDOW_FULLSCREEN*/);
    glRenderContext = SDL_GL_CreateContext(main_window);
    if(glRenderContext == NULL)
    {
        std::cout << "Problems creating Context: "<< SDL_GetError() <<"\n";
        exit(1);
    } 
    /*glThreadContext = SDL_GL_CreateContext(main_window);
    if(glThreadContext == NULL)
    {
        std::cout << "Problems creating Context: "<< SDL_GetError() <<"\n";
        exit(1);
    } */
    SDL_GL_SetSwapInterval(0);
    
    //SDL_GL_MakeCurrent(main_window,glRenderContext);
    //SDL_GL_MakeCurrent(main_window,glThreadContext);
    
    glewExperimental = GL_TRUE;
    GLenum status = glewInit();
    if (status != GLEW_OK)
    {
        std::cerr << "GLEW Error: " << glewGetErrorString(status) << "\n";
        exit(1);
    }
    //activateGLFunctions();
    std::stringstream mesage;
    mesage << "----------------------------------------------------------------\n";
    mesage << "Graphics Successfully Initialized\n";
    mesage << "OpenGL Info\n";
    mesage << "    Version: " << glGetString(GL_VERSION) << "\n";
    mesage << "    Vendor: "<< glGetString(GL_VERSION) << "\n";
    mesage << "    Renderer: "<< glGetString(GL_VERSION) << "\n";
    mesage << "    Shading: "<< glGetString(GL_VERSION) << "\n";
    mesage << "----------------------------------------------------------------\n";
    (Logger::getInstance())->infoLog(mesage.str());
    
    glClearColor(0.95,0.95,0.95,1);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    
    glGenBuffers(100,vbo);
    glGenBuffers(100,uvbo);
}

GLfloat Render::getRendererX()
{
    return (GLfloat) display_info.w;
}

GLfloat Render::getRendererY()
{
    return (GLfloat) display_info.h;
}

Render::~Render()
{
    Logger::getInstance()->infoLog(std::string("Render destructor..."));
    SDL_VideoQuit();
}

SDL_GLContext Render::getThreadContext()
{
    return glThreadContext;
}

SDL_Window* Render::getWindow()
{
    return main_window;
}

void Render::loop()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glMatrixMode(GL_MODELVIEW);
    active_scene->drawBuffer();
    SDL_GL_SwapWindow(main_window);
}

void Render::stop()
{
    end_flag=false;
}

void Render::addRenderable(const GLchar* renderable_id, Renderable* render)
{
    render->setName(renderable_id);
    active_scene->addRenderable(renderable_id,render);
    }

void Render::scaleObject(const GLchar* id, GLfloat _scale)
{
    active_scene->scaleObject(id,_scale);
}

void Render::moveObject(const GLchar* id, GLfloat _x, GLfloat _y)
{
    active_scene->moveObject(id,_x,_y);
}

GLvoid Render::activeScene(Scene* _scene)
{
    active_scene = _scene;
}

Scene* Render::getActiveScene()
{
    return active_scene;
}

GLint Render::getNextVertexBufferObjectNumber()
{
    return vbo[++vbo_count];
}

GLint Render::getNextUVBufferObjectNumber()
{
    return uvbo[++uvbo_count];
}

GLvoid Render::loadKKModel(const GLchar* _name,const GLchar* _filename)
{
    Actor* auxactor = kk_mesh_loader->loadKKModel(_filename);
    auxactor->setName(_name);        
    actors.insert(std::pair<std::string,Renderable*>(std::string(_name),(Renderable*)auxactor));
}

Actor* Render::getActor(const GLchar* _name)
{
    return (Actor*) actors.find(std::string(_name))->second;
}