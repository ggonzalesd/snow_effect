# SnowEffect

## ¿Qué usar?
* Sistema operativo `Gnu/linux`  
* Libreria `ncurses.h`  
* Compilador `g++`  

## Compilar/Ejecutar
> g++ main.cpp -o main -lncurses  
> ./main

## Instalar
> **g++ main.cpp -o main -lncurses**  
> **THIS_DIR=$(pwd)**  
cd ~  
> **if [ -d .local ]; then cd .local; else mkdir .local; cd .local; fi**  
> **if [ -d bin ]; then cd bin; else mkdir bin; cd bin; fi**  
> **cp "$THIS_DIR/main" snoweffect**  
> **cd $THIS_DIR**

### Ejecutar despues de instalar
> **snoweffect**  
