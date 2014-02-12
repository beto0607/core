
NET_INCLUDE= -Iinclude

# libnet.a
all: net

conection.o:
	g++ -O2 $(NET_INCLUDE) -c src/Networking/Conection.cpp -o build/Networking/conection.o

netmanager.o:
	g++ -O2 $(NET_INCLUDE) -c src/Networking/NetManager.cpp -o build/Networking/netmanager.o

net: conection.o netmanager.o
	ar -r -s build/lib/libnet.a build/Networking/netmanager.o build/Networking/conection.o

# END libnet.a