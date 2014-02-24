/* 
 * File:   Clock.cpp
 * Author: fran
 * 
 * Created on December 8, 2013, 4:37 PM
 */

#include <Core/Clock.h>
#include <Log/Logger.h>
#include <Core/Core.h>
#include <Core/TimeEventListener.h>
#include <Renderer/Text.h>
#include <sstream>
#include <iostream>

using namespace unnivelmas;

Clock::Clock(GLint time) {
    frame_time = 1000 / time;
    frame_tick = 0;
    frame_count = 0;
}

Clock::~Clock() {
    Logger::getInstance()->infoLog(std::string("Clock destructor..."));
}

void Clock::endLoop(GLint before, GLint after)
{    
    frame_tick = after - before; 
    if(frame_tick < frame_time)
            SDL_Delay(frame_time - frame_tick);
    after = SDL_GetTicks();
    frame_tick = after - before;
    for(std::list<TimeEventListener*>::iterator it= listeners.begin(); it != listeners.end(); ++it)
       (*it)->update(frame_tick/1000);
    frame_count = frame_count + ( after - before );
    fps++;
    if(frame_count > 1000)
    {
        frame_count = 0;
        final_fps = fps;
        std::stringstream info_fps;
        info_fps << "fps: " << final_fps;
        fps_info->setText(info_fps.str().c_str());
        fps = 0;
    }
}

GLvoid Clock::showFPS()
{
        std::cout << "FPS: " << final_fps << "\n";
}

GLvoid Clock::setFPSTextFont(Font* _font)
{
    fps_info = new Text("fps_info_show");
    fps_info->setFont(_font);
    fps_info->setText("FPS: ");
    fps_info->move(40,30);
    fps_info->setColor(0,0,0,0);
    (Core::getInstance())->addRenderable(fps_info);
}

GLvoid Clock::setFPS(GLint time)
{
        frame_time = 1000 / time;
}

GLvoid Clock::addListener(TimeEventListener* _listener)
{
    this->listeners.push_back(_listener);
}

