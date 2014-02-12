
TEXTURE_INCLUDE= -Iinclude

# libscene.a

all: texture

font.o: 
	g++ -O2 $(TEXTURE_INCLUDE) -c src/Texture/Font.cpp -o build/Texture/font.o

textmanager.o: 
	g++ -O2 $(TEXTURE_INCLUDE) -c src/Texture/TextManager.cpp -o build/Texture/textmanager.o

texture.o: 
	g++ -O2 $(TEXTURE_INCLUDE) -c src/Texture/Texture.cpp -o build/Texture/texture.o

texturemanager.o: 
	g++ -O2 $(TEXTURE_INCLUDE) -c src/Texture/TextureManager.cpp -o build/Texture/texturemanager.o

texture: texture.o texturemanager.o textmanager.o font.o
	ar -r  -s build/lib/libtexture.a build/Texture/texture.o build/Texture/texturemanager.o build/Texture/textmanager.o build/Texture/font.o
	
# end of libscene.a