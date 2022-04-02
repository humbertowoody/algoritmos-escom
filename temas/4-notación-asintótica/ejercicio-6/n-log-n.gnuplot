set title "Complejidad O(n*log(n))"
set grid
set xlabel "Tamaño del problema (n)"
set ylabel "Costo"
set xrange [0:100000]
set yrange [0:]
plot x*log(x)
