
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
    all: directories engine 
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
	mkdir build/Scripting
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
	make -f src/Scripting/Makefile
	
engine: build_libraries
	ar -r  -s build/lib/libengine.a build/Animation/*.o build/Audio/*.o build/Collision/*.o build/Command/*.o build/Core/*.o build/Input/*.o build/Log/*.o build/Networking/*.o build/Renderer/*.o build/Scene/*.o build/Shader/*.o build/Texture/*.o build/Scripting/*.o

ifeq ($(OS),Windows_NT)

directories: root_folder

else

directories: root_folder

endif

clean: 
	rm -R build
