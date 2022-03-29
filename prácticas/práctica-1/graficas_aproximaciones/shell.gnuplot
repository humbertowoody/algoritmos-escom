# Gráfica de las aproximaciones a la función del comportamiento temporal
# (tiempo real) para el algoritmo: Shell.
set title "Aproximaciones a la función de comportamiento temporal para Shell"
set grid
set xlabel "Tamaño del Problema (n)"
set ylabel "Tiempo de Ejecución"
plot [0:] \
  5.155105*x + 3.925235, \
  0.658697*x*x + 4.595581*x + 3.299473, \
  -0.134673*x*x*x + 0.881233*x*x + 4.698576*x + 3.196740#, \
  # 0.360120*x*x*x*x*x*x + -1.268802*x*x*x*x*x + 0.720870*x*x*x*x + 1.059939*x*x*x + 0.074802*x*x + 4.433144*x + 3.297618
