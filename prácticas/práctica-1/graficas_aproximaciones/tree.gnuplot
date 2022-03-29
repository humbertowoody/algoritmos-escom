# Gráfica de las aproximaciones a la función del comportamiento temporal
# (tiempo real) para el algoritmo: Árbol Binario de Búsqueda (Tree).
set title "Aproximaciones a la función de comportamiento temporal para Árbol Binario de Búsqueda (Tree)"
set grid
set xlabel "Tamaño del Problema (n)"
set ylabel "Tiempo de Ejecución"
plot [0:] \
  2.911110*x + 2.124859, \
  0.500668*x*x + 2.485822*x + 1.649224, \
  -0.149368*x*x*x + 0.747487*x*x + 2.600056*x + 1.535281, \
  0.001220*x*x*x*x*x*x + -0.027097*x*x*x*x*x + 0.163326*x*x*x*x + -0.377169*x*x*x + 0.660263*x*x + 2.775269*x + 1.546719
