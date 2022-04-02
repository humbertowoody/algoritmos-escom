set title "Ejercicio 5: Problema 6"
set grid
set xlabel "Tamaño del problema (n)"
set ylabel "Costo"
set xrange [0:]
set yrange [0:]
plot \
  5*x**3 + 5*x**2, \
  2*x**3 + 3*x**2 + 9*x + 120, \
  x**3 + x**2

