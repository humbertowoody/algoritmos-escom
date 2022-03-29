# Gráfica de las aproximaciones a la función del comportamiento temporal
# (tiempo real) para el algoritmo: Inserción.
set title "Aproximaciones a la función de comportamiento temporal para Inserción"
set grid
set xlabel "Tamaño del Problema (n)"
set ylabel "Tiempo de Ejecución"
plot [0:] \
  73.544664*x + 42.819904, \
  29.279588*x*x + 43.891620*x + 16.468274, \
  0.081133*x*x*x + 29.134958*x*x + 43.842941*x + 16.524491, \
  0.091846*x*x*x*x*x*x + -0.318469*x*x*x*x*x + 0.203875*x*x*x*x + 0.304354*x*x*x + 28.958580*x*x + 43.808637*x + 16.541751
