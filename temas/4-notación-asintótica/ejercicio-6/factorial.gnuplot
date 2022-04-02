set title "Complejidad factorial O(n!)"
set grid
set xlabel "Tamaño del problema (n)"
set ylabel "Costo"
set xrange [0:]
set yrange [0:]
fac(x) = (int(x)==0) ? 1.0 : int(x) * fac(int(x)-1.0)
plot fac(x)
