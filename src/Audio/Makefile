
AUDIO_INCLUDE= -Iinclude
SDL_CONFIG= `../../external/sdl2-config --static-libs`

# libaudio.a

all: audio

audiomanager.o:
	g++ -O2 $(AUDIO_INCLUDE) -c src/Audio/AudioManager.cpp -o build/Audio/audiomanager.o

sound.o:
	g++ -O2 $(AUDIO_INCLUDE) -c src/Audio/Sound.cpp -o build/Audio/sound.o

audio.o:
	g++ -O2 $(AUDIO_INCLUDE) -c src/Audio/Audio.cpp -o build/Audio/audio.o
	
song.o:
	g++ -O2 $(AUDIO_INCLUDE) -c src/Audio/Song.cpp -o build/Audio/song.o

audio: audiomanager.o audio.o sound.o song.o
	ar -r -s build/lib/libaudio.a build/Audio/audiomanager.o build/Audio/audio.o build/Audio/sound.o build/Audio/song.o
# END libaudio.a