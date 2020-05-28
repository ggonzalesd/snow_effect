# SnowEffect

## Que usar
..* Sistema operativo `Gnu/linux`
..* Libreria `ncurses.h`
..* Compilador `g++`

## Compilar/Ejecutar
**g++ main.cpp -o main -lncurses**
**./main**

## Instalar
**g++ main.cpp -o main -lncurses**
**THIS_DIR=$(pwd)**
**cd ~**
**if [ -d .local ]; then mv .local; else mkdir .local; mv .local; fi**
**if [ -d bin ]; then mv bin; else mkdir bin; mv bin; fi**
**cp "$THIS_DIR/main snoweffect"

### Ejecutar despues de instalar
**snoweffect**
