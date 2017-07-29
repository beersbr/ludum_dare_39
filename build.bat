@echo off

CLS
SET VCPATH="C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\"

REM execute the command to see if it exists
cl.exe 2> NUL
IF %ERRORLEVEL%==9009 call %VCPATH%\vcvarsall.bat x64

REM "copy dll bin files"

MKDIR build
PUSHD build

COPY ..\library\bin\win64\* .

MKDIR .\shaders

COPY ..\src\shaders\* shaders\

POPD

cl  /EHsc /MD /Ilibrary\include\ /Febuild/game /Zi src\main.cpp src\game.cpp src\shader_manager.cpp src\texture.cpp /DSLOW /link /LIBPATH:library\lib\win64\ opengl32.lib SDL2.lib SDL2_image.lib SDL2main.lib glew32.lib /SUBSYSTEM:CONSOLE

POPD


