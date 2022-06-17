/**
 * Script de animación para Divide y Vencerás.
 */

function quitarBordes(elemento) {
  elemento.classList.remove(
    "borde-rojo",
    "borde-verde",
    "borde-negro",
    "borde-azul"
  );
}

// Extraemos nuestros elementos del DOM.
let matrizA = document.getElementById("matrizA");
let matrizB = document.getElementById("matrizB");
let matrizC = document.getElementById("matrizC");
let submatrizA1 = document.getElementById("submatrizA1");
let submatrizA2 = document.getElementById("submatrizA2");
let submatrizA3 = document.getElementById("submatrizA3");
let submatrizA4 = document.getElementById("submatrizA4");
let submatrizB1 = document.getElementById("submatrizB1");
let submatrizB2 = document.getElementById("submatrizB2");
let submatrizB3 = document.getElementById("submatrizB3");
let submatrizB4 = document.getElementById("submatrizB4");
let submatrizC1 = document.getElementById("submatrizC1");
let submatrizC2 = document.getElementById("submatrizC2");
let submatrizC3 = document.getElementById("submatrizC3");
let submatrizC4 = document.getElementById("submatrizC4");
let a11 = document.getElementById("a11");
let a12 = document.getElementById("a12");
let a13 = document.getElementById("a13");
let a14 = document.getElementById("a14");
let a21 = document.getElementById("a21");
let a22 = document.getElementById("a22");
let a23 = document.getElementById("a23");
let a24 = document.getElementById("a24");
let a31 = document.getElementById("a31");
let a32 = document.getElementById("a32");
let a33 = document.getElementById("a33");
let a34 = document.getElementById("a34");
let a41 = document.getElementById("a41");
let a42 = document.getElementById("a42");
let a43 = document.getElementById("a43");
let a44 = document.getElementById("a44");
let b11 = document.getElementById("b11");
let b12 = document.getElementById("b12");
let b13 = document.getElementById("b13");
let b14 = document.getElementById("b14");
let b21 = document.getElementById("b21");
let b22 = document.getElementById("b22");
let b23 = document.getElementById("b23");
let b24 = document.getElementById("b24");
let b31 = document.getElementById("b31");
let b32 = document.getElementById("b32");
let b33 = document.getElementById("b33");
let b34 = document.getElementById("b34");
let b41 = document.getElementById("b41");
let b42 = document.getElementById("b42");
let b43 = document.getElementById("b43");
let b44 = document.getElementById("b44");
let c11 = document.getElementById("c11");
let c12 = document.getElementById("c12");
let c13 = document.getElementById("c13");
let c14 = document.getElementById("c14");
let c21 = document.getElementById("c21");
let c22 = document.getElementById("c22");
let c23 = document.getElementById("c23");
let c24 = document.getElementById("c24");
let c31 = document.getElementById("c31");
let c32 = document.getElementById("c32");
let c33 = document.getElementById("c33");
let c34 = document.getElementById("c34");
let c41 = document.getElementById("c41");
let c42 = document.getElementById("c42");
let c43 = document.getElementById("c43");
let c44 = document.getElementById("c44");
let a = [
  [a11, a12, a13, a14],
  [a21, a22, a23, a24],
  [a31, a32, a33, a34],
  [a41, a42, a43, a44],
];
let b = [
  [b11, b12, b13, b14],
  [b21, b22, b23, b24],
  [b31, b32, b33, b34],
  [b41, b42, b43, b44],
];
let c = [
  [c11, c12, c13, c14],
  [c21, c22, c23, c24],
  [c31, c32, c33, c34],
  [c41, c42, c43, c44],
];
let boton = document.getElementById("siguiente");

// Variables globales.
let paso_animacion = 1,
  contador_pasos = 0;

// Verificamos las celdas y llenamos si están vacías.
for (let i = 0; i < 4; i++) {
  for (let j = 0; j < 4; j++) {
    a[i][j].disabled = false;
    b[i][j].disabled = false;
    c[i][j].innerHTML = "0";
  }
}

boton.addEventListener("click", () => {
  // Yep.
  switch (paso_animacion) {
    case 1:
      // Inicializamos contadores.
      contador_pasos = 0;
      // Cambiamos el texto del botón.
      boton.textContent = "Siguiente";
      // Verificamos las celdas y llenamos si están vacías.
      for (let i = 0; i < 4; i++) {
        for (let j = 0; j < 4; j++) {
          if (!a[i][j].value) {
            a[i][j].value = Math.floor(Math.floor(Math.random() * 9) + 1);
          }
          if (!b[i][j].value) {
            b[i][j].value = Math.floor(Math.floor(Math.random() * 9) + 1);
          }

          // Desactivamos los inputs.
          a[i][j].disabled = true;
          b[i][j].disabled = true;
        }
      }
      // Mostramos las matrices realtadas.
      quitarBordes(matrizA);
      matrizA.classList.add("borde-azul");
      quitarBordes(matrizB);
      matrizB.classList.add("borde-rojo");
      quitarBordes(matrizC);
      matrizC.classList.add("borde-verde");

      // Incrementamos el contador del paso de la animación.
      paso_animacion++;
      break;
    case 2:
      // Quitamos los bordes de las matrices de colores.
      quitarBordes(matrizA);
      matrizA.classList.add("borde-negro");
      quitarBordes(matrizB);
      matrizB.classList.add("borde-negro");
      quitarBordes(matrizC);
      matrizC.classList.add("borde-negro");
      // Mostramos las subdivisiones posibles de la matriz A.
      quitarBordes(submatrizA1);
      quitarBordes(submatrizA2);
      quitarBordes(submatrizA3);
      quitarBordes(submatrizA4);
      submatrizA1.classList.add("borde-azul");
      submatrizA2.classList.add("borde-rojo");
      submatrizA3.classList.add("borde-verde");
      submatrizA4.classList.add("borde-negro");

      alert("what the fuck!");

      // Actualizamos el contador.
      break;
    default:
      break;
  }
});
