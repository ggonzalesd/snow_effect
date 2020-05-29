# SnowEffect

## Requisitos
* Solo para el sistema operativo `Gnu/linux`  
* Tener instalado la librería `ncurses.h`  
* Tener instalado el compilador `g++`  
* Agregar el directorio `~/.local/bin/` al `PATH`

## Compilar/Ejecutar
> g++ main.cpp -o main -lncurses  
> ./main

## Instalar
Usar el siguiente código o copiar directamente el archivo `main` en el directorio `~/.local/bin/` con el nombre `snoweffect`  
```
g++ main.cpp -o main -lncurses  
THIS_DIR=$(pwd)  
cd ~  
if [ -d .local ]; then cd .local; else mkdir .local; cd .local; fi  
if [ -d bin ]; then cd bin; else mkdir bin; cd bin; fi  
cp "$THIS_DIR/main" snoweffect  
cd $THIS_DIR
```

### Ejecutar despues de instalar
> snoweffect  
