set title "Ejercicio 5: Problema 2"
set grid
set xlabel "Tamaño del problema (n)"
set ylabel "Costo"
set xrange [0:]
set yrange [0:]
plot \
  3 * x**3, \
  2 * x**3 - 30*x + 500

