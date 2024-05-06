#!/bin/bash

AppName="multiMap"

gcc -c source_code/displayMenu.c -o  obj/displayMenu.o 
gcc -c source_code/List.c   -o obj/List.o
gcc -c source_code/menu.c -o  obj/menu.o  
gcc -c source_code/operations.c  -o obj/operations.o 
gcc -c source_code/pairUtils.c -o obj/pairUtils.o 
gcc -c source_code/sort.c  -o obj/sort.o

gcc obj/* main.c -o $AppName
