# Gráfica de las aproximaciones a la función del comportamiento temporal
# (tiempo real) para el algoritmo: Heap Sort.
set title "Aproximaciones a la función de comportamiento temporal para Heap Sort"
set grid
set xlabel "Tamaño del Problema (n)"
set ylabel "Tiempo de Ejecución"
plot [0:] \
  0.006459*log(x)+-0.058057, \
  0.029486*x + 0.024881