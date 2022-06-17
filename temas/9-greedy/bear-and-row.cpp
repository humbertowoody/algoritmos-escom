/**
 * @file bear-and-row.cpp
 * @author Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)
 * @brief Solución al problema: Bear and Row (https://www.codechef.com/submit-v2/ROWSOLD)
 * @version 0.1
 * @date 2022-06-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <bits/stdc++.h> // Librería estándar de C++ proporcionada por el juez.
using namespace std;

// Función principal.
int main()
{
  // Variables locales.
  int t; // El número de platos.

  cin >> t; // Lectura del número de platos.

  // Iteramos sobre cada plato.
  while (t--)
  {
    string plato;         // Creamos un plato string.
    cin >> plato;         // Leemos el plato.
    int n = plato.size(); // Obtenemos el número de caracteres del plato.

    // Banderas y variables temporales.
    unsigned long long int bandera = 0, contador = 0, temp = 0, bandera1 = 0;
    unsigned long long int sum1 = 0;

    // Iteramos sobre cada caracter del plato.
    for (int i = 0; i < n; i++)
    {
      // Si el plato en la posición actual es 1 y la bandera es 0.
      if (plato[i] == '1' && bandera == 0)
      {
        bandera = 1;
        contador++;
        continue;
      }

      // Si el plato es 1 y la bandera es 1.
      if (plato[i] == '1' && bandera == 1)
      {
        bandera = 1;
        if (bandera1 == 1)
          sum1 = sum1 + (contador * (temp + 1));
        contador++;
        temp = 0;
        bandera1 = 0;
      }

      // Si el plato es 0 y la bandera es 1
      if (plato[i] == '0' && bandera == 1)
      {
        bandera1 = 1;
        temp++;
      }
    }

    // Verificación final del plato en n-1 para condición de optimalidad.
    if (plato[n - 1] == '0')
    {
      sum1 = sum1 + (contador * (temp + 1));
    }

    // Mostramos la suma para este plato.
    cout << sum1 << endl;
  }

  // Fin de ejecución.
  return 0;
}