#!/bin/bash
# Compilar y ejecutar

# Compilamos el código
g++ *.cpp -o ejecutable-02.out;

# Limpiamos el fichero de salida.
rm salidas.csv;
touch salidas.csv;
echo "n,programa,modelo" > salidas.csv;

# Realizamos las pruebas y acumulamos resultados.
./ejecutable-02.out -1 >>salidas.csv;
./ejecutable-02.out 0 >>salidas.csv;
./ejecutable-02.out 1 >>salidas.csv;
./ejecutable-02.out 2 >>salidas.csv;
./ejecutable-02.out 3 >>salidas.csv;
./ejecutable-02.out 5 >>salidas.csv;
./ejecutable-02.out 15 >>salidas.csv;
./ejecutable-02.out 20 >>salidas.csv;
./ejecutable-02.out 100 >>salidas.csv;
./ejecutable-02.out 409 >>salidas.csv;
./ejecutable-02.out 500 >>salidas.csv;
./ejecutable-02.out 593 >>salidas.csv;
./ejecutable-02.out 1000 >>salidas.csv;
./ejecutable-02.out 1471 >>salidas.csv;
./ejecutable-02.out 1500 >>salidas.csv;
./ejecutable-02.out 2801 >>salidas.csv;
./ejecutable-02.out 3000 >>salidas.csv;
./ejecutable-02.out 5000 >>salidas.csv;
./ejecutable-02.out 10000 >>salidas.csv;
./ejecutable-02.out 20000 >>salidas.csv;
