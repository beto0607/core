
# INCLUDES
SDL_INCLUDE= -Iexternal/include -Iinclude

# LIBRARIES
ENGINE_LIB= -Lexternal/lib

ifeq ($(OS),Windows_NT)
    LINK_LIBRARY= -lmingw32 -lSDL2main -lSDL2_mixer -lSDL2_ttf -lSDL2_net -lSDL2 -lSDL2.dll -lopengl32 -lglu32  -lglew32 -lfreeimage
    EXTENSION= .exe
    all: directories copy_dll core input collision animation audio renderer scene command net engine example animation_example audio_example net_client_example net_server_example demo_example
else
    EXTENSION=
    all: directories engine example animation_example audio_example net_client_example net_server_example demo_example
endif
	
# MAKE creation folders
	
root_folder:
	mkdir build
	mkdir build/lib	
	mkdir build/Core
	mkdir build/Scene
	mkdir build/Shader
	mkdir build/Texture
	mkdir build/Renderer	
	mkdir build/Log	
	mkdir build/Input
	mkdir build/Collision
	mkdir build/examples
	mkdir build/Command
	mkdir build/Animation
	mkdir build/Networking
	mkdir build/Audio
	mkdir build/examples/prueba
	mkdir build/examples/animation
	mkdir build/examples/audio
	mkdir build/examples/net
	mkdir build/examples/demo
	mkdir build/examples/prueba/resources
	mkdir build/examples/prueba/resources/shaders
		
copy_dll: 
	cp -R resources/ build/examples/prueba/
	cp -R resources/ build/examples/animation/
	cp -R resources/ build/examples/audio/
	cp dependencies/SDL2-2.0.1/build/.libs/SDL2.dll build/examples/prueba/
	cp dependencies/SDL2-2.0.1/build/.libs/SDL2.dll build/examples/animation/
	cp dependencies/SDL2-2.0.1/build/.libs/SDL2.dll build/examples/audio/
	cp dependencies/SDL2_mixer-2.0.0/build/.libs/SDL2_mixer.dll build/examples/prueba/
	cp dependencies/SDL2_mixer-2.0.0/build/.libs/SDL2_mixer.dll build/examples/animation/
	cp dependencies/SDL2_mixer-2.0.0/build/.libs/SDL2_mixer.dll build/examples/audio/
	cp dependencies/FreeImage/FreeImage.dll build/examples/prueba/
	cp dependencies/FreeImage/FreeImage.dll build/examples/animation/
	cp dependencies/FreeImage/FreeImage.dll build/examples/audio/
	cp dependencies/glew-1.10.0/lib/glew32.dll build/examples/prueba/
	cp dependencies/glew-1.10.0/lib/glew32.dll build/examples/animation/
	cp dependencies/glew-1.10.0/lib/glew32.dll build/examples/audio/
	
build_libraries:
	make -f src/Animation/Makefile
	make -f src/Audio/Makefile
	make -f src/Collision/Makefile
	make -f src/Command/Makefile
	make -f src/Core/Makefile
	make -f src/External/Makefile
	make -f src/Input/Makefile
	make -f src/Log/Makefile
	make -f src/Networking/Makefile
	make -f src/Renderer/Makefile
	make -f src/Scene/Makefile
	make -f src/Shader/Makefile
	make -f src/Texture/Makefile
	
engine.a: build_libraries
	ar -r  -s build/lib/libengine.a build/Animation/*.o build/Audio/*.o build/Collision/*.o build/Command/*.o build/Core/*.o build/Input/*.o build/Log/*.o build/Networking/*.o build/Renderer/*.o build/Scene/*.o build/Shader/*.o build/Texture/*.o

engine: engine.a
	
ifeq ($(OS),Windows_NT)

directories: root_folder

else

directories: root_folder

endif
	
# Example Collision
	
ejemplo_pruebashader.o:
	g++ -O2 $(SDL_INCLUDE) -c examples/prueba/shader/PruebaShader.cpp -o build/examples/prueba/pruebashader.o 

ejemplo_simplematerial.o: 
	g++ -O2 $(SDL_INCLUDE) -c examples/prueba/material/SimpleMaterial.cpp -o build/examples/prueba/simplematerial.o 
	
example_main.o:
	g++ -O2 $(SDL_INCLUDE) -c examples/prueba/main.cpp -o build/examples/prueba/main.o 
	
example: example_main.o ejemplo_simplematerial.o ejemplo_pruebashader.o
	g++ -Lbuild/lib -Lexternal/lib -Iexternal/include build/examples/prueba/main.o build/examples/prueba/pruebashader.o build/examples/prueba/simplematerial.o -o build/examples/prueba/ejemplo -s -lengine -lSDL2_mixer -lSDL2_net -lSDL2_image -lGL -lGLU `external/sdl2-config --static-libs` -lSDL2_ttf -lfreetype

# End Example

# Example Animation

animation_material.o:
	g++ -O2 $(SDL_INCLUDE) -c examples/animation/material/SimpleMaterial.cpp -o build/examples/animation/simplematerial.o 

animation_shader.o:
	g++ -O2 $(SDL_INCLUDE) -c examples/animation/shader/AnimationShader.cpp -o build/examples/animation/animationshader.o 

animation_ninja.o:
	g++ -O2 $(SDL_INCLUDE) -c examples/animation/class/AnimatedNinja.cpp -o build/examples/animation/ninja.o 

animation_main.o:
	g++ -O2 $(SDL_INCLUDE) -c examples/animation/main.cpp -o build/examples/animation/main.o 

animation_example: animation_main.o animation_ninja.o animation_shader.o animation_material.o
	g++ -Lbuild/lib -Lexternal/lib -Iexternal/include build/examples/animation/main.o build/examples/animation/ninja.o build/examples/animation/animationshader.o build/examples/animation/simplematerial.o -o build/examples/animation/animation -s -lengine -lSDL2_mixer -lSDL2_net -lSDL2_image -lGL -lGLU `external/sdl2-config --static-libs` -lSDL2_ttf -lfreetype
# end Example Animation

# Example Audio

audio_main.o:
	g++ -O2 $(SDL_INCLUDE) -c examples/audio/main.cpp -o build/examples/audio/main.o 

audio_example: audio_main.o 
	g++ -Lbuild/lib -Lexternal/lib -Iexternal/include  build/examples/audio/main.o -o build/examples/audio/audio -s -lengine -lSDL2_mixer -lSDL2_net -lSDL2_image -lGL -lGLU `external/sdl2-config --static-libs` -lSDL2_ttf -lfreetype
# end Example Animation

# Example Networking

net_client.o:
	g++ -O2 $(SDL_INCLUDE) -c examples/net/client.cpp -o build/examples/net/client.o 

net_server.o:
	g++ -O2 $(SDL_INCLUDE) -c examples/net/server.cpp -o build/examples/net/server.o 

net_client_example: net_client.o
	g++ -Lbuild/lib -Lexternal/lib -Iexternal/include build/examples/net/client.o -o build/examples/net/netclient -s -lengine -lSDL2_mixer -lSDL2_net -lSDL2_image -lGL -lGLU `external/sdl2-config --static-libs` -lSDL2_ttf -lfreetype

net_server_example: net_server.o
	g++ -Lbuild/lib -Lexternal/lib -Iexternal/include build/examples/net/server.o -o build/examples/net/netserver -s -lengine -lSDL2_mixer -lSDL2_net -lSDL2_image -lGL -lGLU `external/sdl2-config --static-libs` -lSDL2_ttf -lfreetype
# end Example Networking

# Example Demo

player_demo.o:
	g++ -O2 $(SDL_INCLUDE) -c examples/demo/class/Player.cpp -o build/examples/demo/player.o 
demo_main.o:
	g++ -O2 $(SDL_INCLUDE) -c examples/demo/main.cpp -o build/examples/demo/main.o 
demo_material.o:
	g++ -O2 $(SDL_INCLUDE) -c examples/demo/material/SimpleMaterial.cpp -o build/examples/demo/simplematerial.o 
demo_shader.o:
	g++ -O2 $(SDL_INCLUDE) -c examples/demo/shader/AnimationShader.cpp -o build/examples/demo/animationshader.o 

demo_example: demo_main.o player_demo.o demo_material.o demo_shader.o
	g++ -Lbuild/lib -Lexternal/lib -Iexternal/include build/examples/demo/main.o build/examples/demo/simplematerial.o build/examples/demo/animationshader.o build/examples/demo/player.o -o build/examples/demo/testdemo -s -lengine -lSDL2_mixer -lSDL2_net -lSDL2_image -lGL -lGLU `external/sdl2-config --static-libs` -lSDL2_ttf -lfreetype

# end Example Demo

clean: 
	rm -R build
