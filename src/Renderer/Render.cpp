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

Render::Render()
{
    active_scene = new SceneNull();
    kk_mesh_loader = new KKMeshLoader();
    end_flag=true;
    vbo_count=0;
    uvbo_count=0;
    
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL can't be initialized: "<< SDL_GetError() <<"\n";
        exit(1);
    }   
    
    int num = SDL_GetNumVideoDisplays();
    
    if(SDL_GetDisplayBounds(0,&display_info))
        std::cout << SDL_GetError();
    
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

//    display_info.w = 800;
//    display_info.h = 600;
    main_window = SDL_CreateWindow("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, display_info.w,display_info.h,SDL_WINDOW_OPENGL| SDL_WINDOW_ALLOW_HIGHDPI /*| SDL_WINDOW_FULLSCREEN*/);
    
    glRenderContext = SDL_GL_CreateContext(main_window);
    if(glRenderContext == NULL)
    {
        std::cout << "Problems creating Context: "<< SDL_GetError() <<"\n";
        exit(1);
    } 
//    glThreadContext = SDL_GL_CreateContext(main_window);
//    if(glThreadContext == NULL)
//    {
//        std::cout << "Problems creating Context: "<< SDL_GetError() <<"\n";
//        exit(1);
//    } 
    
    if(SDL_GL_SetSwapInterval(1))
        std::cout << "Problems with SDL_GL_SetSwapInterval: "<< SDL_GetError() <<"\n";
    
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
    glPushAttrib(GL_ENABLE_BIT);
//    glEnable(GL_CULL_FACE);
//    glCullFace(GL_FRONT_AND_BACK);
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
    SDL_GL_MakeCurrent(main_window,glRenderContext);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
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