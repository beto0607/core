/* 
 * File:   Ligth.cpp
 * Author: francisco
 * 
 * Created on 12 de diciembre de 2013, 17:47
 */

#include <Scene/Ligth.h>

using namespace kaikai;

Ligth::Ligth() {
}

Ligth::~Ligth() {
}

void Ligth::turnOn()
{

}

void Ligth::turnOff()
{

}

GLfloat Ligth::getIntensity(){return this->intensity;}
GLfloat Ligth::getColorR(){return this->color.r;}
GLfloat Ligth::getColorG(){return this->color.g;}
GLfloat Ligth::getColorB(){return this->color.b;}

GLvoid Ligth::setColor(float r, float g, float b){this->color = glm::vec3(r,g,b);}

GLvoid Ligth::setIntensity(float i){this->intensity = i;}