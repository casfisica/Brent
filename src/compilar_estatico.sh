#!/bin/bash

#  $1 es lo que entra como argumento

if [ -z "$1" ];
then

    echo "nombre del ejecutable, y la(s) librerias ejemplo: ./compilar_estatico 'programa libreria' (solo el nombre sin extenciones ni el prefijo lib) ";

        
else

    g++ -c "lib$2.cpp" -o "lib$2.o"
    ar rcs "lib$2.a" "lib$2.o"
    g++-5 -static "$1.cpp" -L. -"l$2" -o  $1.out


    
fi 
