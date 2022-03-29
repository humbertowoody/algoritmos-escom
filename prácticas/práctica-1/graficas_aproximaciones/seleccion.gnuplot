# Gráfica de las aproximaciones a la función del comportamiento temporal
# (tiempo real) para el algoritmo: Selección.
set title "Aproximaciones a la función de comportamiento temporal para Selección"
set grid
set xlabel "Tamaño del Problema (n)"
set ylabel "Tiempo de Ejecución"
plot [0:] \
  75.320737*x + 40.504773, \
  29.120898*x*x + 41.248262*x + 14.619531, \
  0.143801*x*x*x + 28.846246*x*x + 41.171356*x + 14.714108, \
  0.862265*x*x*x*x*x*x + -1.038268*x*x*x*x*x + -2.428278*x*x*x*x + 0.669053*x*x*x + 31.026775*x*x + 41.833324*x + 14.620144
