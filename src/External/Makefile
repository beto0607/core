
GLEW_INCLUDE= -Iexternal/include
XML_INCLUDE= -Iinclude/external

all: external

# glew.o 
glew.o:
	g++ $(GLEW_INCLUDE) -o build/Core/glew.o -c src/External/glew.c

tinyxml2.o:
	g++ -O2 $(XML_INCLUDE) -o build/Core/tinyxml2.o -c src/External/tinyxml2.cpp
#END glew.o 

external: glew.o tinyxml2.o
	ar -r  -s build/lib/external.a build/Core/tinyxml2.o build/Core/glew.o