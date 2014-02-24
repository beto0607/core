#include <Core/Core.h>
#include <Core/Clock.h>
#include <Renderer/Render.h>
#include <Renderer/Renderable.h>
#include <Renderer/Rectangle.h>
#include <Texture/Font.h>
#include <Command/CommandManager.h>
#include <Input/Input.h>
#include <Log/Logger.h>
#include <Texture/TextureManager.h>
#include <Texture/Texture.h>
#include <Texture/TextManager.h>
#include <iostream>
#include <Input/Input.h>
#include <Input/KeyBoardManager.h>
#include <Scene/Scene.h>
#include <Core/TimeEventListener.h>
#include <Scene/MaterialNull.h>
#include <Audio/AudioManager.h>
#include <Audio/Audio.h>
#include <stdio.h>

using namespace unnivelmas;

Core::Core()
{
    logger = (Logger::getInstance());
    render = new Render();
    logger->infoLog("Render Manager has been created sucefully");
    input = new Input();
    logger->infoLog("Input Manager has been created Sucefully");
    command = new CommandManager();
    logger->infoLog("Command Console Manager has been create susefully");
    clock = new Clock(60);
    logger->infoLog("Clock has been created Susefully");
    texture = new TextureManager();
    logger->infoLog("TextureManager has been created Susefully");
    logger->infoLog("Core has been created Susefully");
    audio = new AudioManager();
    audio->openAudioDevice();
    text = new TextManager();
    texture->setNullMaterial(new MaterialNull());
}

Core::~Core()
{
    std::cout << "\n1Nivel+ Engine will shut down\n";
    clock->~Clock();
    render->~Render();
    input->~Input();
    logger->~Logger();
    audio->~AudioManager();
    texture->~TextureManager();
    text->~TextManager();
    command->~CommandManager();
    Mix_CloseAudio();
    SDL_Quit();
    std::cout << "Bye ;-) \n";
    //system("killall -9 ejemplo ");
}

Core* Core::instance = 0;

Core* Core::getInstance()
{
    if(!instance)
        instance = new Core();
    return instance;    
}

GLvoid Core::stop()
{
    end_flag = false;
}

int command_thread_function(void* ptr)
{
    ((CommandManager*)ptr)->waitForCommand();
    return 15;
}

int input_thread_function(void* ptr)
{
    GLboolean resu = true;
    while(resu)
        resu = ((Input*)ptr)->checkInput();
    Core::getInstance()->stop();
    return 15;
}

Logger* Core::getLogger()
{
    return logger;
}

Render* Core::getRenderManager()
{
    return render;
}
 
RenderBuilder* Core::getRenderBuilder()
{
    return render_builder;
}

GLvoid Core::start()
{
    clock->setFPSTextFont(new Font("resources/fonts/fantasy.ttf", 16));
    GLint after_tick(0), before_tick(0);
    SDL_Thread* th_command = SDL_CreateThread(command_thread_function,"command",(void*)command);
    SDL_Thread* th_input   = SDL_CreateThread(input_thread_function,"input",(void*)input);
    end_flag = true;
    while(end_flag)
    {
        before_tick = SDL_GetTicks();
        input->checkInput();
        //Game Logic
        render->loop();
        after_tick = SDL_GetTicks();
        clock->endLoop(before_tick, after_tick);
    }
    this->~Core();
}

GLvoid Core::update()
{
    
}

Clock* Core::getClock()
{
    return clock;
}

TextureManager* Core::getTextureManager()
{
    return texture;
}

Renderable* Core::getRenderable(const GLchar* _render_name)
{
    return render->getActiveScene()->getRenderable(_render_name);
}

GLvoid Core::addRenderable(Renderable* ren)
{
    render->addRenderable(ren->getName().c_str(), ren);
}

GLvoid Core::scaleObject(const GLchar* id, GLfloat scale)
{
    render->scaleObject(id,scale);
}

GLvoid Core::moveObject(const GLchar* id,GLfloat _x, GLfloat _y)
{
    render->moveObject(id,_x,_y);
}

GLvoid Core::rotateObject(const GLchar* id,GLfloat _x, GLfloat _z)
{
    //render->rotateObject(id,scale);
}

GLvoid Core::loadTexture(const GLchar* name,const GLchar* file_path)
{
    texture->loadTexture(name,file_path);
}

Texture* Core::getTexture(const GLchar* _texture_name)
{
    return texture->getTexture(_texture_name);
}

GLvoid Core::addScene(Scene* _scene)
{
    render->activeScene(_scene);
}

GLvoid Core::addMouseKeyPressedListener(MouseEventListener* _mel)
{
    input->addMouseKeyPressedListener(_mel);
}

GLvoid Core::addMouseMovedListener(MouseEventListener* _mel)
{
    input->addMouseMovedListener(_mel);
}

GLvoid Core::addTimeListener(TimeEventListener* _mel)
{
    clock->addListener(_mel);
}

GLvoid Core::setFPS(GLint _fps)
{
    clock->setFPS(_fps);
}

GLvoid Core::addCollider(Renderable* _renderable)
{
    render->getActiveScene()->addCollider(_renderable->getShape());
}

GLvoid Core::addCollidable(Renderable* _renderable)
{
    render->getActiveScene()->addCollidable(_renderable->getShape());
}

GLvoid Core::play(const GLchar* _audio_name)
{
    audio->play(_audio_name);
}

GLvoid Core::addAudio(Audio* _audio)
{
    audio->addAudio(_audio->getName(), _audio);
}

GLvoid Core::addButtonDownListener(JoystickListener* _listener)
{
    input->getJoystickManager()->addButtonDownListener(_listener);
}

GLvoid Core::addButtonUpListener(JoystickListener* _listener)
{
    input->getJoystickManager()->addButtonUpListener(_listener);
}

GLvoid Core::addAxisListener(JoystickListener* _listener)
{
    input->getJoystickManager()->addAxisListener(_listener);
}

GLvoid Core::addKeyDownListener(const GLchar* _key,KeyBoardListener* _listener)
{
    input->getKeyBoardManager()->addKeyPressedListener(SDL_GetKeyFromName(_key),_listener);
}

GLvoid Core::addKeyUpListener(const GLchar* _key,KeyBoardListener* _listener)
{
    input->getKeyBoardManager()->addKeyReleaseListener(SDL_GetKeyFromName(_key),_listener);
}

GLvoid Core::addKeyLoopListener(const GLchar* _key,KeyBoardListener* _listener)
{
    input->getKeyBoardManager()->addPressedKeyYetListener(SDL_GetKeyFromName(_key),_listener);
}

GLvoid Core::addAllStateKeyListener(const GLchar* _key,KeyBoardListener* _listener)
{
    input->getKeyBoardManager()->addAllKeyListener(SDL_GetKeyFromName(_key),_listener);
}

GLvoid Core::fullScreenMode()
{
    //SDL_InitSubSystem(SDL_INIT_);
}