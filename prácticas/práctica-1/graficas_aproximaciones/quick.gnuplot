# Gráfica de las aproximaciones a la función del comportamiento temporal
# (tiempo real) para el algoritmo: Quick Sort.
set title "Aproximaciones a la función de comportamiento temporal para Quick Sort"
set grid
set xlabel "Tamaño del Problema (n)"
set ylabel "Tiempo de Ejecución"
plot [0:] \
  0.095489*log(x)+-0.865188
  