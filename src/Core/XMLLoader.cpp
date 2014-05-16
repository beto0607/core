    /* 
 * File:   XMLLoader.cpp
 * Author: beto0607
 * 
 * Created on 16 de mayo de 2014, 15:51
 */

#include <Core/XMLLoader.h>

#include "../Unnivelmas_conf.h"
#include "Scene/Scene.h"
#include "Scene/Camera/Camera.h"
#include "Renderer/Renderable.h"
#include "Scene/Ligth.h"
#include <map>
#include <string>
#include <stdlib.h>
#include <External/tinyxml2.h>

using namespace kaikai;

XMLLoader::XMLLoader(){}

XMLLoader::XMLLoader(const char * _file) {
    file = _file;
    load();
}

void XMLLoader::setFile(const char* _file){
    file = _file;
    load();
}

void XMLLoader::load(){
    XMLDocument doc;
    doc.LoadFile( file );
    XMLNode* node = doc.FirstChild();
    XMLElement* ele = node->ToElement();
    while(node->NextSibling() != NULL){
        data.insert(std::pair<std::string,std::string>(ele->Value(),ele->GetText()));
        node = node->NextSibling();
        ele = node->ToElement();
    }
    data.insert(std::pair<std::string, std::string>(ele->Value(),ele->GetText()));
}

float XMLLoader::getFloat(const char* _key){
    const char * aux = data[_key].c_str();
    return strtod(aux, NULL);
}
int XMLLoader::getInt(const char* _key){
    const char * aux = data[_key].c_str();
    return strtol(aux, NULL, 10);
}
const char * XMLLoader::getString(const char* _key){
    return data[_key].c_str();
}
XMLLoader::~XMLLoader() {
}

void XMLLoader::saveScene(const char* _file, Scene* _scene){
    FILE * f ;
    f = fopen(_file+".xml","w");
    XMLPrinter * auxp = new XMLPrinter(f,false);
    auxp->OpenElement("Scene");
//Camera-----------------------------------------
    auxp->OpenElement(_scene->getCamera()->getName());
        auxp->OpenElement("position");auxp->OpenElement("x");auxp->PushText(_scene->getCamera()->getPositionX()); auxp->CloseElement(); auxp->OpenElement("y");auxp->PushText(_scene->getCamera()->getPositionY()); auxp->CloseElement();auxp->OpenElement("z");auxp->PushText(_scene->getCamera()->getPositionZ()); auxp->CloseElement();auxp->CloseElement();
        auxp->OpenElement("focus");auxp->OpenElement("x");auxp->PushText(_scene->getCamera()->getFocusX()); auxp->CloseElement();auxp->OpenElement("y");auxp->PushText(_scene->getCamera()->getFocusY()); auxp->CloseElement();auxp->OpenElement("z");auxp->PushText(_scene->getCamera()->getFocusZ()); auxp->CloseElement();auxp->CloseElement();
        auxp->OpenElement("angle");auxp->OpenElement("x");auxp->PushText(_scene->getCamera()->getAngleX()); auxp->CloseElement();auxp->OpenElement("y");auxp->PushText(_scene->getCamera()->getAngleY()); auxp->CloseElement();auxp->OpenElement("z");auxp->PushText(_scene->getCamera()->getAngleZ()); auxp->CloseElement();auxp->CloseElement();
    auxp->CloseElement();    
//-----------------------------------------------
//Renderables------------------------------------
    auxp->OpenElement("Renderables");
    std::map<std::string,Renderable*>* aux = _scene->getRenderables();
    for(std::map<std::string,Renderable*>::iterator it = aux->begin(); it != aux->end();++it){
        auxp->OpenElement((*it).second->getName());
            auxp->OpenElement("position");auxp->OpenElement("x");auxp->PushText((*it).second->getX()); auxp->CloseElement(); auxp->OpenElement("y");auxp->PushText((*it).second->getY()); auxp->CloseElement();auxp->OpenElement("z");auxp->PushText((*it).second->getZ()); auxp->CloseElement();auxp->CloseElement();
            auxp->OpenElement("scale");auxp->PushText((*it).second->getScale());auxp->CloseElement();
        auxp->CloseElement();
    }
    auxp->CloseElement();
//-----------------------------------------------    
//Lights-----------------------------------------
    auxp->OpenElement("Lights");
    std::map<std::string,Ligth*>  auxL = _scene->getLights();
    for(std::map<std::string,Ligth*> ::iterator it = auxL->begin(); it != auxL->end();++it){
        auxp->OpenElement("Light");
            auxp->OpenElement("color");auxp->OpenElement("r");auxp->PushText((*it).second->getColorR()); auxp->CloseElement(); auxp->OpenElement("g");auxp->PushText((*it).second->getColorG()); auxp->CloseElement();auxp->OpenElement("b");auxp->PushText((*it).second->getColorB()); auxp->CloseElement();auxp->CloseElement();
            auxp->OpenElement("intensity");auxp->PushText((*it).second->getIntensity());auxp->CloseElement();
        auxp->CloseElement();
    }
    auxp->CloseElement();
//-----------------------------------------------    
}