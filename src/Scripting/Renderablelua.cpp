/* 
 * File:   Renderablelua.cpp
 * Author: francisco
 * 
 * Created on 21 de febrero de 2014, 19:06
 */

#include <Scripting/Renderablelua.h>
#include <Renderer/Renderable.h>
#include <Core/Core.h>
#include <iostream>

using namespace unnivelmas;

Renderablelua::Renderablelua(Renderable* _render) {
    renderable = _render;
    L = luaL_newstate();
    luaL_openlibs(L);
}

Renderablelua::~Renderablelua() {
    lua_close(L);
}

GLint setX(lua_State* L)
{
    if(lua_isstring(L,-2))
    {
        Renderable* auxrender = (Core::getInstance())->getRenderable(lua_tostring(L,-2));
        auxrender->move(lua_tonumber(L,-1), auxrender->getY());
    }
}

GLint setY(lua_State* L)
{
    if(lua_isstring(L,-2))
    {
        Renderable* auxrender = (Core::getInstance())->getRenderable(lua_tostring(L,-2));
        auxrender->move(auxrender->getX(), lua_tonumber(L,-1));
    }
}

GLint getX(lua_State* L)
{
    Renderable* auxrender = (Core::getInstance())->getRenderable(lua_tostring(L,-1));
    lua_pushnumber(L,auxrender->getX());
}

GLint getY(lua_State* L)
{
    Renderable* auxrender = (Core::getInstance())->getRenderable(lua_tostring(L,-1));
    lua_pushnumber(L,auxrender->getY());  
}

int getRenderable(lua_State* L)
{
    lua_newtable(L);
    
    lua_pushstring(L,"getX");
    lua_pushcfunction(L,setX);
    lua_settable(L,-3);
    
    lua_pushstring(L,"getX");
    lua_pushcfunction(L,setX);
    lua_settable(L,-3);
    
    lua_pushstring(L,"setX");
    lua_pushcfunction(L,setX);
    lua_settable(L,-3);
    
    lua_pushstring(L,"setY");
    lua_pushcfunction(L,setY);
    lua_settable(L,-3);
    
    return 1;					
}

int getLigth(lua_State* L)
{
	std::cout << "Ligh \n";
}

int getScene(lua_State* L)
{
	std::cout << "Scene \n";
}

GLvoid Renderablelua::openLUAFile(const GLchar* _filename)
{
    if(luaL_loadfile(L, _filename))
        std::cout << "\nError\n\n" << lua_tostring(L,-1) << "\n\n";
    lua_newtable(L);
    lua_pushstring(L,"getRenderable");
    lua_pushcfunction(L,getRenderable);
    lua_settable(L,-3);
    lua_pushstring(L,"getScene");
    lua_pushcfunction(L,getScene);
    lua_settable(L,-3);
    lua_pushstring(L,"getLigth");
    lua_pushcfunction(L,getLigth);
    lua_settable(L,-3);
    lua_setglobal(L,"Core");	
    if(lua_pcall(L,0,0,0))
        std::cout << "\nError\n\n" << lua_tostring(L,-1) << "\n\n";
    
}

GLvoid Renderablelua::mouseMoved(GLfloat x,GLfloat y)
{
    lua_getglobal(L,"onMouseMoved");
    lua_pushinteger(L,x);
    lua_pushinteger(L,y);
    if(lua_pcall(L,2,1,0) != LUA_OK)
            std::cout << "Error: " << lua_tostring(L,-1) << " is not defined\n";
}
