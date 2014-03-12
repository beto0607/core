#include <Renderer/Render.h>
#include <Renderer/Renderable.h>
#include <Renderer/KKMeshLoader.h>
#include <Scene/SceneNull.h>
#include <Scene/SceneReal.h>
#include <Log/Logger.h>
#include <iostream>
#include <stdlib.h>
#include <map>
#include <string>

using namespace kaikai;

Render::Render()
{
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
    
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_SHARE_WITH_CURRENT_CONTEXT, 1);
    main_window = SDL_CreateWindow("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, display_info.w,display_info.h,SDL_WINDOW_OPENGL | /*SDL_WINDOW_FULLSCREEN |*/ SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(main_window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == 0)
    {
        std::cout << "Renderer creation fail: "<< SDL_GetError() <<"\n";
        exit(1);        
    }
    SDL_SetRenderDrawColor(renderer,230,230,230,0);
    
    glRenderContext = SDL_GL_CreateContext(main_window);
    glThreadContext = SDL_GL_CreateContext(main_window);
    
    GLenum status = glewInit();
    if (status != GLEW_OK)
    {
        std::cerr << "GLEW Error: " << glewGetErrorString(status) << "\n";
        exit(1);
    }
    SDL_GL_SetSwapInterval(1);
    glClearColor(0.8,0.8,0.8,1);
    active_scene = new SceneNull();
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
    active_scene->drawBuffer();
    SDL_GL_SwapWindow(main_window);
    if(end_flag == false){this->~Render();}
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

GLvoid Render::loadKKModel(const GLchar* _filename)
{
    kk_mesh_loader->loadKKModel(_filename);
}