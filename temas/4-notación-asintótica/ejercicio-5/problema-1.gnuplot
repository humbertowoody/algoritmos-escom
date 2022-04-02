set title "Ejercicio 5: Problema 1"
set grid
set xlabel "Tamaño del problema (n)"
set ylabel "Costo"
set xrange [200:400]
set yrange [0:]
plot \
  3 * x**2, \
  2 * x**2 + 300*x - 1000

