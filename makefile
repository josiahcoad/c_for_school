all: GIU.o 
    g++ -std=c++14 GIU.o -o run

GIU.o: GIU.cpp GIU.h
    g++ -std=c++14 -c GIU.cpp

clean:
	rm *.o run
