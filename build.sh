#!/bin/bash

LIBRARY_DIRECTORY=/Library/Frameworks
OUTPUTPATH=build
EXECUTABLE_NAME=ludumdare39
SRC_DIRECTORY=src

clang++ -F $LIBRARY_DIRECTORY \
-std=c++11 \
-framework SDL2 -framework opengl \
-o $OUTPUTPATH/$EXECUTABLE_NAME \
$SRC_DIRECTORY/main.cpp $SRC_DIRECTORY/game.cpp

