/* 
 * File:   FreeCameraStrategy.cpp
 * Author: francisco
 * 
 * Created on 19 de marzo de 2014, 19:28
 */

#include <Scene/Camera/FreeCameraStrategy.h>
#include <Scene/Camera/Camera.h>
#include <iostream>

using namespace kaikai;

FreeCameraStrategy::FreeCameraStrategy() : CameraStrategy(){
    altpresed = 0;
    ctrlpressed = 0;
    shiftpressed = 0;
    difX = 0;difY =0;
}

FreeCameraStrategy::~FreeCameraStrategy() {
}

GLvoid FreeCameraStrategy::update(GLfloat _tick, Camera* _camera)
{
    std::cout <<altpresed << " - "<<ctrlpressed<< " - "<< shiftpressed<< "\n";
    if (altpresed == 1)
    {
         _camera->setPositionX(_camera->getPositionX() - (-0.3*difX));
         _camera->setPositionY(_camera->getPositionY() - (-0.3*difY)); 
       difY = 0; 
       difX = 0;
    }
    if (ctrlpressed == 1)
    {
       _camera->setPositionZ(_camera->getPositionZ() - (-0.2*difY)); 
       difY = 0; 
    }
    if (shiftpressed == 1)
    {
         _camera->setAngleY(_camera->getAngleY() - (0.001*difY)); 
         difY = 0; 
    }
}

GLvoid FreeCameraStrategy::mouseMoved(GLfloat _x, GLfloat _y, Camera* _camera)
{
    difX = lastX - _x;
    difY = lastY - _y;
    lastY = _y;
    lastX = _x;
}

GLvoid FreeCameraStrategy::keyLEFTALTdown(Camera* _camera)
{
    altpresed = 1;
    
}

GLvoid FreeCameraStrategy::keyLEFTALTup(Camera* _camera)
{
    altpresed = 0;
}

GLvoid FreeCameraStrategy::keyRIGTHCTRdown(Camera* _camera)
{
    ctrlpressed = 1;
}

GLvoid FreeCameraStrategy::keyRIGTHCTRup(Camera* _camera)
{
    ctrlpressed = 0;
}

GLvoid FreeCameraStrategy::keyRIGTHSHIFTdown(Camera* _camera)
{
    shiftpressed = 1;
}

GLvoid FreeCameraStrategy::keyRIGTHSHIFTup(Camera* _camera)
{
    shiftpressed = 0;
}

