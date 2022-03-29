# Gráfica de las aproximaciones a la función del comportamiento temporal
# (tiempo real) para el algoritmo: Burbuja Simple.
set title "Aproximaciones a la función de comportamiento temporal para Burbuja Simple"
set grid
set xlabel "Tamaño del Problema (n)"
set ylabel "Tiempo de Ejecución"
plot [0:] \
  36.271147*x + 19.104938, \
  14.431341*x*x + 19.698536*x + 6.735217, \
  0.084317*x*x*x + 14.286307*x*x + 19.637767*x + 6.776537#, \
  #-9.698826*x*x*x*x*x*x + 6.806174*x*x*x*x*x + 24.335316*x*x*x*x + 5.264492*x*x*x + 6.201101*x*x + 16.393083*x + 6.684913
