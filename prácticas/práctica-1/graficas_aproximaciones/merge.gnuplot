# Gráfica de las aproximaciones a la función del comportamiento temporal
# (tiempo real) para el algoritmo: Merge.
set title "Aproximaciones a la función de comportamiento temporal para Merge"
set grid
set xlabel "Tamaño del Problema (n)"
set ylabel "Tiempo de Ejecución"
plot [0:] \
  0.139378*log(x)+-1.263619
  