
COLLISION_INCLUDE= -Iinclude

#libcollision.a

all: collision

rectangleshape.o: 
	g++ -O2 $(COLLISION_INCLUDE) -c src/Collision/RectangleShape.cpp -o build/Collision/rectangleshape.o

shape.o: 
	g++ -O2 $(COLLISION_INCLUDE) -c src/Collision/Shape.cpp -o build/Collision/shape.o

collisionmanager.o: 
	g++ -O2 $(COLLISION_INCLUDE) -c src/Collision/CollisionManager.cpp -o build/Collision/collisionmanager.o

collision: rectangleshape.o shape.o collisionmanager.o
	ar -r -s build/lib/libcollision.a build/Collision/collisionmanager.o build/Collision/rectangleshape.o build/Collision/shape.o

#END libcollision.a