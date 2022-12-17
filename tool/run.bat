@echo off
color a
g++ -static-libgcc -static-libstdc++ manager.cpp -o manager.exe
start manager.exe