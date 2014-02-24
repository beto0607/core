
SCRIPTING_INCLUDE= -Iinclude

# librender.a
all: script	
	
renderlua: 
	g++ -O2 $(SCRIPTING_INCLUDE) -c src/Scripting/Renderablelua.cpp -o build/Scripting/renderablelua.o

script: renderlua
	ar -r  -s build/lib/libscripting.a build/Scripting/renderablelua.o 

# end of librender.a