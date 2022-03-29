# Gráfica de las aproximaciones a la función del comportamiento temporal
# (tiempo real) para todos los algoritmos.
set title "Aproximaciones a la función de comportamiento temporal"
set grid
set xlabel "Tamaño del Problema (n)"
set ylabel "Tiempo de Ejecución"
plot [0:] \
  14.431341*x*x + 19.698536*x + 6.735217 title 'Burbuja Simple', \
  10.986627*x*x + 14.884114*x + 5.049672 title 'Burbuja Optimizada 1', \
  10.921471*x*x + 14.723485*x + 4.974177 title 'Burbuja Optimizada 2', \
  29.279588*x*x + 43.891620*x + 16.468274 title 'Inserción', \
  29.120898*x*x + 41.248262*x + 14.619531 title 'Selección', \
  0.658697*x*x + 4.595581*x + 3.299473 title 'Shell', \
  2.911110*x + 2.124859 title 'Árbol Binario de Búsqueda', \
  0.139378*log(x)-1.263619 title 'Merge Sort', \
  0.139378*log(x)+-1.263619 title 'Quick Sort', \
  0.029486*x + 0.024881 title 'Heap Sort'
