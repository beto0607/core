
COMMAND_INCLUDE= -Iinclude
SDL_CONFIG= `../../external/sdl2-config --static-libs`

# libcommand.a

all: command

commandmanager.o: 
	g++ -O2 $(COMMAND_INCLUDE) -c src/Command/CommandManager.cpp -o build/Command/commandmanager.o
	
command.o: 
	g++ -O2 $(COMMAND_INCLUDE) -c src/Command/Command.cpp -o build/Command/command.o

load.o: 
	g++ -O2 $(COMMAND_INCLUDE) -c src/Command/Cargar.cpp -o build/Command/load.o

setfps.o: 
	g++ -O2 $(COMMAND_INCLUDE) -c src/Command/SetFps.cpp -o build/Command/setfps.o

create_rectangle.o: 
	g++ -O2 $(COMMAND_INCLUDE) -c src/Command/RectangleCommand.cpp -o build/Command/rectanglecommand.o

salir.o: 
	g++ -O2 $(COMMAND_INCLUDE) -c src/Command/Salir.cpp -o build/Command/salir.o

mostrarfps.o: 
	g++ -O2 $(COMMAND_INCLUDE) -c src/Command/MostrarFPS.cpp -o build/Command/mostrarfps.o

move.o: 
	g++ -O2 $(COMMAND_INCLUDE) -c src/Command/Move.cpp -o build/Command/move.o

create.o: 
	g++ -O2 $(COMMAND_INCLUDE) -c src/Command/Create.cpp -o build/Command/crear.o

scale.o: 
	g++ -O2 $(COMMAND_INCLUDE) -c src/Command/Escalar.cpp -o build/Command/escale.o

savescene.o:
	g++ -O2 $(COMMAND_INCLUDE) -c src/Command/SaveScene.cpp -o build/Command/savescene.o

command: commandmanager.o command.o load.o create_rectangle.o salir.o mostrarfps.o move.o create.o scale.o setfps.o savescene.o
	ar -r  -s build/lib/libcommand.a build/Command/command.o build/Command/salir.o build/Command/load.o build/Command/move.o build/Command/escale.o build/Command/commandmanager.o build/Command/mostrarfps.o build/Command/crear.o build/Command/rectanglecommand.o build/Command/setfps.o build/Command/savescene.o

#end of libcommand.a