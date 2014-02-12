
LOG_INCLUDE= -Iinclude

# liblog.a

all: log

logger.o: 
	g++ -O2 $(LOG_INCLUDE) -c src/Log/Logger.cpp -o build/Log/logger.o 

log: logger.o 
	ar -r  -s build/lib/liblog.a build/Log/logger.o

# end of libinput.a