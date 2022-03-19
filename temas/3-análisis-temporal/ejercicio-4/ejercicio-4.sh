#!/bin/bash
# Script para ejecutar todos los códigos y generar los resultados.

# Compilamos el código.
make;

# Ejecutamos el código.
./codigo_1.out >codigo_1.csv;
./codigo_2.out >codigo_2.csv;
./codigo_3.out >codigo_3.csv;
./codigo_4.out >codigo_4.csv;

# Eliminamos binarios y archivos objetos.
make clean;
