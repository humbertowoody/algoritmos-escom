var paso = 0;

function mult(id1, id2) {
  let res = $("#" + id1).val() * $("#" + id2).val();
  console.log("res: ", res);
  return res;
}

/**
 * Arreglo con las explicaciones de cada una de las animaciones.
 */
const explicaciones = [
  "Seleccionamos nuestra primer matriz.",
  "¿La matriz está en el tamaño de caso base (2x2)? No.",
  "La dividiremos en 4 matrices de 2x2.",
  "Ahora seleccionamos nuestra segunda matriz.",
  "¿La matriz está en el tamaño de caso base (2x2)? No.",
  "Así, se subidividirá en 4 matrices de 2x2.",
  "Asignaremos los coeficientes a, b, c, d, e, f, g, h a las matrices.",
  "Aquí comenzaremos con los pasos recursivos para cada una hasta llegar al caso base.",
  "Comenzaremos por las dos primeras sub-matrices de nuestra primer matriz original.",
  "Seleccionamos la primer sub-matriz.",
  "Aplicamos el algoritmo de Strassen.",
  "La subdivisión ahora será en elementos únicos (caso base).",
  "Ahora seleccionamos la segunda sub-matriz.",
  "Aplicamos el algoritmo de Strassen.",
  "Se sub-divide en 4 elementos únicos (caso base).",
  "Ahora tenemos nuestro caso base, 2 matrices de 2x2.",
  "Comenzamos con la operación de multiplicación.",
  "Calculamos ae.",
  "Calculamos bg.",
  "Calculamos af.",
  "Calculamos bh.",
  "Calculamos ce.",
  "Calculamos dg.",
  "Calculamos cf.",
  "Calculamos dh.",
  "Calculamos las sumas intermedias entre cada celda.",
  "Así, ahora realizaremos esos mismos pasos para cada sub-matriz.",
  "Comenzando por las dos primeras sub-matrices de cada matriz original, respectivamente.",
  "Siguiendo con la operación de multiplicación de forma recursiva.",
  "Generando poco a poco cada uno de los resultados.",
  "Con esto vamos a obtener nuestra matriz resultante.",
  "Dado que cada matriz tuvo 4 sub-matrices, esto nos deja los 8 pasos recursivos.",
  "Este sería nuestro pen-último paso recursivo.",
  "Aquí se realizará la multiplicación de las matrices.",
  "Ya tenemos nuestros cálculos para la matriz resultante, solo queda...",
  "Resolver las sumas y ¡Voilá! ¡Fin de la animación!",
];

jQuery(function ($) {
  // Sección para la ejecución general del algoritmo.
  $("#siguiente").on("click", function (e) {
    let ae = Number($("#a11").val()) * Number($("#b11").val());
    let bg = Number($("#a12").val()) * Number($("#b21").val());
    let af = Number($("#a11").val()) * Number($("#b12").val());
    let bh = Number($("#a12").val()) * Number($("#b22").val());
    let ce = Number($("#a21").val()) * Number($("#b11").val());
    let dg = Number($("#a22").val()) * Number($("#b21").val());
    let cf = Number($("#a21").val()) * Number($("#b12").val());
    let dh = Number($("#a22").val()) * Number($("#b22").val());

    // Cada paso de resolución (animación).
    switch (paso) {
      case 0:
        for (let i = 1; i <= 4; i++) {
          for (let j = 1; j <= 4; j++) {
            // llenar celdas vacías.
            if (!$(`#a${i}${j}`).val()) {
              $(`#a${i}${j}`).val(Math.floor(Math.random() * 9) + 1);
            }
            if (!$(`#b${i}${j}`).val()) {
              $(`#b${i}${j}`).val(Math.floor(Math.random() * 9) + 1);
            }
            // desactivar entradas.
            $(`#a${i}${j}`).attr("disabled", true);
            $(`#b${i}${j}`).attr("disabled", true);
          }
        }
        $("#siguiente").html("Siguiente");
        $("#cuadroFrontA").fadeIn();
        $("#codigo").fadeIn();
        $("#cuadroCodigo1").fadeIn();
        break;
      case 1:
        $("#matrizA, #cuadroFrontA").animate({ left: "950px" });
        $("#codigo").fadeOut();
        $("#cuadroCodigo1").fadeOut();
        $("#codigo2").fadeIn();
        $("#cuadroCodigo2").fadeIn();
        break;
      case 2:
        $("#cuadroFrontA").fadeOut();
        $("#cuadroCh1").fadeIn();
        $("#cuadroCh2").fadeIn();
        $("#cuadroCh3").fadeIn();
        $("#cuadroCh4").fadeIn();
        break;
      case 3:
        $("#matrizA").animate({ left: "100px" });
        $("#cuadroCh1").animate({ left: "100px" });
        $("#cuadroCh2").animate({ left: "180px" });
        $("#cuadroCh3").animate({ left: "180px" });
        $("#cuadroCh4").animate({ left: "100px" });
        $("#cuadroFrontB").fadeIn();
        $("#a").fadeIn();
        $("#b").fadeIn();
        $("#c").fadeIn();
        $("#d").fadeIn();
        $("#codigo2").fadeOut();
        $("#cuadroCodigo2").fadeOut();
        $("#codigo").fadeIn();
        $("#cuadroCodigo1").fadeIn();
        $("#cuadroCodigo1").animate({ top: "355px" });
        break;
      case 4:
        $("#matrizB").animate({ left: "950px" });
        $("#cuadroFrontB").animate({ left: "950px" });
        $("#codigo").fadeOut();
        $("#cuadroCodigo1").fadeOut();
        $("#codigo2").fadeIn();
        $("#cuadroCodigo2").fadeIn();
        break;
      case 5:
        $("#cuadroFrontB").fadeOut();
        $("#cuadroChb1").fadeIn();
        $("#cuadroChb2").fadeIn();
        $("#cuadroChb3").fadeIn();
        $("#cuadroChb4").fadeIn();
        break;
      case 6:
        $("#matrizB").animate({ left: "350px" });
        $("#cuadroChb1").animate({ left: "350px" });
        $("#cuadroChb2").animate({ left: "430px" });
        $("#cuadroChb3").animate({ left: "430px" });
        $("#cuadroChb4").animate({ left: "350px" });
        $("#e").fadeIn();
        $("#f").fadeIn();
        $("#g").fadeIn();
        $("#h").fadeIn();
        $("#codigo2").fadeOut();
        $("#cuadroCodigo2").fadeOut();
        $("#codigo").fadeIn();
        $("#cuadroCodigo1").fadeIn();
        $("#cuadroCodigo1").animate({ top: "380px" });
        break;
      case 7:
        $(
          "#matrizB,#matrizA,#cuadroChb1,#cuadroChb2,#cuadroChb3,#cuadroChb4,#cuadroCh1,#cuadroCh2,#cuadroCh3,#cuadroCh4,#e,#f,#g,#h,#a,#b,#c,#d"
        ).fadeOut();
        break;
      case 8:
        $("#subA11").text($("#a11").val());
        $("#subA12").text($("#a12").val());
        $("#subA21").text($("#a21").val());
        $("#subA22").text($("#a22").val());

        $("#subB11").text($("#b11").val());
        $("#subB12").text($("#b12").val());
        $("#subB21").text($("#b21").val());
        $("#subB22").text($("#b22").val());

        $("#subMatrizA").fadeIn();
        $("#subMatrizB").fadeIn();
        break;
      case 9:
        $("#squareChsub1").fadeIn();
        $("#cuadroCodigo1").animate({ top: "335px" });
        break;
      case 10:
        $("#subMatrizA, #squareChsub1").animate({ left: "950px" });
        break;
      case 11:
        $("#squareChsub1").fadeOut();
        $(
          "#squareAsubCh1, #squareAsubCh2, #squareAsubCh3, #squareAsubCh4"
        ).fadeIn();
        $("#codigo").fadeOut();
        $("#cuadroCodigo1").fadeOut();
        $("#codigo2").fadeIn();
        $("#cuadroCodigo2").fadeIn();
        break;
      case 12:
        $("#subMatrizA").animate({ left: "100px" });
        $("#squareAsubCh1").animate({ left: "100px" });
        $("#squareAsubCh2").animate({ left: "140px" });
        $("#squareAsubCh3").animate({ left: "140px" });
        $("#squareAsubCh4").animate({ left: "100px" });
        $("#aa, #bb, #cc, #dd").fadeIn();
        $("#squareChsub2").fadeIn();
        $("#codigo").fadeIn();
        $("#cuadroCodigo1").fadeIn();
        $("#codigo2").fadeOut();
        $("#cuadroCodigo2").fadeOut();
        $("#cuadroCodigo1").animate({ top: "355px" });
        break;
      case 13:
        $("#subMatrizB, #squareChsub2").animate({ left: "950px" });
        $("#codigo").fadeOut();
        $("#cuadroCodigo1").fadeOut();
        $("#codigo2").fadeIn();
        $("#cuadroCodigo2").fadeIn();
        break;
      case 14:
        $("#squareChsub2").fadeOut();
        $(
          "#squareBsubCh1, #squareBsubCh2, #squareBsubCh3, #squareBsubCh4"
        ).fadeIn();
        break;
      case 15:
        $("#subMatrizB").animate({ left: "350px" });
        $("#squareBsubCh1").animate({ left: "350px" });
        $("#squareBsubCh2").animate({ left: "390px" });
        $("#squareBsubCh3").animate({ left: "390px" });
        $("#squareBsubCh4").animate({ left: "350px" });
        $("#ee, #ff, #gg, #hh").fadeIn();
        $("#codigo").fadeIn();
        $("#cuadroCodigo1").fadeIn();
        $("#codigo2").fadeOut();
        $("#cuadroCodigo2").fadeOut();
        $("#cuadroCodigo1").animate({ top: "355px" });
        break;
      case 16:
        $("#subResultado").fadeIn();

        $("#squareAsubCh2, #squareAsubCh3, #squareAsubCh4").css(
          "background-color",
          "#7B7D7D",
          "border-color",
          "#7B7D7D"
        );
        $("#squareAsubCh2, #squareAsubCh3, #squareAsubCh4").css(
          "border-color",
          "#7B7D7D"
        );

        $("#squareBsubCh2, #squareBsubCh3, #squareBsubCh4").css(
          "background-color",
          "#7B7D7D",
          "border-color",
          "#7B7D7D"
        );
        $("#squareBsubCh2, #squareBsubCh3, #squareBsubCh4").css(
          "border-color",
          "#7B7D7D"
        );
        $("#cuadroCodigo1").animate({ top: "565px" });
        break;
      case 17:
        $("#subResultado tr:first th:first").text(ae + "+bg");
        break;
      case 18:
        $("#squareAsubCh2").css("background-color", "#F5C603");
        $("#squareAsubCh2").css("border-color", "#F55F03");

        $("#squareBsubCh4").css("background-color", "#10FC04");
        $("#squareBsubCh4").css("border-color", "#10FC04");

        $("#squareAsubCh1, #squareAsubCh3, #squareAsubCh4").css(
          "background-color",
          "#7B7D7D"
        );
        $("#squareAsubCh1, #squareAsubCh3, #squareAsubCh4").css(
          "border-color",
          "#7B7D7D"
        );

        $("#squareBsubCh1, #squareBsubCh2, #squareBsubCh3").css(
          "background-color",
          "#7B7D7D"
        );
        $("#squareBsubCh1, #squareBsubCh2, #squareBsubCh3").css(
          "border-color",
          "#7B7D7D"
        );

        $("#subResultado tr:first th:first").text(ae + "+" + bg);
        break;
      case 19:
        $("#squareAsubCh1").css("background-color", "#F5C603");
        $("#squareAsubCh1").css("border-color", "#F55F03");

        $("#squareBsubCh2").css("background-color", "#10FC04");
        $("#squareBsubCh2").css("border-color", "#10FC04");

        $("#squareAsubCh2, #squareAsubCh3, #squareAsubCh4").css(
          "background-color",
          "#7B7D7D"
        );
        $("#squareAsubCh2, #squareAsubCh3, #squareAsubCh4").css(
          "border-color",
          "#7B7D7D"
        );

        $("#squareBsubCh1, #squareBsubCh3, #squareBsubCh4").css(
          "background-color",
          "#7B7D7D"
        );
        $("#squareBsubCh1, #squareBsubCh3, #squareBsubCh4").css(
          "border-color",
          "#7B7D7D"
        );

        $("#cuadroCodigo1").animate({ top: "585px" });

        $("#subResultado tr:first th:nth-child(2)").text(af + "+ bh");
        break;
      case 20:
        $("#squareAsubCh2").css("background-color", "#F5C603");
        $("#squareAsubCh2").css("border-color", "#F55F03");

        $("#squareBsubCh3").css("background-color", "#10FC04");
        $("#squareBsubCh3").css("border-color", "#10FC04");

        $("#squareAsubCh1, #squareAsubCh3, #squareAsubCh4").css(
          "background-color",
          "#7B7D7D"
        );
        $("#squareAsubCh1, #squareAsubCh3, #squareAsubCh4").css(
          "border-color",
          "#7B7D7D"
        );

        $("#squareBsubCh1, #squareBsubCh2, #squareBsubCh4").css(
          "background-color",
          "#7B7D7D"
        );
        $("#squareBsubCh1, #squareBsubCh2, #squareBsubCh4").css(
          "border-color",
          "#7B7D7D"
        );

        $("#subResultado tr:first th:nth-child(2)").text(af + "+" + bh);
        break;
      case 21:
        $("#squareAsubCh4").css("background-color", "#F5C603");
        $("#squareAsubCh4").css("border-color", "#F55F03");

        $("#squareBsubCh1").css("background-color", "#10FC04");
        $("#squareBsubCh1").css("border-color", "#10FC04");

        $("#squareAsubCh1, #squareAsubCh3, #squareAsubCh2").css(
          "background-color",
          "#7B7D7D"
        );
        $("#squareAsubCh1, #squareAsubCh3, #squareAsubCh2").css(
          "border-color",
          "#7B7D7D"
        );

        $("#squareBsubCh3, #squareBsubCh2, #squareBsubCh4").css(
          "background-color",
          "#7B7D7D"
        );
        $("#squareBsubCh3, #squareBsubCh2, #squareBsubCh4").css(
          "border-color",
          "#7B7D7D"
        );

        $("#cuadroCodigo1").animate({ top: "610px" });

        $("#subResultado tr:nth-child(2) th:nth-child(1)").text(ce + "+ dg");
        break;
      case 22:
        $("#squareAsubCh3").css("background-color", "#F5C603");
        $("#squareAsubCh3").css("border-color", "#F55F03");

        $("#squareBsubCh4").css("background-color", "#10FC04");
        $("#squareBsubCh4").css("border-color", "#10FC04");

        $("#squareAsubCh1, #squareAsubCh4, #squareAsubCh2").css(
          "background-color",
          "#7B7D7D"
        );
        $("#squareAsubCh1, #squareAsubCh4, #squareAsubCh2").css(
          "border-color",
          "#7B7D7D"
        );

        $("#squareBsubCh3, #squareBsubCh2, #squareBsubCh1").css(
          "background-color",
          "#7B7D7D"
        );
        $("#squareBsubCh3, #squareBsubCh2, #squareBsubCh1").css(
          "border-color",
          "#7B7D7D"
        );

        $("#subResultado tr:nth-child(2) th:nth-child(1)").text(ce + "+" + dg);
        break;
      case 23:
        $("#squareAsubCh4").css("background-color", "#F5C603");
        $("#squareAsubCh4").css("border-color", "#F55F03");

        $("#squareBsubCh2").css("background-color", "#10FC04");
        $("#squareBsubCh2").css("border-color", "#10FC04");

        $("#squareAsubCh1, #squareAsubCh3, #squareAsubCh2").css(
          "background-color",
          "#7B7D7D"
        );
        $("#squareAsubCh1, #squareAsubCh3, #squareAsubCh2").css(
          "border-color",
          "#7B7D7D"
        );

        $("#squareBsubCh3, #squareBsubCh4, #squareBsubCh1").css(
          "background-color",
          "#7B7D7D"
        );
        $("#squareBsubCh3, #squareBsubCh4, #squareBsubCh1").css(
          "border-color",
          "#7B7D7D"
        );

        $("#cuadroCodigo1").animate({ top: "630px" });

        $("#subResultado tr:nth-child(2) th:nth-child(2)").text(cf + "+ dh");
        break;
      case 24:
        $("#squareAsubCh3").css("background-color", "#F5C603");
        $("#squareAsubCh3").css("border-color", "#F55F03");

        $("#squareBsubCh3").css("background-color", "#10FC04");
        $("#squareBsubCh3").css("border-color", "#10FC04");

        $("#squareAsubCh1, #squareAsubCh4, #squareAsubCh2").css(
          "background-color",
          "#018ABE"
        );
        $("#squareAsubCh1, #squareAsubCh4, #squareAsubCh2").css(
          "border-color",
          "#7B7D7D"
        );

        $("#squareBsubCh2, #squareBsubCh4, #squareBsubCh1").css(
          "background-color",
          "#7B7D7D"
        );
        $("#squareBsubCh2, #squareBsubCh4, #squareBsubCh1").css(
          "border-color",
          "#7B7D7D"
        );

        $("#subResultado tr:nth-child(2) th:nth-child(2)").text(cf + "+" + dh);
        break;
      case 25:
        $("#squareAsubCh3,#squareAsubCh1, #squareAsubCh4, #squareAsubCh2").css(
          "background-color",
          "#018ABE"
        );
        $("#squareAsubCh3,#squareAsubCh1, #squareAsubCh4, #squareAsubCh2").css(
          "border-color",
          "#F55F03"
        );

        $("#squareBsubCh3,#squareBsubCh2, #squareBsubCh4, #squareBsubCh1").css(
          "background-color",
          "#10FC04"
        );
        $("#squareBsubCh3,#squareBsubCh2, #squareBsubCh4, #squareBsubCh1").css(
          "border-color",
          "#10FC04"
        );

        $("#subResultado tr:nth-child(1) th:nth-child(1)").text(ae + bg);
        $("#subResultado tr:nth-child(1) th:nth-child(2)").text(af + bh);
        $("#subResultado tr:nth-child(2) th:nth-child(1)").text(ce + dg);
        $("#subResultado tr:nth-child(2) th:nth-child(2)").text(cf + dh);

        break;
      case 26:
        $("#Resultado").fadeIn();
        $(
          "#subMatrizA,#subMatrizB, #squareAsubCh1, #squareAsubCh2, #squareAsubCh3, #squareAsubCh4, #squareBsubCh1, #squareBsubCh2, #squareBsubCh3, #squareBsubCh4, #aa, #bb, #cc, #dd, #ee, #ff, #gg, #hh, #subResultado"
        ).fadeOut();
        $(
          "#matrizA, #matrizB,#cuadroCh1,#cuadroCh2,#cuadroCh3,#cuadroCh4,#cuadroChb1,#cuadroChb2,#cuadroChb3,#cuadroChb4"
        ).fadeIn();
        $("#squareChR1, #squareChR2,#squareChR3,#squareChR4").fadeIn();
        break;
      case 27:
        $("#cuadroCh1,#cuadroChb1").css("background-color", "#D30DF6");
        $("#cuadroCh1,#cuadroChb1").css("border-color", "#D30DF6");

        $(
          "#cuadroCh2, #cuadroCh3, #cuadroCh4,#cuadroChb2,#cuadroChb3,#cuadroChb4"
        ).css("background-color", "#018ABE");
        $(
          "#cuadroCh2, #cuadroCh3, #cuadroCh4,#cuadroChb2,#cuadroChb3,#cuadroChb4"
        ).css("border-color", "#7B7D7D");
        $("#cuadroCodigo1").animate({ top: "385px" }); //ae
        break;
      case 28:
        $("#cuadroCh1").animate({ left: "180px" });
        $("#cuadroCh2").animate({ left: "100px" });

        $("#cuadroChb1").animate({ top: "185px" });
        $("#cuadroChb4").animate({ top: "90px" });

        $("#Resultado tr:nth-child(1) th:nth-child(1)").text(
          mult("a11", "b11") +
            mult("a12", "b21") +
            "+" +
            (mult("a13", "b31") + mult("a14", "b41"))
        );
        $("#Resultado tr:nth-child(1) th:nth-child(2)").text(
          mult("a11", "b12") +
            mult("a12", "b22") +
            "+" +
            (mult("a13", "b32") + mult("a14", "b42"))
        );
        $("#Resultado tr:nth-child(2) th:nth-child(1)").text(
          mult("a21", "b11") +
            mult("a22", "b21") +
            "+" +
            (mult("a23", "b31") + mult("a24", "b41"))
        );
        $("#Resultado tr:nth-child(2) th:nth-child(2)").text(
          mult("a21", "b12") +
            mult("a22", "b22") +
            "+" +
            (mult("a23", "b32") + mult("a24", "b42"))
        );

        $("#cuadroCodigo1").animate({ top: "405px" }); //bg
        break;
      case 29:
        $("#cuadroCh1").animate({ left: "100px" });
        $("#cuadroCh2").animate({ left: "180px" });

        $("#cuadroChb1").animate({ top: "90px" });
        $("#cuadroChb4").animate({ top: "185px" });

        $("#cuadroChb1").animate({ left: "430px" });
        $("#cuadroChb2").animate({ left: "350px" });

        $("#Resultado tr:nth-child(1) th:nth-child(3)").text(
          mult("a11", "b13") + mult("a12", "b23") + " + ¿?"
        );
        $("#Resultado tr:nth-child(1) th:nth-child(4)").text(
          mult("a11", "b14") + mult("a12", "b24") + " + ¿?"
        );
        $("#Resultado tr:nth-child(2) th:nth-child(3)").text(
          mult("a21", "b13") + mult("a22", "b23") + " + ¿?"
        );
        $("#Resultado tr:nth-child(2) th:nth-child(4)").text(
          mult("a21", "b14") + mult("a22", "b24") + " + ¿?"
        );

        $("#cuadroCodigo1").animate({ top: "425px" }); //af
        break;
      case 30:
        $("#cuadroCh1").animate({ left: "180px" });
        $("#cuadroCh2").animate({ left: "100px" });

        $("#cuadroChb1").animate({ top: "185px" });
        $("#cuadroChb3").animate({ top: "90px" });

        $("#Resultado tr:nth-child(1) th:nth-child(3)").text(
          mult("a11", "b13") +
            mult("a12", "b23") +
            "+" +
            (mult("a13", "b33") + mult("a14", "b43"))
        );
        $("#Resultado tr:nth-child(1) th:nth-child(4)").text(
          mult("a11", "b14") +
            mult("a12", "b24") +
            "+" +
            (mult("a13", "b34") + mult("a14", "b44"))
        );
        $("#Resultado tr:nth-child(2) th:nth-child(3)").text(
          mult("a21", "b13") +
            mult("a22", "b23") +
            "+" +
            (mult("a23", "b33") + mult("a24", "b43"))
        );
        $("#Resultado tr:nth-child(2) th:nth-child(4)").text(
          mult("a21", "b14") +
            mult("a22", "b24") +
            "+" +
            (mult("a23", "b34") + mult("a24", "b44"))
        );

        $("#cuadroCodigo1").animate({ top: "448px" }); //bh
        break;
      case 31:
        $("#cuadroCh1").animate({ top: "185px" });
        $("#cuadroCh1").animate({ left: "100px" });
        $("#cuadroCh4").animate({ left: "180px" });
        $("#cuadroCh4").animate({ top: "90px" });

        $("#cuadroChb1").animate({ left: "350px" });
        $("#cuadroChb1").animate({ top: "90px" });
        $("#cuadroChb2").animate({ left: "430px" });
        $("#cuadroChb2").animate({ top: "185px" });

        $("#Resultado tr:nth-child(3) th:nth-child(1)").text(
          mult("a31", "b11") + mult("a32", "b21") + " + ¿?"
        );
        $("#Resultado tr:nth-child(3) th:nth-child(2)").text(
          mult("a31", "b12") + mult("a32", "b22") + " + ¿?"
        );
        $("#Resultado tr:nth-child(4) th:nth-child(1)").text(
          mult("a41", "b11") + mult("a42", "b21") + " + ¿?"
        );
        $("#Resultado tr:nth-child(4) th:nth-child(2)").text(
          mult("a41", "b12") + mult("a42", "b22") + " + ¿?"
        );

        $("#cuadroCodigo1").animate({ top: "470px" }); //ce
        break;
      case 32:
        $("#cuadroCh1").animate({ left: "180px" });
        $("#cuadroCh3").animate({ left: "100px" });
        $("#cuadroCh3").animate({ top: "185px" });

        $("#cuadroChb1").animate({ top: "185px" });
        $("#cuadroChb4").animate({ top: "90px" });

        $("#Resultado tr:nth-child(3) th:nth-child(1)").text(
          mult("a31", "b11") +
            mult("a32", "b21") +
            "+" +
            (mult("a33", "b31") + mult("a34", "b41"))
        );
        $("#Resultado tr:nth-child(3) th:nth-child(2)").text(
          mult("a31", "b12") +
            mult("a32", "b22") +
            "+" +
            (mult("a33", "b32") + mult("a34", "b42"))
        );
        $("#Resultado tr:nth-child(4) th:nth-child(1)").text(
          mult("a41", "b11") +
            mult("a42", "b21") +
            "+" +
            (mult("a43", "b31") + mult("a44", "b41"))
        );
        $("#Resultado tr:nth-child(4) th:nth-child(2)").text(
          mult("a41", "b12") +
            mult("a42", "b22") +
            "+" +
            (mult("a43", "b32") + mult("a44", "b42"))
        );

        $("#cuadroCodigo1").animate({ top: "498px" }); //dg
        break;
      case 33:
        $("#cuadroCh1").animate({ left: "100px" });
        $("#cuadroCh3").animate({ left: "180px" });

        $("#cuadroChb1").animate({ top: "90px" });
        $("#cuadroChb1").animate({ left: "430px" });
        $("#cuadroChb3").animate({ top: "185px" });
        $("#cuadroChb3").animate({ left: "350px" });

        $("#Resultado tr:nth-child(3) th:nth-child(3)").text(
          mult("a31", "b13") + mult("a32", "b23") + " + ¿?"
        );
        $("#Resultado tr:nth-child(3) th:nth-child(4)").text(
          mult("a31", "b14") + mult("a32", "b24") + " + ¿?"
        );
        $("#Resultado tr:nth-child(4) th:nth-child(3)").text(
          mult("a41", "b13") + mult("a42", "b23") + " + ¿?"
        );
        $("#Resultado tr:nth-child(4) th:nth-child(4)").text(
          mult("a41", "b14") + mult("a42", "b24") + " + ¿?"
        );

        $("#cuadroCodigo1").animate({ top: "518px" }); //cf
        break;
      case 34:
        $("#cuadroCh1").animate({ left: "180px" });
        $("#cuadroCh3").animate({ left: "100px" });

        $("#cuadroChb1").animate({ top: "185px" });
        $("#cuadroChb2").animate({ top: "90px" });

        $("#Resultado tr:nth-child(3) th:nth-child(3)").text(
          mult("a31", "b13") +
            mult("a32", "b23") +
            "+" +
            (mult("a33", "b33") + mult("a34", "b43"))
        );
        $("#Resultado tr:nth-child(3) th:nth-child(4)").text(
          mult("a31", "b14") +
            mult("a32", "b24") +
            "+" +
            (mult("a33", "b34") + mult("a34", "b44"))
        );
        $("#Resultado tr:nth-child(4) th:nth-child(3)").text(
          mult("a41", "b13") +
            mult("a42", "b23") +
            "+" +
            (mult("a43", "b33") + mult("a44", "b43"))
        );
        $("#Resultado tr:nth-child(4) th:nth-child(4)").text(
          mult("a41", "b14") +
            mult("a42", "b24") +
            "+" +
            (mult("a43", "b34") + mult("a44", "b44"))
        );

        $("#cuadroCodigo1").animate({ top: "540px" }); //dh
        break;
      case 35:
        $("#Resultado tr:nth-child(1) th:nth-child(1)").text("30");
        $("#Resultado tr:nth-child(1) th:nth-child(2)").text("42");
        $("#Resultado tr:nth-child(2) th:nth-child(1)").text("43");
        $("#Resultado tr:nth-child(2) th:nth-child(2)").text("58");

        $("#Resultado tr:nth-child(1) th:nth-child(3)").text("54");
        $("#Resultado tr:nth-child(1) th:nth-child(4)").text("62");
        $("#Resultado tr:nth-child(2) th:nth-child(3)").text("73");
        $("#Resultado tr:nth-child(2) th:nth-child(4)").text("83");

        $("#Resultado tr:nth-child(3) th:nth-child(1)").text("50");
        $("#Resultado tr:nth-child(3) th:nth-child(2)").text("74");
        $("#Resultado tr:nth-child(4) th:nth-child(1)").text("62");
        $("#Resultado tr:nth-child(4) th:nth-child(2)").text("90");

        $("#Resultado tr:nth-child(3) th:nth-child(3)").text("92");
        $("#Resultado tr:nth-child(3) th:nth-child(4)").text("104");
        $("#Resultado tr:nth-child(4) th:nth-child(3)").text("111");
        $("#Resultado tr:nth-child(4) th:nth-child(4)").text("125");

        $("#squareChR1").fadeOut();
        $("#squareChR2").fadeOut();
        $("#squareChR3").fadeOut();
        $("#squareChR4").fadeOut();

        $("#squareChR1f").fadeIn();
        $("#squareChR2f").fadeIn();
        $("#squareChR3f").fadeIn();
        $("#squareChR4f").fadeIn();

        $("#cuadroCodigo1").fadeOut();
        $("#cuadroCodigoFinal").fadeIn();

        $("#siguiente").html("Reiniciar Animación");
        break;
      case 36:
        location.reload();
        break;
    }

    // Incrementamos el paso actual.
    paso = paso + 1;

    // Actualizamos el status.
    $("#status").html(`Paso: #${paso} - ${explicaciones[paso - 1]}`);
  });
});
