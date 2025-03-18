@echo off
setlocal
set src=main.cpp point.cpp line.cpp
set cc=clang++
set cflags=-I"f:/code/cpp/lib/include" -std=c++17 -Wall -Wextra -Werror
set lflags=-L"f:/code/cpp/lib/lib" -lsfml-graphics -lsfml-window -lsfml-system

%cc% %cflags% %src% -o main.exe %lflags%
endlocal
