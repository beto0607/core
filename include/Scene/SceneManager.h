/* 
 * File:   SceneManager.h
 * Author: francisco
 *
 * Created on 12 de diciembre de 2013, 17:43
 */

#ifndef SCENEMANAGER_H
#define	SCENEMANAGER_H

#include "../Unnivelmas_conf.h"
#include <map>
#include <string>

namespace unnivelmas
{
    class Scene;
    
    class SceneManager {
    public:
        SceneManager();
        virtual ~SceneManager();
        
        GLvoid createScene(const GLchar*);
        GLvoid activeScene(const GLchar*);
        
    private:
        std::map<std::string, Scene*> scenes;
        };
}// end namespace
#endif	/* SCENEMANAGER_H */

