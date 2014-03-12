#ifndef RENDER_ENGINE_H
#define	RENDER_ENGINE_H

#include <map>
#include <string>    
#include "../Unnivelmas_conf.h"
#include "KKMeshLoader.h"

class SDL_Window;
class SDL_VideoInfo;
class SDL_Renderer;

namespace kaikai
{
        class Renderable;
        class Scene;
        class Material;
        class KKMeshLoader;
        
	class Render
	{
		private: 
                        Scene* active_scene;
                        KKMeshLoader* kk_mesh_loader;
                        SDL_Window* main_window;
                        SDL_Rect display_info;
                        SDL_Renderer* renderer;
                        SDL_GLContext glRenderContext, glThreadContext;
                        bool end_flag;
                        GLuint vbo[100];
                        GLuint uvbo[100];
                        GLint vbo_count, uvbo_count;
                        
		public:
                        Render();
                        virtual ~Render();	

                        GLfloat getRendererX();
                        GLfloat getRendererY();
                        GLvoid loop();
                        GLvoid stop();
                        GLvoid addRenderable(const GLchar*,Renderable*);
                        GLvoid scaleObject(const GLchar*, GLfloat);
                        GLvoid moveObject(const GLchar*, GLfloat,GLfloat);
                        GLvoid activeScene(Scene*);
                        Scene* getActiveScene();
                        GLint getNextVertexBufferObjectNumber();
                        GLint getNextUVBufferObjectNumber();
                        SDL_GLContext getThreadContext();
                        SDL_Window* getWindow();
                        GLvoid loadKKModel(const GLchar*);
	};
}; // Close Namespace Tag
#endif // RENDER_ENGINE_H