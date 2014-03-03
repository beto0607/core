/* 
 * File:   Renderablelua.cpp
 * Author: francisco
 * 
 * Created on 21 de febrero de 2014, 19:06
 */

#include <Scripting/Renderablelua.h>
#include <Renderer/Renderable.h>
#include <Renderer/Rectangle.h>
#include <Core/Core.h>
#include <Scene/Camera.h>
#include <iostream>
#include <Scene/Scene.h>
#include <Renderer/Render.h>

using namespace kaikai;

Renderablelua::Renderablelua(Renderable* _render) {
    renderable = _render;
    L = luaL_newstate();
    luaL_openlibs(L);
}

Renderablelua::~Renderablelua() {
    lua_close(L);
}

GLint getX (lua_State *L)
{
    if( !lua_islightuserdata(L,-1))
        std::cout << "Parameter error, usage:\n" << "           Core.getX(<renderable_pointer>)\n";
    else
    {
        Rectangle* aux = (Rectangle*) lua_touserdata(L,-1);
        lua_pushnumber(L,aux->getX());
    }
    return 1;
}

GLint getY (lua_State *L)
{
    if( !lua_islightuserdata(L,-1))
        std::cout << "Parameter error, usage:\n" << "           Core.getY(<renderable_pointer>)\n";
    else
    {
        Rectangle* aux = (Rectangle*) lua_touserdata(L,-1);
        lua_pushnumber(L,aux->getY());
    }
    return 1;
}

GLint getCameraX (lua_State *L)
{
    if( !lua_islightuserdata(L,-1))
        std::cout << "Parameter error, usage:\n" << "           Core.getCameraX(<camera_pointer>)\n";
    else
    {
        Camera* cam = (Camera*) lua_touserdata(L,-1);
        lua_pushnumber(L,cam->getX());
    }
    return 1;
}

GLint getCameraY (lua_State *L)
{
    if( !lua_islightuserdata(L,-1))
        std::cout << "Parameter error, usage:\n" << "           Core.getCameraY(<camera_pointer>)\n";
    else
    {
        Camera* cam = (Camera*) lua_touserdata(L,-1);
        lua_pushnumber(L,cam->getY());
    }
    return 1;
}

GLint getZ(lua_State *L)
{
    return 1;
}

GLint setX (lua_State *L)
{
    if( !lua_isnumber(L,-1) || !lua_islightuserdata(L,-2))
        std::cout << "Parameter error, usage:\n" << "           Core.setX(<renderable_pointer> , <float>)\n";
    else
    {
        Rectangle* aux = (Rectangle*) lua_touserdata(L,-2);
        aux->setX(lua_tonumber(L,-1));
    }
    return 1;
}

GLint setCameraX (lua_State *L)
{
    if( !lua_isnumber(L,-1) || !lua_islightuserdata(L,-2))
        std::cout << "Parameter error, usage:\n" << "           Core.setCameraX(<camera_pointer> , <float>)\n";
    else
    {
        Camera* aux = (Camera*) lua_touserdata(L,-2);
        aux->setX(lua_tonumber(L,-1));
    }
    return 1;
}

GLint setCameraY (lua_State *L)
{
    if( !lua_isnumber(L,-1) || !lua_islightuserdata(L,-2))
        std::cout << "Parameter error, usage:\n" << "           Core.setCameraY(<camera_pointer> , <float>)\n";
    else
    {
        Camera* aux = (Camera*) lua_touserdata(L,-2);
        aux->setY(lua_tonumber(L,-1));
    }
    return 1;
}

GLint setY (lua_State *L)
{
    if( !lua_isnumber(L,-1) || !lua_islightuserdata(L,-2))
        std::cout << "Parameter error, usage:\n" << "           Core.setY(<renderable_pointer> , <float>)\n";
    else
    {
        Rectangle* aux = (Rectangle*) lua_touserdata(L,-2);
        aux->setY(lua_tonumber(L,-1));
    }
    return 1;
}

GLint setAnimation (lua_State *L)
{
    if( !lua_isstring(L,-1) || !lua_islightuserdata(L,-2))
        std::cout << "Parameter error, usage:\n" << "           Core.setAnimation(<renderable_pointer> , <string_animation_name>)\n";
    else
    {
        Rectangle* aux = (Rectangle*) lua_touserdata(L,-2);
        aux->play(lua_tostring(L,-1));
        return 1;
    }
}

GLint setZ (lua_State *L)
{
    return 1;
}

int getRenderable(lua_State* L)
{
    if( !lua_isstring(L,-1))
        std::cout << "Parameter error, usage:\n" << "           Core.getRenderable(<string_renderable_id>)\n";
    else
    {
        Renderable* rec = (Core::getInstance())->getRenderable(lua_tostring(L,-1));
        lua_pushlightuserdata(L,rec);
    }
    return 1;					
}

int getCamera(lua_State* L)
{
    Camera* cam = (Core::getInstance())->getRenderManager()->getActiveScene()->getCamera();
    if(cam == NULL)
        std::cout << "There is not an active camera\n";
    else
        lua_pushlightuserdata(L,cam);
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

int flipX(lua_State* L)
{
    if( !lua_islightuserdata(L,-1))
        std::cout << "Parameter error, usage:\n" << "           Core.flipX(<renderable_pointer>)\n";
    else
    {
        Rectangle* aux = (Rectangle*) lua_touserdata(L,-1);
        aux->flipX();
    }
}

int flipY(lua_State* L)
{
    if( !lua_islightuserdata(L,-1))
        std::cout << "Parameter error, usage:\n" << "           Core.flipY(<renderable_pointer>)\n";
    else
    {
        Rectangle* aux = (Rectangle*) lua_touserdata(L,-1);
        aux->flipY();
    }
}

static const struct luaL_Reg core_functions [] = {
    {"getRenderable", getRenderable},
    {"getActiveCamera", getCamera},
    {"getScene", getScene},
    {"getLigth", getLigth},
    {"getX", getX},
    {"getY", getY},
    {"getZ", getZ},
    {"setX", setX},
    {"setY", setY},
    {"setZ", setZ},
    {"setCameraX", setCameraX},
    {"setCameraY", setCameraY},
    {"getCameraX", getCameraX},
    {"getCameraY", getCameraY},
    {"setAnimation", setAnimation},
    {"flipX", flipX},
    {"flipY", flipY},
    {NULL, NULL},
};

GLint luaopen_renderable(lua_State *L)
{
    luaL_newlib(L,core_functions);
    return 1;
}

GLvoid Renderablelua::openLUAFile(const GLchar* _filename)
{
    if(luaL_loadfile(L, _filename))
        std::cout << "\nError\n\n" << lua_tostring(L,-1) << "\n\n";
    luaopen_renderable(L);
    lua_setglobal(L,"Core");	
    if(lua_pcall(L,0,0,0))
        std::cout << "\nError\n\n" << lua_tostring(L,-1) << "\n\n";
    
}

GLvoid Renderablelua::update(GLfloat _tick)
{
    lua_getglobal(L,"update");
    lua_pushnumber(L,_tick);
    lua_pcall(L,1,1,0);
}

GLvoid Renderablelua::mouseMoved(GLfloat x,GLfloat y)
{
    lua_getglobal(L,"onMouseMoved");
    lua_pushinteger(L,x);
    lua_pushinteger(L,y);
    lua_pcall(L,2,1,0);
}

GLvoid Renderablelua::keyPressed()
{
    lua_getglobal(L,"onMouseKeyPressed");
    lua_pcall(L,1,1,0);
}

GLvoid Renderablelua::keyRelease()
{
    lua_getglobal(L,"onMouseKeyRelease");
    lua_pcall(L,1,1,0);
}

GLvoid Renderablelua::buttonDown(GLint)
{
    lua_getglobal(L,"onJoypadButtonDown");
    lua_pcall(L,1,1,0);
}

GLvoid Renderablelua::buttonUp(GLint)
{
    lua_getglobal(L,"onJoypadButtonUp");
    lua_pcall(L,1,1,0);
}

GLvoid Renderablelua::axisMove(GLint x ,GLint y)
{
    lua_getglobal(L,"onJoypadAxisMove");
    lua_pushinteger(L,x);
    lua_pushinteger(L,y);
    lua_pcall(L,2,1,0);
}

GLvoid Renderablelua::keyQdown()
{
    lua_getglobal(L,"keyQdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::keyWdown()
{
    lua_getglobal(L,"keyWdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::keyEdown()
{
    lua_getglobal(L,"keyEdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::keyRdown()
{
    lua_getglobal(L,"keyRdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::keyTdown()
{
    lua_getglobal(L,"keyTdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::keyYdown()
{
    lua_getglobal(L,"keyYdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::keyUdown()
{
    lua_getglobal(L,"keyUdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::keyIdown()
{
    lua_getglobal(L,"keyIdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::keyOdown()
{
    lua_getglobal(L,"keyOdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::keyPdown()
{
    lua_getglobal(L,"keyPdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::keyAdown()
{
    lua_getglobal(L,"keyAdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::keySdown()
{
    lua_getglobal(L,"keySdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::keyDdown()
{
    lua_getglobal(L,"keyDdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::keyFdown()
{
    lua_getglobal(L,"keyFdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::keyGdown()
{
    lua_getglobal(L,"keyGdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::keyHdown()
{
    lua_getglobal(L,"keyHdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::keyJdown()
{
    lua_getglobal(L,"keyJdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::keyKdown()
{
    lua_getglobal(L,"keyKdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::keyLdown()
{
    lua_getglobal(L,"keyLdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::keyZdown()
{
    lua_getglobal(L,"keyZdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::keyXdown()
{
    lua_getglobal(L,"keyXdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::keyCdown()
{
    lua_getglobal(L,"keyCdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::keyVdown()
{
    lua_getglobal(L,"keyVdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::keyBdown()
{
    lua_getglobal(L,"keyBdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::keyNdown()
{
    lua_getglobal(L,"keyNdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::keyMdown()
{
    lua_getglobal(L,"keyMdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::key1down()
{
    lua_getglobal(L,"key1down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::key2down()
{
    lua_getglobal(L,"key2down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::key3down()
{
    lua_getglobal(L,"key3down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::key4down()
{
    lua_getglobal(L,"key4down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::key5down()
{
    lua_getglobal(L,"key5down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::key6down()
{
    lua_getglobal(L,"key6down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::key7down()
{
    lua_getglobal(L,"key7down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::key8down()
{
    lua_getglobal(L,"key8down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::key9down()
{
    lua_getglobal(L,"key9down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::key0down()
{
    lua_getglobal(L,"key0down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyF1down()
{
    lua_getglobal(L,"keyF1down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::keyF2down()
{
    lua_getglobal(L,"keyF2down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyF3down()
{
    lua_getglobal(L,"keyF3down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyF4down()
{
    lua_getglobal(L,"keyF4down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyF5down()
{
    lua_getglobal(L,"keyF5down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyF6down()
{
    lua_getglobal(L,"keyF6down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyF7down()
{
    lua_getglobal(L,"keyF7down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyF8down()
{
    lua_getglobal(L,"keyF8down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyF9down()
{
    lua_getglobal(L,"keyF9down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyF10down()
{
    lua_getglobal(L,"keyF10down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyF11down()
{
    lua_getglobal(L,"keyF11down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyF12down()
{
    lua_getglobal(L,"keyF12down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyENTERdown()
{
    lua_getglobal(L,"keyENTERdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyESCAPEdown()
{
    lua_getglobal(L,"keyESCAPEdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keySPACEdown()
{
    lua_getglobal(L,"keySPACEdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyTABdown()
{
    lua_getglobal(L,"keyTABdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyBLOCKMAYdown()
{
    lua_getglobal(L,"keyBLOCKMAYdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyLEFTSHIFTdown()
{
    lua_getglobal(L,"keyLEFTSHIFTdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyLEFTCTRdown()
{
    lua_getglobal(L,"keyLEFTCTRdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyLEFTALTdown()
{
    lua_getglobal(L,"keyLEFTALTdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyRIGTHSHIFTdown()
{
    lua_getglobal(L,"keyRIGTHSHIFTdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyRIGTHCTRdown()
{
    lua_getglobal(L,"keyRIGTHCTRdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyRIGTHALTdown()
{
    lua_getglobal(L,"keyRIGTHALTdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyBACKSPACEdown()
{
    lua_getglobal(L,"keyBACKSPACEdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyARROWUPdown()
{
    lua_getglobal(L,"keyARROWUPdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyARROWDOWNdown()
{
    lua_getglobal(L,"keyARROWDOWNdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::keyARROWLEFTdown()
{
    lua_getglobal(L,"keyARROWLEFTdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyARROWRIGHTdown()
{
    lua_getglobal(L,"keyARROWRIGHTdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPAD1down()
{
    lua_getglobal(L,"keyNUMPAD1down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPAD2down()
{
    lua_getglobal(L,"keyNUMPAD2down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPAD3down()
{
    lua_getglobal(L,"keyNUMPAD3down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPAD4down()
{
    lua_getglobal(L,"keyNUMPAD4down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPAD5down()
{
    lua_getglobal(L,"keyNUMPAD5down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPAD6down()
{
    lua_getglobal(L,"keyNUMPAD6down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPAD7down()
{
    lua_getglobal(L,"keyNUMPAD7down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPAD8down()
{
    lua_getglobal(L,"keyNUMPAD8down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPAD9down()
{
    lua_getglobal(L,"keyNUMPAD9down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPAD0down()
{
    lua_getglobal(L,"keyNUMPAD0down");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPADPLUSdown()
{
    lua_getglobal(L,"keyNUMPADPLUSdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPADMINUSdown()
{
    lua_getglobal(L,"keyNUMPADMINUSdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPADSUBdown()
{
    lua_getglobal(L,"keyNUMPADSUBdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPADMULdown()
{
    lua_getglobal(L,"keyNUMPADMULdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPADENTERdown()
{
    lua_getglobal(L,"keyNUMPADENTERdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPADDOTdown()
{
    lua_getglobal(L,"keyNUMPADDOTdown");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::keyQup()
{
    lua_getglobal(L,"keyQup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}

GLvoid Renderablelua::keyWup()
{
    lua_getglobal(L,"keyWup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyEup()
{
    lua_getglobal(L,"keyEup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyRup()
{
    lua_getglobal(L,"keyRup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyTup()
{
    lua_getglobal(L,"keyTup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyYup()
{
    lua_getglobal(L,"keyYup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyUup()
{
    lua_getglobal(L,"keyUup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyIup()
{
    lua_getglobal(L,"keyIup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyOup()
{
    lua_getglobal(L,"keyOup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyPup()
{
    lua_getglobal(L,"keyPup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyAup()
{
    lua_getglobal(L,"keyAup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keySup()
{
    lua_getglobal(L,"keySup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyDup()
{
    lua_getglobal(L,"keyDup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyFup()
{
    lua_getglobal(L,"keyFup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyGup()
{
    lua_getglobal(L,"keyGup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyHup()
{
    lua_getglobal(L,"keyHup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyJup()
{
    lua_getglobal(L,"keyJup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyKup()
{
    lua_getglobal(L,"keyKup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyLup()
{
    lua_getglobal(L,"keyLup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyZup()
{
    lua_getglobal(L,"keyZup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyXup()
{
    lua_getglobal(L,"keyXup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyCup()
{
    lua_getglobal(L,"keyCup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyVup()
{
    lua_getglobal(L,"keyVup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyBup()
{
    lua_getglobal(L,"keyBup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNup()
{
    lua_getglobal(L,"keyNup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyMup()
{
    lua_getglobal(L,"keyMup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::key1up()
{
    lua_getglobal(L,"key1up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::key2up()
{
    lua_getglobal(L,"key2up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::key3up()
{
    lua_getglobal(L,"key3up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::key4up()
{
    lua_getglobal(L,"key4up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::key5up()
{
    lua_getglobal(L,"key5up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::key6up()
{
    lua_getglobal(L,"key6up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::key7up()
{
    lua_getglobal(L,"key7up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::key8up()
{
    lua_getglobal(L,"key8up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::key9up()
{
    lua_getglobal(L,"key9up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::key0up()
{
    lua_getglobal(L,"key0up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyF1up()
{
    lua_getglobal(L,"keyF1up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyF2up()
{
    lua_getglobal(L,"keyF2up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyF3up()
{
    lua_getglobal(L,"keyF3up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyF4up()
{
    lua_getglobal(L,"keyF4up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyF5up()
{
    lua_getglobal(L,"keyF5up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyF6up()
{
    lua_getglobal(L,"keyF6up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyF7up()
{
    lua_getglobal(L,"keyF7up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyF8up()
{
    lua_getglobal(L,"keyF8up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyF9up()
{
    lua_getglobal(L,"keyF9up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyF10up()
{
    lua_getglobal(L,"keyF10up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyF11up()
{
    lua_getglobal(L,"keyF11up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyF12up()
{
    lua_getglobal(L,"keyF12up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyENTERup()
{
    lua_getglobal(L,"keyENTERup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyESCAPEup()
{
    lua_getglobal(L,"keyESCAPEup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keySPACEup()
{
    lua_getglobal(L,"keySPACEup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyTABup()
{
    lua_getglobal(L,"keyTABup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyBLOCKMAYup()
{
    lua_getglobal(L,"keyBLOCKMAYup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyLEFTSHIFTup()
{
    lua_getglobal(L,"keyLEFTSHIFTup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyLEFTCTRup()
{
    lua_getglobal(L,"keyLEFTCTRup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyLEFTALTup()
{
    lua_getglobal(L,"keyLEFTALTup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyRIGTHSHIFTup()
{
    lua_getglobal(L,"keyRIGTHSHIFTup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyRIGTHCTRup()
{
    lua_getglobal(L,"keyRIGTHCTRup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyRIGTHALTup()
{
    lua_getglobal(L,"keyRIGTHALTup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyBACKSPACEup()
{
    lua_getglobal(L,"keyBACKSPACEup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyARROWUPup()
{
    lua_getglobal(L,"keyARROWUPup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyARROWDOWNup()
{
    lua_getglobal(L,"keyARROWDOWNup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyARROWLEFTup()
{
    lua_getglobal(L,"keyARROWLEFTup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyARROWRIGHTup()
{
    lua_getglobal(L,"keyARROWRIGHTup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPAD1up()
{
    lua_getglobal(L,"keyNUMPAD1up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPAD2up()
{
    lua_getglobal(L,"keyNUMPAD2up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPAD3up()
{
    lua_getglobal(L,"keyNUMPAD3up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPAD4up()
{
    lua_getglobal(L,"keyNUMPAD4up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPAD5up()
{
    lua_getglobal(L,"keyNUMPAD5up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPAD6up()
{
    lua_getglobal(L,"keyNUMPAD6up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPAD7up()
{
    lua_getglobal(L,"keyNUMPAD7up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPAD8up()
{
    lua_getglobal(L,"keyNUMPAD8up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPAD9up()
{
    lua_getglobal(L,"keyNUMPAD9up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPAD0up()
{
    lua_getglobal(L,"keyNUMPAD0up");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPADPLUSup()
{
    lua_getglobal(L,"keyNUMPADPLUSup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPADMINUSup()
{
    lua_getglobal(L,"keyNUMPADMINUSup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPADSUBup()
{
    lua_getglobal(L,"keyNUMPADSUBup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPADMULup()
{
    lua_getglobal(L,"keyNUMPADMULup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPADENTERup()
{
    lua_getglobal(L,"keyNUMPADENTERup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyNUMPADDOTup()
{
    lua_getglobal(L,"keyNUMPADDOTup");
    if(lua_pcall(L,0,0,0) != LUA_OK)
        std::cout << lua_tostring(L,-1) << "\n";
}
GLvoid Renderablelua::keyQpressed(){ }
GLvoid Renderablelua::keyWpressed(){ }
GLvoid Renderablelua::keyEpressed(){ }
GLvoid Renderablelua::keyRpressed(){ }
GLvoid Renderablelua::keyTpressed(){ }
GLvoid Renderablelua::keyYpressed(){ }
GLvoid Renderablelua::keyUpressed(){ }
GLvoid Renderablelua::keyIpressed(){ }
GLvoid Renderablelua::keyOpressed(){ }
GLvoid Renderablelua::keyPpressed(){ }
GLvoid Renderablelua::keyApressed(){ }
GLvoid Renderablelua::keySpressed(){ }
GLvoid Renderablelua::keyDpressed(){ }
GLvoid Renderablelua::keyFpressed(){ }
GLvoid Renderablelua::keyGpressed(){ }
GLvoid Renderablelua::keyHpressed(){ }
GLvoid Renderablelua::keyJpressed(){ }
GLvoid Renderablelua::keyKpressed(){ }
GLvoid Renderablelua::keyLpressed(){ }
GLvoid Renderablelua::keyZpressed(){ }
GLvoid Renderablelua::keyXpressed(){ }
GLvoid Renderablelua::keyCpressed(){ }
GLvoid Renderablelua::keyVpressed(){ }
GLvoid Renderablelua::keyBpressed(){ }
GLvoid Renderablelua::keyNpressed(){ }
GLvoid Renderablelua::keyMpressed(){ }
GLvoid Renderablelua::key1pressed(){ }
GLvoid Renderablelua::key2pressed(){ }
GLvoid Renderablelua::key3pressed(){ }
GLvoid Renderablelua::key4pressed(){ }
GLvoid Renderablelua::key5pressed(){ }
GLvoid Renderablelua::key6pressed(){ }
GLvoid Renderablelua::key7pressed(){ }
GLvoid Renderablelua::key8pressed(){ }
GLvoid Renderablelua::key9pressed(){ }
GLvoid Renderablelua::key0pressed(){ }
GLvoid Renderablelua::keyF1pressed(){ }
GLvoid Renderablelua::keyF2pressed(){ }
GLvoid Renderablelua::keyF3pressed(){ }
GLvoid Renderablelua::keyF4pressed(){ }
GLvoid Renderablelua::keyF5pressed(){ }
GLvoid Renderablelua::keyF6pressed(){ }
GLvoid Renderablelua::keyF7pressed(){ }
GLvoid Renderablelua::keyF8pressed(){ }
GLvoid Renderablelua::keyF9pressed(){ }
GLvoid Renderablelua::keyF10pressed(){ }
GLvoid Renderablelua::keyF11pressed(){ }
GLvoid Renderablelua::keyF12pressed(){ }
GLvoid Renderablelua::keyENTERpressed(){ }
GLvoid Renderablelua::keyESCAPEpressed(){ }
GLvoid Renderablelua::keySPACEpressed(){ }
GLvoid Renderablelua::keyTABpressed(){ }
GLvoid Renderablelua::keyBLOCKMAYpressed(){ }
GLvoid Renderablelua::keyLEFTSHIFTpressed(){ }
GLvoid Renderablelua::keyLEFTCTRpressed(){ }
GLvoid Renderablelua::keyLEFTALTpressed(){ }
GLvoid Renderablelua::keyRIGTHSHIFTpressed(){ }
GLvoid Renderablelua::keyRIGTHCTRpressed(){ }
GLvoid Renderablelua::keyRIGTHALTpressed(){ }
GLvoid Renderablelua::keyBACKSPACEpressed(){ }
GLvoid Renderablelua::keyARROWUPpressed(){ }
GLvoid Renderablelua::keyARROWDOWNpressed(){ }
GLvoid Renderablelua::keyARROWLEFTpressed(){ }
GLvoid Renderablelua::keyARROWRIGHTpressed(){ }
GLvoid Renderablelua::keyNUMPAD1pressed(){ }
GLvoid Renderablelua::keyNUMPAD2pressed(){ }
GLvoid Renderablelua::keyNUMPAD3pressed(){ }
GLvoid Renderablelua::keyNUMPAD4pressed(){ }
GLvoid Renderablelua::keyNUMPAD5pressed(){ }
GLvoid Renderablelua::keyNUMPAD6pressed(){ }
GLvoid Renderablelua::keyNUMPAD7pressed(){ }
GLvoid Renderablelua::keyNUMPAD8pressed(){ }
GLvoid Renderablelua::keyNUMPAD9pressed(){ }
GLvoid Renderablelua::keyNUMPAD0pressed(){ }
GLvoid Renderablelua::keyNUMPADPLUSpressed(){ }
GLvoid Renderablelua::keyNUMPADMINUSpressed(){ }
GLvoid Renderablelua::keyNUMPADSUBpressed(){ }
GLvoid Renderablelua::keyNUMPADMULpressed(){ }
GLvoid Renderablelua::keyNUMPADENTERpressed(){ }
GLvoid Renderablelua::keyNUMPADDOTpressed(){ }