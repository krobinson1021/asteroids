CC=g++
RM=rm -f
CFLAGS=-c -Wall -std=c++11 -I../include
SOURCES=driver.cpp asteroid.cpp laser.cpp ship.cpp functions.cpp
OBJECTS=driver.o asteroid.o laser.o ship.o functions.o


all: build play

build:
	@echo "Compiling and linking..."
	$(CC) $(CFLAGS) $(SOURCES)
	$(CC) -o asteroids $(OBJECTS) -lsfml-graphics -lsfml-window -lsfml-system

play:
	@echo "Executing..."
	./asteroids

clean:
	@echo "Cleaning...";
	$(RM) asteroids
	$(RM) *.o