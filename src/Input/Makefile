
INPUT_INCLUDE= -Iinclude

# libinput.a

all: input

josticklistener.o: 
	g++ -O2 $(INPUT_INCLUDE) -c src/Input/JoystickListener.cpp -o build/Input/josticklistener.o 

keyboardlistener.o: 
	g++ -O2 $(INPUT_INCLUDE) -c src/Input/KeyBoardListener.cpp -o build/Input/keyboardlistener.o 

keyboardmanager.o: 
	g++ -O2 $(INPUT_INCLUDE) -c src/Input/KeyBoardManager.cpp -o build/Input/keyboardmanager.o 

joystickmanager.o: 
	g++ -O2 $(INPUT_INCLUDE) -c src/Input/JostickManager.cpp -o build/Input/joystickmanager.o 

mouseeventhanler.o: 
	g++ -O2 $(INPUT_INCLUDE) -c src/Input/MouseEventListener.cpp -o build/Input/mouseeventlistener.o 

mousehanlerinput.o: 
	g++ -O2 $(INPUT_INCLUDE) -c src/Input/MouseInputHandler.cpp -o build/Input/mouseinputhandler.o 
	
input.o: 
	g++ -O2 $(INPUT_INCLUDE) -c src/Input/Input.cpp -o build/Input/input.o 

input: input.o mousehanlerinput.o mouseeventhanler.o joystickmanager.o josticklistener.o keyboardmanager.o keyboardlistener.o
	ar -r  -s build/lib/libinput.a build/Input/input.o build/Input/mouseinputhandler.o build/Input/mouseeventlistener.o build/Input/joystickmanager.o build/Input/josticklistener.o build/Input/keyboardmanager.o build/Input/keyboardlistener.o 

# end of libinput.a