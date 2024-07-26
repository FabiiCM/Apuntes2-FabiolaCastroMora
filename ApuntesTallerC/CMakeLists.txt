cmake_minimum_required(VERSION 3.22.1)
project(apuntestallerC)
set(CMAKE_C_STANDARD 11)
add_executable(apuntestallerC main.c Ejercicio1.h Ejercicio1.c Ejercicio2.h Ejercicio2.c Ejercicio3.h Ejercicio3.c Ejercicio4.h Ejercicio4.c Ejercicio5.h Ejercicio5.c)
#Ctrl Shift P > CMake: Select a kit > Select a variable > Debug
#cada vez que agrego un archivo dentro del add executable, le doy build para que compile la informacion

