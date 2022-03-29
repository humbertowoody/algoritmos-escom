# Gráfica de las aproximaciones a la función del comportamiento temporal
# (tiempo real) para el algoritmo: Burbuja Optimizada 1.
set title "Aproximaciones a la función de comportamiento temporal para Burbuja Optimizada 1"
set grid
set xlabel "Tamaño del Problema (n)"
set ylabel "Tiempo de Ejecución"
plot [0:] \
  27.500897*x + 14.466781, \
  10.986627*x*x + 14.884114*x + 5.049672, \
  0.041848*x*x*x + 10.914645*x*x + 14.853953*x + 5.070179#, \
  #-12.882195*x*x*x*x*x*x + 8.676464*x*x*x*x*x + 32.729530*x*x*x*x + 7.670934*x*x*x + 0.042533*x*x + 10.300202*x + 4.936281
