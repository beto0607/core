/* 
 * File:   Scene.h
 * Author: francisco
 *
 * Created on 12 de diciembre de 2013, 17:45
 */

#ifndef SCENE_H
#define	SCENE_H

#include <map>
#include <string>
#include "../Unnivelmas_conf.h"

namespace kaikai{

    class Camera;
    class Ligth;
    class RenderableBuffer;
    class ProjectionMatrix;
    class Renderable;
    class Material;
    class Shape;
    class CollisionManager;
    class Renderable;

    class Scene {
    public:
        Scene();
        virtual ~Scene();
        
        virtual GLvoid drawBuffer();
        virtual GLvoid addRenderable(const GLchar*,Renderable*);
        virtual GLvoid addCollider(Shape*);
        virtual GLvoid addCollidable(Shape*);
        virtual GLvoid scaleObject(const GLchar*, GLfloat);
        virtual GLvoid moveObject(const GLchar*, GLfloat,GLfloat);  
        virtual Renderable* getRenderable(const GLchar*);
                        
    protected:
        Camera* camera;
        CollisionManager* collision_manager;
        std::map<std::string,Renderable*>* renderables;
        std::map<std::string, Ligth*> ligths;
        glm::mat4 projection_matrix;
        RenderableBuffer* buffer;
        
};
}
#endif	/* SCENE_H */

