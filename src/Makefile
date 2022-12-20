all:
	g++ -c point.cpp
	g++ -c object.cpp
	g++ -o main main.cpp point.o object.o -lncurses
tar:
	tar cvf ec6.tar point.h point.cpp object.h object.cpp main.cpp Makefile 

clean:
	rm ec6.tar main point.o object.o
