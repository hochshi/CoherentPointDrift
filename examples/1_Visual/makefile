CC = g++ -std=c++17
CF = -Wfatal-errors -O3
LF = -I/usr/local/include -L/usr/local/lib

TINYLINK = -lX11 -lpthread -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lGL -lGLEW -lboost_system -lboost_filesystem

all: source/main.cpp
			$(CC) source/main.cpp $(CF) $(LF) -lfgt -lTinyEngine $(TINYLINK) -o main
