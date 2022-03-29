# Gráfica de las aproximaciones a la función del comportamiento temporal
# (tiempo real) para el algoritmo: Burbuja Optimizada 2.
set title "Aproximaciones a la función de comportamiento temporal para Burbuja Optimizada 2"
set grid
set xlabel "Tamaño del Problema (n)"
set ylabel "Tiempo de Ejecución"
plot [0:] \
  27.265444*x + 14.335438, \
  10.921471*x*x + 14.723485*x + 4.974177 , \
  0.080515*x*x*x + 10.782978*x*x + 14.665456*x + 5.013633# , \
  #-7.116180*x*x*x*x*x*x + 5.172099*x*x*x*x*x + 17.593743*x*x*x*x + 3.627293*x*x*x + 4.959886*x*x + 12.357570*x + 4.946715 
