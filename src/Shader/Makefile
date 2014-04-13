
SHADER_INCLUDE= -Iinclude

# libscene.a

all: shader

shader_text.o: 
	g++ -O2 $(SHADER_INCLUDE) -c src/Shader/TextShader.cpp -o build/Shader/textshader.o 

shader_bind_vertex.o: 
	g++ -O2 $(SHADER_INCLUDE) -c src/Shader/BindVertexShader.cpp -o build/Shader/shader_bind_vertex.o 

shader_null.o: 
	g++ -O2 $(SHADER_INCLUDE) -c src/Shader/ShaderNull.cpp -o build/Shader/shadernull.o 

shader_3d_null.o: 
	g++ -O2 $(SHADER_INCLUDE) -c src/Shader/Shader3DNull.cpp -o build/Shader/shader3dnull.o 

shader_sprite.o: 
	g++ -O2 $(SHADER_INCLUDE) -c src/Shader/SpriteShader.cpp -o build/Shader/spriteshader.o 
	
shader.o: 
	g++ -O2 $(SHADER_INCLUDE) -c src/Shader/Shader.cpp -o build/Shader/shader.o 

shadermanager.o: 
	g++ -O2 $(SHADER_INCLUDE) -c src/Shader/ShaderManager.cpp -o build/Shader/shadermanager.o
	
shader: shader_null.o shader_text.o shader.o shadermanager.o shader_sprite.o shader_3d_null.o shader_bind_vertex.o
	ar -r  -s build/lib/libshader.a build/Shader/shadernull.o build/Shader/shader.o build/Shader/shadermanager.o build/Shader/shader_bind_vertex.o build/Shader/textshader.o build/Shader/shader3dnull.o build/Shader/spriteshader.o
	
# end of libscene.a