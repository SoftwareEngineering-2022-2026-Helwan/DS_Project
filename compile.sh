#!/bin/bash

AppName="multiMap"

mkdir obj 2> /dev/null

# compile the headers and store the its object file in obj
gcc -c source_code/handler.c        -o  obj/handler.o 
gcc -c source_code/validation.c     -o  obj/validation.o 
gcc -c source_code/displayMenu.c    -o  obj/displayMenu.o 
gcc -c source_code/List.c           -o  obj/List.o
gcc -c source_code/menu.c           -o  obj/menu.o  
gcc -c source_code/operations.c     -o  obj/operations.o 
gcc -c source_code/pairUtils.c      -o  obj/pairUtils.o 
gcc -c source_code/sort.c           -o  obj/sort.o

# compile the main program linked with the obj
gcc obj/* main.c -o $AppName
