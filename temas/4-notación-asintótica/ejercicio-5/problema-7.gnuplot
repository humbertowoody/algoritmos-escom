set title "Ejercicio 5: Problema 7"
set grid
set xlabel "Tamaño del problema (n)"
set ylabel "Costo"
set xrange [0:15]
set yrange [0:]
plot \
  3*x**2, \
  2*x**2 + 9*x, \
  x**2

