#!/bin/bash
# Script para realizar todas las ejecuciones del ejercicio 3.
# Autor: Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)

# Compilamos los programas.
gcc ./mejor_caso.c ./producto_dos_mayores.c ./librerias/*.c -o mejor_caso.out;
gcc ./peor_caso.c ./producto_dos_mayores.c ./librerias/*.c -o peor_caso.out;
gcc ./caso_medio.c ./producto_dos_mayores.c ./librerias/*.c -o caso_medio.out;

# Ejecutamos los programas.
./mejor_caso.out 2500 >resultados_mejor_caso_2500.csv;
./mejor_caso.out 5000 >resultados_mejor_caso_5000.csv;
./peor_caso.out 2500 >resultados_peor_caso_2500.csv;
./peor_caso.out 5000 >resultados_peor_caso_5000.csv;
./caso_medio.out 2500 >resultados_caso_medio_2500.csv;
./caso_medio.out 5000 >resultados_caso_medio_5000.csv;
