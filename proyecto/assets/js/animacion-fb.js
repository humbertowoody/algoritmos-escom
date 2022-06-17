// Contador del paso de animación.
let paso_animacion = 1,
  fila = 1,
  columna = 1,
  iSum = 1,
  contador = -1,
  tamanio = 3;

// selectores de código por línea
const codigo = [$("#linea1"), $("#linea2"), $("#linea3"), $("#linea4")];

// Generar un color obscuro.
function getDarkColor() {
  var color = "#";
  for (var i = 0; i < 6; i++) {
    color += Math.floor(Math.random() * 10);
  }
  return color;
}

// Función que obtiene el valor númerico de una celda.
const valor_de = (id) => {
  return Number($(`#${id}`).val() || $(`#${id}`).html());
};

// Función para multiplicar los valores en dos celdas.
const multiplicar_id = (id1, id2) => {
  return valor_de(id1) * valor_de(id2);
};

// Para atrapar eventos de JS.
jQuery(function ($) {
  function limpiarCeldasSeleccionadas() {
    // Iteramos y llenamos saltantes.
    for (let i = 1; i <= tamanio; i++) {
      for (let j = 1; j <= tamanio; j++) {
        $(`#a${i}${j}`).removeClass("celda-seleccionada");
        $(`#a${i}${j}`).css("background-color", "transparent");
        $(`#b${i}${j}`).removeClass("celda-seleccionada");
        $(`#b${i}${j}`).css("background-color", "transparent");
        $(`#c${i}${j}`).removeClass("celda-seleccionada");
        $(`#c${i}${j}`).css("background-color", "transparent");
      }
    }
  }
  // Cuando hagan click en el botón de siguiente.
  $("#siguiente").on("click", function () {
    switch (paso_animacion) {
      case 1:
        // Iteramos y llenamos saltantes.
        for (let i = 1; i <= tamanio; i++) {
          for (let j = 1; j <= tamanio; j++) {
            // Si a(i,j) está vacía.
            if (!$(`#a${i}${j}`).val()) {
              $(`#a${i}${j}`).val(Math.floor(Math.random() * 9) + 1);
            }
            // Si b(i,j) está vacía.
            if (!$(`#b${i}${j}`).val()) {
              $(`#b${i}${j}`).val(Math.floor(Math.random() * 9) + 1);
            }

            // Desactivamos las entradas.
            $(`#a${i}${j}`).attr("disabled", true);
            $(`#b${i}${j}`).attr("disabled", true);
          }
        }

        // Cambiamos el texto del botón.
        $("#siguiente").text("Siguiente");

        // Mostramos la explicación.
        $("#status").html(
          "Estos son los valores que consideraremos para la animación."
        );

        // Aumentamos la animación.
        paso_animacion++;
        break;
      case 2:
        // Limpiamos las celdas seleccionadas.
        limpiarCeldasSeleccionadas();

        // Calculamos el texto a mostrar de operación.
        let valor =
          Number($(`#c${fila}${columna}`).html()) +
          multiplicar_id(`a${fila}${iSum}`, `b${iSum}${columna}`);

        // Mostramos el status.
        $("#status").html(
          `Sumamos A[${fila},${iSum}] x B[${iSum},${columna}] a Resultado[${fila},${columna}].<br />
          Esto es: (${valor_de(`a${fila}${iSum}`)} x ${valor_de(
            `b${iSum}${columna}`
          )} = ${multiplicar_id(
            `a${fila}${iSum}`,
            `b${iSum}${columna}`
          )}) + ${valor_de(`c${fila}${columna}`)} = ${valor}.`
        );

        let color1 = getDarkColor(),
          color2 = getDarkColor(),
          color3 = getDarkColor();

        // Mostramos la línea de código relevante.
        codigo[fila - 1].addClass("codigo-resaltado");
        codigo[fila - 1].css("background-color", color1);
        codigo[columna - 1].addClass("codigo-resaltado");
        codigo[columna - 1].css("background-color", color2);
        codigo[iSum - 1].addClass("codigo-resaltado");
        codigo[iSum - 1].css("background-color", color3);

        // Remarcamos las celdas de la operación.
        $(`#a${fila}${iSum}`).addClass("celda-seleccionada");
        $(`#a${fila}${iSum}`).css("background-color", color1);
        $(`#b${iSum}${columna}`).addClass("celda-seleccionada");
        $(`#b${iSum}${columna}`).css("background-color", color2);
        $(`#c${fila}${columna}`).addClass("celda-seleccionada");
        $(`#c${fila}${columna}`).css("background-color", color3);

        // Mostramos el resultado.
        $(`#c${fila}${columna}`).html(valor);

        // Checamos si es la última iteración.
        if (iSum === tamanio && fila === tamanio && columna === tamanio) {
          // Mostramos la explicación.
          $("#siguiente").html("Finalizar");
          paso_animacion++;
        }

        // Aumentamos iteradores.
        if (iSum === tamanio) {
          iSum = 1;
          if (columna === tamanio) {
            columna = 1;
            if (fila === tamanio) {
              fila = 1;
            } else {
              fila++;
            }
          } else {
            columna++;
          }
        } else {
          iSum++;
        }

        break;
      default:
        // Mostramos una alerta de confirmación.
        alert(`¡Fin! Tomó ${contador} pasos completar el procedimiento.`);
        // Limpiamos matrices.
        limpiarCeldasSeleccionadas();
        for (let i = 1; i <= tamanio; i++) {
          for (let j = 1; j <= tamanio; j++) {
            // Limpiamos matrices.
            $(`#a${i}${j}`).val("");
            $(`#b${i}${j}`).val("");
            $(`#c${i}${j}`).html(0);

            // Activamos entradas.
            $(`#a${i}${j}`).attr("disabled", false);
            $(`#b${i}${j}`).attr("disabled", false);
          }

          // Cambiamos el texto del botón.
          $("#siguiente").text("Comenzar");
        }

        // Mostramos la explicación inicial.
        $("#status").html(
          "Rellena las matrices para inciar, se rellenarán las celdas vacías con valores aleatorios."
        );

        // Reiniciamos el contador.
        paso_animacion = 1;
        contador = -2;
        break;
    }

    // Actualizamos el contador.
    contador++;
    for (let i = 1; i < codigo.length; i++) {
      $(`#lineaContador${i + 1}`).css(
        "background-color",
        $(`#linea${i}`).css("background-color")
      );
    }

    $("#lineaContador1").html(`Pasos: ${contador}`);
    $("#lineaContador2").html(`Fila: ${fila}`);
    $("#lineaContador3").html(`Columna: ${columna}`);
    $("#lineaContador4").html(`Iteración: ${iSum}`);
    // $("#contador").html(`
    //   Contador de pasos: ${contador} <br />
    //   Fila: ${fila} <br />
    //   Columna: ${columna} <br />
    //   Iteración: ${iSum} <br />
    // `);
  });
});
