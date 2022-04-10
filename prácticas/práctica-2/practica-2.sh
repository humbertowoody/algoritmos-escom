#!/bin/bash
# practica-2.sh
# Script con los pasos para ejecutar la práctica 2 probando los algoritmos
# proporcionados con los tamaños (n) y los elementos a buscar en cada uno. 
# 
# Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)
# 2022

# Nombre del programa ejecutable.
EJECUTABLE=algoritmos_busqueda.out

# Nombre del archivo con los diez millones de números proporcionado por el profesor.
ARCHIVO_10_MILLONES_DE_NUMEROS=10_millones_numeros.txt

# Bandera para indicar si queremos una ejecución en paralelo (resultados no
# válidos pero excelente para hacer pruebas).
EJECUCION_EN_PARALELO=true

# Nombre del programa para hacer "timeout", es decir, que cuide que si nuestro
# binario toma más de X tiempo, lo finaliza.
# En mi caso, estoy usando GNU "timeout", el cual viene incluído en distros Linux modernas
# sin embargo puede ser requerido instalarse, en macOS con Hombrew sería así:
# $ brew install coreutils
# Y, para no reemplazar las utilidades default de macOS (por razones obvias), los binarios
# incluídos se inician con una 'g'. Por ejemplo 'timeout' -> 'gtimeout'.
# En Ubuntu está incluída la utilidad original: timeout.
PROGRAMA_TIMEOUT=timeout

# Máximo tiempo de ejecución por programa.
TIEMPO_TIMEOUT=10s

# Índices de los algoritmos disponibles en el programa.
ALGORITMOS=(
  "lineal"
  "lineal_p"
  "abb"
  #"abb_p"
  "binaria"
  #"binaria_p"
  "exponencial"
  #"exponencial_p"
  "fibonacci"
  #"fibonacci_p"
);

# Arreglo con los valores de n para probar.
VALORES_N=(
  1000000
  # 2000000
  # 3000000
  # 4000000
  # 5000000
  # 6000000
  # 7000000
  # 8000000
  # 9000000
  # 10000000
);

# Arreglo con los elementos a buscar.
ELEMENTOS_A_BUSCAR=(
  322486
  14700764
  3128036
  6337399
  61396
  10393545
  2147445644
  1295390003
  450057883
  187645041
  1980098116
  152503
  5000
  1493283650
  214826
  1843349527
  1360839354
  2109248666
  2147470852
  0
);

# Generamos el nombre del archivo para los resultados.
CARPETA_RESULTADOS=resultados # Debe existir!
ARCHIVO_CSV=$CARPETA_RESULTADOS/res-$(date +"%H-%M_%d_%m_%Y")-to-$TIEMPO_TIMEOUT.csv

# Inicio de ejecución.
# 0) Compilar el programa.
# 1) Creamos archivo CSV con resultados.
# 2) Iteramos sobre cada n seleccionada.
# 3) Iteramos sobre cada algoritmo seleccionado.
# 4) Limpiar binarios y archivos objeto.

# Variable auxiliar para mejorar el rendimiento llevando el tracking de los
# algoritmos que ya dieron timeout para omitirlos de las pruebas.
declare -A timeouts;
for alg in ${ALGORITMOS[@]}; do
  timeouts[$alg]=false;
done

# Compilamos el programa.
make all;

# Imprimimos el encabezado CSV estándar para la práctica.
echo "nombre_algoritmo,n,elemento,tiempo_real,tiempo_usuario,tiempo_sistema,tiempo_cpu_wall" >$ARCHIVO_CSV;

# Mensaje de inicio.
echo "Inicio de ejecución: $(date)";
echo "Máximo tiempo de ejecución: $TIEMPO_TIMEOUT";
echo "Ejecución en paralelo: $EJECUCION_EN_PARALELO";
echo "Algoritmos a probar:";
for algoritmo in ${ALGORITMOS[@]}; do
  echo "\t - $algoritmo";
done
echo "Valores de n para probar:";
for n in ${VALORES_N[@]}; do
  echo "\t - $n";
done
echo "Elementos a buscar en cada n:";
for elemento in ${ELEMENTOS_A_BUSCAR[@]}; do
  echo "\t - $n";
done


# Iteramos sobre las n proporcionadas.
for n in ${VALORES_N[@]}; do
  # Iteramos sobre los algoritmos seleccionados.
  for alg in ${ALGORITMOS[@]}; do
    # Verificamos si el algoritmo en cuestión ya dió timeout en una iteración 
    # anterior y, de ser así, lo omitimos.
    if [ "${timeouts[$alg]}" = false ]; then
      # Iteramos sobre los elementos de búsqueda seleccionados.
      for elemento in ${ELEMENTOS_A_BUSCAR[@]}; do
        echo "Ejecutando algoritmo: \"$alg\" para búsqueda de: \"$elemento\" en $n elementos. ($(date))";
        # Aquí decidimos si queremos ejecutar los algoritmos en paralelo o secuencialmente.
        if [ "$EJECUCION_EN_PARALELO" = true ] ; then
          # Ejecutamos cada algoritmo en el background.
          $PROGRAMA_TIMEOUT $TIEMPO_TIMEOUT ./$EJECUTABLE $alg $n $elemento <$ARCHIVO_10_MILLONES_DE_NUMEROS >>$ARCHIVO_CSV || { echo "Timeout para \"$alg\" en complejidad: $n ($(date))" && timeouts[$alg]=true; } &
        else
          # Ejecutamos cada algoritmo de forma secuencial.
          $PROGRAMA_TIMEOUT $TIEMPO_TIMEOUT ./$EJECUTABLE $alg $n $elemento <$ARCHIVO_10_MILLONES_DE_NUMEROS >>$ARCHIVO_CSV || { echo "Timeout para \"$alg\" en complejidad: $n ($(date))" && timeouts[$alg]=true; };
        fi
      done
    else
      echo "Saltando algoritmo: \"$alg\" para n=$n por timeout previo.";
    fi
  done
done

# En caso de que hayamos ejecutado los algoritmos de forma paralela, esperamos
# a que terminen todos los procesos inicializados.
if [ "$EJECUCION_EN_PARALELO" = true ] ; then
  echo "Esperando a que terminen la ejecución de los programas...";
  wait;
fi

# Limpiamos todo.
make clean;

# Mensaje de fin.
echo "Fin de ejecución: $(date)";
echo "Archivo de resultados: $ARCHIVO_CSV";

# Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)

