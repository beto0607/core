    /* 
 * File:   XMLLoader.cpp
 * Author: beto0607
 * 
 * Created on 16 de mayo de 2014, 15:51
 */

#include <Core/XMLLoader.h>

#include <Scene/Scene.h>
#include <Scene/Camera/Camera.h>
#include <Renderer/Renderable.h>
#include <Scene/Ligth.h>
#include <Core/Core.h>
#include <map>
#include <string>
#include <stdlib.h>
#include <External/tinyxml2.h>
#include <iostream>

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

void XMLLoader::loadScene(const char* _file, Scene* _scene){
    XMLDocument doc; 
    if(doc.LoadFile(_file) != XML_NO_ERROR){
        switch(doc.ErrorID()){
            case (XML_ERROR_FILE_NOT_FOUND): std::cout << "XML_ERROR_FILE_NOT_FOUND\n"; break;
            case (XML_ERROR_EMPTY_DOCUMENT): std::cout << "XML_ERROR_EMPTY_DOCUMENT\n"; break;
            case (XML_ERROR_FILE_READ_ERROR): std::cout << "XML_ERROR_FILE_READ_ERROR\n"; break;
            case (XML_ERROR_FILE_COULD_NOT_BE_OPENED): std::cout << "XML_ERROR_FILE_COULD_NOT_BE_OPENED\n"; break;
            case (XML_SUCCESS): std::cout << "XML_SUCCESS\n"; break;
            case (XML_CAN_NOT_CONVERT_TEXT): std::cout << "XML_CAN_NOT_CONVERT_TEXT\n"; break;
            case (XML_ERROR_ELEMENT_MISMATCH): std::cout << "XML_ERROR_ELEMENT_MISMATCH\n"; break;
            case (XML_ERROR_IDENTIFYING_TAG): std::cout << "XML_ERROR_IDENTIFYING_TAG\n"; break;
            case (XML_ERROR_PARSING): std::cout << "XML_ERROR_PARSING\n"; break;        };
    }else{
        XMLNode* node = doc.FirstChild()->FirstChild();
        XMLElement* ele = node->ToElement();
        Camera* cam =_scene->getCamera();
        if(cam->getName() == ele->Value()){
            ele = node->FirstChildElement("position");
            cam->setPositionX(ele->FloatAttribute("x"));
            cam->setPositionY(ele->FloatAttribute("y"));
            cam->setPositionZ(ele->FloatAttribute("z")); 
            ele = node->FirstChildElement("angle");
            cam->setAngleX(ele->FloatAttribute("x"));
            cam->setAngleY(ele->FloatAttribute("y"));
            cam->setAngleZ(ele->FloatAttribute("z")); 
            ele = node->FirstChildElement("focus");
            cam->setFocusX(ele->FloatAttribute("x"));
            cam->setFocusY(ele->FloatAttribute("y"));
            cam->setFocusZ(ele->FloatAttribute("z")); 
        }
        node = node->NextSibling();
        ele = node->ToElement();    
        if(ele->Value(), "Renderables"){
            std::map<std::string,Renderable*>* auxR = _scene->getRenderables();
            Renderable* rr;
            XMLNode* nodeR = node->FirstChild();
            while(nodeR!=NULL){
                ele = nodeR->ToElement();
                rr = auxR->at(ele->Value());
                ele = nodeR ->FirstChildElement("scale");
                rr->scaleX(ele->FloatAttribute("x"));
                rr->scaleY(ele->FloatAttribute("y"));
                rr->scaleZ(ele->FloatAttribute("z"));
                ele = nodeR ->FirstChildElement("position");
                rr->setX(ele->FloatAttribute("x"));
                rr->setY(ele->FloatAttribute("y"));
                rr->setZ(ele->FloatAttribute("z"));
                nodeR = nodeR->NextSibling();
            }
        }
        node = node->NextSibling();
        ele = node->ToElement(); 
        if(ele->Value(), "Lights"){
            std::map<std::string,Ligth*>  auxL = _scene->getLights();
            Ligth* ll;
            XMLNode* nodeL = node->FirstChild();
            while(nodeL!=NULL){
                ele = nodeL->ToElement();
                ll = auxL.at(ele->Value());
                ll->setIntensity(ele->FloatAttribute("intensity"));
                ele = ele->FirstChildElement("color");
                ll->setColor(ele->FloatAttribute("r"), ele->FloatAttribute("g"), ele->FloatAttribute("b"));
            }
        }
    }
}

void XMLLoader::saveScene(const char* _file, Scene* _scene){
    FILE * f ;
    f = fopen(_file,"w");
    XMLPrinter * auxp = new XMLPrinter(f,false);
    auxp->OpenElement("Scene");
//Camera-----------------------------------------
    auxp->OpenElement((_scene->getCamera()->getName().c_str()));
        auxp->OpenElement("position");
            auxp->PushAttribute("x",_scene->getCamera()->getPositionX());
            auxp->PushAttribute("y",_scene->getCamera()->getPositionY());
            auxp->PushAttribute("z",_scene->getCamera()->getPositionZ());
        auxp->CloseElement();
        auxp->OpenElement("focus");
            auxp->PushAttribute("x",_scene->getCamera()->getFocusX());
            auxp->PushAttribute("y",_scene->getCamera()->getFocusY());
            auxp->PushAttribute("z",_scene->getCamera()->getFocusZ());
        auxp->CloseElement();
        auxp->OpenElement("angle");
            auxp->PushAttribute("x",_scene->getCamera()->getAngleX());
            auxp->PushAttribute("y",_scene->getCamera()->getAngleY());
            auxp->PushAttribute("z",_scene->getCamera()->getAngleZ());
        auxp->CloseElement();
    auxp->CloseElement(); 
//Renderables------------------------------------
    auxp->OpenElement("Renderables");
    std::map<std::string,Renderable*>* aux = _scene->getRenderables();
    for(std::map<std::string,Renderable*>::iterator it = aux->begin(); it != aux->end();++it){
        auxp->OpenElement(((*it).second->getName().c_str()));
            auxp->OpenElement("position");
                auxp->PushAttribute("x", (*it).second->getX());
                auxp->PushAttribute("y", (*it).second->getY());
                auxp->PushAttribute("z", (*it).second->getZ());
            auxp->CloseElement();
            auxp->OpenElement("scale");
                auxp->PushAttribute("x", (*it).second->getScaleX());
                auxp->PushAttribute("y", (*it).second->getScaleY());
                auxp->PushAttribute("z", (*it).second->getScaleZ());
            auxp->CloseElement();
        auxp->CloseElement();
    }
    auxp->CloseElement();
//Lights-----------------------------------------
    auxp->OpenElement("Lights");
    std::map<std::string,Ligth*>  auxL = _scene->getLights();
    for(std::map<std::string,Ligth*> ::iterator it = auxL.begin(); it != auxL.end();++it){
        auxp->OpenElement("Light");
            auxp->PushAttribute("intensity", (*it).second->getIntensity());
            auxp->OpenElement("color");
                auxp->PushAttribute("r", (*it).second->getColorR());
                auxp->PushAttribute("g", (*it).second->getColorG()); 
                auxp->PushAttribute("b", (*it).second->getColorB());
            auxp->CloseElement();
        auxp->CloseElement();
    }
    auxp->CloseElement();
//-----------------------------------------------    
    auxp->CloseElement();
    fclose(f);
}























void XMLLoader::saveScene2(const char* _file, Scene* _scene){
    FILE * f ;
    f = fopen(_file,"w");
    XMLPrinter * auxp = new XMLPrinter(f,false);
    auxp->OpenElement("Scene");
//Camera-----------------------------------------
    auxp->OpenElement((_scene->getCamera()->getName().c_str()));
        auxp->OpenElement("position");auxp->OpenElement("x");auxp->PushText(_scene->getCamera()->getPositionX()); auxp->CloseElement(); auxp->OpenElement("y");auxp->PushText(_scene->getCamera()->getPositionY()); auxp->CloseElement();auxp->OpenElement("z");auxp->PushText(_scene->getCamera()->getPositionZ()); auxp->CloseElement();auxp->CloseElement();
        auxp->OpenElement("focus");auxp->OpenElement("x");auxp->PushText(_scene->getCamera()->getFocusX()); auxp->CloseElement();auxp->OpenElement("y");auxp->PushText(_scene->getCamera()->getFocusY()); auxp->CloseElement();auxp->OpenElement("z");auxp->PushText(_scene->getCamera()->getFocusZ()); auxp->CloseElement();auxp->CloseElement();
        auxp->OpenElement("angle");auxp->OpenElement("x");auxp->PushText(_scene->getCamera()->getAngleX()); auxp->CloseElement();auxp->OpenElement("y");auxp->PushText(_scene->getCamera()->getAngleY()); auxp->CloseElement();auxp->OpenElement("z");auxp->PushText(_scene->getCamera()->getAngleZ()); auxp->CloseElement();auxp->CloseElement();
    auxp->CloseElement();    
//-----------------------------------------------
//Renderables------------------------------------
    auxp->OpenElement("Renderables");
    std::map<std::string,Renderable*>* aux = _scene->getRenderables();
    for(std::map<std::string,Renderable*>::iterator it = aux->begin(); it != aux->end();++it){
        auxp->OpenElement(((*it).second->getName().c_str()));
            auxp->OpenElement("position");
            
                auxp->OpenElement("x");auxp->PushText((*it).second->getX()); auxp->CloseElement(); 
                auxp->OpenElement("y");auxp->PushText((*it).second->getY()); auxp->CloseElement();
                auxp->OpenElement("z");auxp->PushText((*it).second->getZ()); auxp->CloseElement();
            auxp->CloseElement();
            auxp->OpenElement("scale");auxp->PushText((*it).second->getScale());auxp->CloseElement();
        auxp->CloseElement();
    }
    auxp->CloseElement();
//-----------------------------------------------    
//Lights-----------------------------------------
    auxp->OpenElement("Lights");
    std::map<std::string,Ligth*>  auxL = _scene->getLights();
    for(std::map<std::string,Ligth*> ::iterator it = auxL.begin(); it != auxL.end();++it){
        auxp->OpenElement("Light");
            auxp->OpenElement("color");auxp->OpenElement("r");auxp->PushText((*it).second->getColorR()); auxp->CloseElement(); auxp->OpenElement("g");auxp->PushText((*it).second->getColorG()); auxp->CloseElement();auxp->OpenElement("b");auxp->PushText((*it).second->getColorB()); auxp->CloseElement();auxp->CloseElement();
            auxp->OpenElement("intensity");auxp->PushText((*it).second->getIntensity());auxp->CloseElement();
        auxp->CloseElement();
    }
    auxp->CloseElement();
//-----------------------------------------------    
    auxp->CloseElement();
    fclose(f);
}