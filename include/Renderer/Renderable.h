
#ifndef RENDERABLE_H
#define	RENDERABLE_H

#include "../Unnivelmas_conf.h"
#include "../../external/include/glm/glm.hpp"
#include <string>

namespace unnivelmas
{
    class Shape;
    class Animation;
    
	class Renderable
	{
		public:
			
                        Renderable();
                        virtual ~Renderable();
                    
                        GLfloat getX();
                        GLvoid setX(GLfloat);

                        GLfloat getY();
                        GLvoid setY(GLfloat);
                        
                        GLfloat getZ();
                        GLvoid setZ(GLfloat);

                        GLvoid scale(GLfloat);
                        GLfloat* getScale();

                        GLvoid move(GLfloat, GLfloat);
                        GLvoid move(GLfloat, GLfloat, GLfloat);
                        
                        GLfloat* getPosition();
                        GLfloat* getRotation();
                        
                        GLfloat* getProjectionMatrix();
                        
                        GLfloat getTop();
                        GLfloat getBottom();
                        GLfloat getRigth();
                        GLfloat getLeft();
                        
                        glm::vec2 getTopRigth();
                        glm::vec2 getTopLeft();
                        glm::vec2 getBottomRigth();
                        glm::vec2 getBottomLeft();
                        GLfloat getRadius();
                        GLfloat getHeight();
                        GLfloat getWidth();
                        GLuint getVertexBufferID();
                        GLuint getUVBufferID();
                        
                        GLvoid setName(std::string);
                        std::string getName();
                        
                        virtual GLvoid topCollision(Renderable*);
                        virtual GLvoid bottomCollision(Renderable*);
                        virtual GLvoid leftCollision(Renderable*);
                        virtual GLvoid rightCollision(Renderable*);
                        
                        Shape* getShape();
                        
                        GLvoid setAnimation(Animation*);
                        GLvoid setUVCoordinates(GLfloat*);
        
                        GLvoid drawRenderable();
                        GLvoid play(const GLchar*);
                        virtual GLvoid draw()=0;
                        
                protected:  
                        GLuint buffer_id, uv_id;
                        GLuint vertex_buffer_id;
                        GLfloat width, heigth, radius;
                        Shape* shape;
                        Animation* animation;
                        std::string name;
                        glm::mat3 position_matrix;
                        glm::mat3 angle_matrix;
                        glm::mat3 scale_matrix;
                        glm::mat4 projection_matrix;
                        glm::mat4 viewport_matrix;
            
	};
}; // Close Namespace Tag
#endif