set title "Comparativa entre todos los órdenes de complejidad"
set grid
set xlabel "Tamaño del problema (n)"
set ylabel "Costo"
set xrange [0:6]
set yrange [0:]
fac(x) = (int(x)==0) ? 1.0 : int(x) * fac(int(x)-1.0)
plot \
  1 title 'Constante', \
  log(x) title 'Logarítmica', \
  x title 'Lineal', \
  x*log(x) title 'n log n', \
  x**2 title 'Cuadrática', \
  x**3 title 'Cúbica', \
  2**x title 'Exponencial', \
  fac(x) title 'Factorial'
