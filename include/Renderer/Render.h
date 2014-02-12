#ifndef RENDER_ENGINE_H
#define	RENDER_ENGINE_H

#include <map>
#include <string>    
#include "../Unnivelmas_conf.h"

class SDL_Window;
class SDL_VideoInfo;
class SDL_Renderer;

namespace unnivelmas
{
        class Renderable;
        class Scene;
        class Material;
        
	class Render
	{
		private: 
                        Scene* active_scene;
                        SDL_Window* main_window;
                        SDL_VideoInfo* info;
                        SDL_Renderer* renderer;
                        bool end_flag;
		public:
                        Render();
                        virtual ~Render();	

                        GLvoid loop();
                        GLvoid stop();
                        GLvoid addRenderable(const GLchar*,Renderable*);
                        GLvoid scaleObject(const GLchar*, GLfloat);
                        GLvoid moveObject(const GLchar*, GLfloat,GLfloat);
                        GLvoid activeScene(Scene*);
                        Scene* getActiveScene();
	};
}; // Close Namespace Tag
#endif // RENDER_ENGINE_H