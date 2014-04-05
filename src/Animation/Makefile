#libanimation.a

ANIMATION_INCLUDE= -Iinclude
SDL_CONFIG= `../../external/sdl2-config --static-libs`

all: track.o sprite.o spriteanimation.o animation.o trackstatechanged.o trackstate.o skeleton.o boundvertex.o joint.o animation

joint.o: 
	g++ -O2 $(ANIMATION_INCLUDE) -c src/Animation/Joint.cpp -o build/Animation/joint.o 

boundvertex.o: 
	g++ -O2 $(ANIMATION_INCLUDE) -c src/Animation/Boundvertex.cpp -o build/Animation/boundvertex.o 
	
skeleton.o: 
	g++ -O2 $(ANIMATION_INCLUDE) -c src/Animation/Skeleton.cpp -o build/Animation/skeleton.o 

trackstate.o: 
	g++ -O2 $(ANIMATION_INCLUDE) -c src/Animation/TrackState.cpp -o build/Animation/trackstate.o 

trackstatechanged.o: 
	g++ -O2 $(ANIMATION_INCLUDE) -c src/Animation/TrackStateChanged.cpp -o build/Animation/trackstatechanged.o

sprite.o: 
	g++ -O2 $(ANIMATION_INCLUDE) -c src/Animation/Sprite.cpp -o build/Animation/sprite.o

track.o: 
	g++ -O2 $(ANIMATION_INCLUDE) -c src/Animation/Track.cpp -o build/Animation/track.o

spriteanimation.o: 
	g++ -O2 $(ANIMATION_INCLUDE) -c src/Animation/SpriteAnimation.cpp -o build/Animation/spriteanimation.o

animation.o: 
	g++ -O2 $(ANIMATION_INCLUDE) -c src/Animation/Animation.cpp -o build/Animation/animation.o

animation:
	ar -r -s build/lib/libanimation.a build/Animation/animation.o build/Animation/spriteanimation.o build/Animation/sprite.o build/Animation/track.o build/Animation/trackstatechanged.o build/Animation/trackstate.o build/Animation/skeleton.o build/Animation/boundvertex.o build/Animation/joint.o 
#END libanimation.a