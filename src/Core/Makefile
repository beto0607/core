
CORE_INCLUDE= -Iinclude

# libcore.a 

all: core

clock.o: 
	g++ -O2 $(CORE_INCLUDE) -c src/Core/Clock.cpp -o build/Core/clock.o

meshloader.o: 
	g++ -O2 $(CORE_INCLUDE) -c src/Core/MeshLoader.cpp -o build/Core/meshloader.o

core.o: 
	g++ -O2 $(CORE_INCLUDE) -c src/Core/Core.cpp -o build/Core/core.o

timeeventlistener.o: 
	g++ -O2 $(CORE_INCLUDE) -c src/Core/TimeEventListener.cpp -o build/Core/timeeventlistener.o
	
core: core.o clock.o timeeventlistener.o meshloader.o
	ar -r  -s build/lib/libcore.a build/Core/core.o build/Core/clock.o build/Core/timeeventlistener.o build/Core/meshloader.o

#END libcore.a