# Práctica 1

En esta práctica se realizó la implementación de varios algoritmos de búsqueda
presentes en `librerias/busquedas.h` de los cuales se obtuvieron métricas
de desempeño usando `librerias/tiempo.h`, se ajustaron modelos a partir de los
datos usando _Matlab_, se graficaron usando _GNUPlot_ y se hicieron proyecciones
de comportamiento.

## Compilación

Para compilar está el archivo `Makefile` con el cual se generan los binarios
de nuestro programa.

Para compilar nuestro programa, usaremos:

```sh
make
```

Para ejecutar los tests, usaremos:

```sh
make tests
```

Para borrar los archivos objetos y los binarios:

```sh
make clean
```


## Ejecución

La ejecución de la práctica inicia con el script `practica-2.sh`, el cual contiene
los pasos para compilar (usando el comando `make`) y ejecutar de forma iterativa
cada algoritmo de ordenamiento obteniendo las métricas de tiempo de ejecución,
almacenándolas en un archivo CSV.

En el script se pueden modificar varios parámetros de ejecución de la práctica:

- `VALORES_N`: un arreglo con los valores de _n_ para realizar las mediciones.
- `ALGORITMOS`: un arreglo con los nombres (IDs válidos) de los algoritmos con
                los que se harán las pruebas.
- `ELEMENTOS_A_BUSCAR`: un arreglo con los valores a buscar dentro de cada
                        conjunto de datos para cada algoritmo.
- `EJECUCION_EN_PARALELO`: una bandera para definir si la ejecución de los
                           algoritmos se realizará en paralelo. *Nota:* si se
                           ejecutan en paralelo se distribuirá el procesador
                           por lo que los resultados serán inválidos. Los
                           valores pueden ser `true` o `false`.
- `ARCHIVO_10_MILLONES_DE_NUMEROS`: la ruta que apunta al archivo con los 10
                                    millones de números para realizar las
                                    pruebas de ordenamiento.
- `ARCHIVO_CSV`: el nombre del archivo `.csv` que se generará.
- `EJECUTABLE`: el nombre del ejecutable de nuestro programa.
- `TIEMPO_TIMEOUT`: el tiempo _máximo_ de ejecución de nuestro algoritmo, por
                    ejemplo: `10s` (diez segundos), `5m` (cinco minutos), `1h`
                    (una hora).
- `PROGRAMA_TIMEOUT`: el nombre del programa de timeout a utilizar, por ejemplo
                      `timeout` en Linux o `gtimeout` en macOS (en el caso del
                      último, se deberá instalar con `brew install coreutils`).

La ejecución del script es muy simple:

```sh
# Nos ubicamos en la carpeta de la práctica.
cd prácticas/práctica-2/

# Ejecutamos la práctica
./practica-2.sh
```

### Matlab

Posterior a la ejecución del script se tendrá que, manualmente, ejecutar el
script de Matlab llamado `AproximacionesComplejidad.m` el cual generará como
salida el archivo de GNUPlot (`.gnuplot`) con todos los ajustes realizados para
los resultados proporcionados.

La intención será tomar la salida de cada ejecución y guardarla en un archivo
que posteriormente podremos usar para generar las gráficas.

### GNUPlot

Para usar los archivos de GNUPlot `.gnuplot` se invocará el software de la
siguiente forma:

```sh
gnuplot -p archivo.gnuplot
```

> Por defecto se generó el script para que generara las visualizaciones en
> formato `.png`, sin embargo la resolución es malísima, así que se sugiere
> que se utilice la ventana de ejecución normal (comentando las primeras dos
> líneas del archivo `.gnuplot`) y se tome una captura a partir de ahí.


---

Autor: Humberto Alejandro Ortega Alcocer
Año: 2022

