set title 'Ajustes a la función de comportamiento temporal de Búsqueda Fibonacci'
set grid
set xlabel 'Tamaño del Problema (n)'
set ylabel 'Tiempo de ejecución'
set xrange [0:10000000]
set yrange [0:54717]
plot \
   + 2778.080218*x**1 + 49519.700000*x**0 title 'Polinomio grado 1', \
   + -985.173611*x**2 + 2778.080218*x**1 + 50406.356250*x**0 title 'Polinomio grado 2', \
   + 6.399254*x**3 + -985.173611*x**2 + 2767.853047*x**1 + 50406.356250*x**0 title 'Polinomio grado 3', \
   + 3085.779120*x**6 + -2666.997949*x**5 + -12184.343667*x**4 + 7522.484382*x**3 + 11457.065208*x**2 + -1243.884942*x**1 + 48402.943115*x**0 title 'Polinomio grado 6', \
  3956.861535*log(x)+-11122.969220 title 'Logarítmico', \
  0.000000 * exp(10.704672*x) title 'Exponencial', \
  1 / (-0.000000*x + 0.000022) title 'Inverso'