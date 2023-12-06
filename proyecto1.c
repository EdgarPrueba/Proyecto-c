// -----Encabezado-----
// Programación bajo plataformas abiertas.
// Estudiantes:
//             Edgar Alvarado C10351, participacion:100 
//             Charlie Arroyo B90765, participacion:100 
// Fecha: 09-12-2023
// Proyecto #1 en C.
// Ingeniería Eléctrica.
// -----Descripción del programa-----
/*Este programa, segun lo que el usuario escriba muestra en pantalla 
cual es la ruta mas corta entre dos ciudades  y su distancia, los calculos fueron
manuales pero se hizo el intento, piedad. :( */

// -----Desarrollo del programa-----
#include <stdio.h>
#include <string.h> // para llamar a funciones de copia de cadenas

int main() {
  // Declarar las variables para el punto de entrada y el punto de salida
  char entrada, salida;

  // Pedir al usuario que digite el punto de entrada
  printf("Digite el punto de entrada:\n");
  scanf(" %c", &entrada);

  // Pedir al usuario que digite el punto de salida
  printf("Digite el punto de salida:\n");
  scanf(" %c", &salida);

  // Declarar las variables para el recorrido y la distancia
  char recorrido[27];
  int distancia;

  // Usar if y else para asignar el recorrido y la distancia según el punto de entrada y el punto de salida
  if (entrada == 'A' && salida == 'B') {
    strcpy(recorrido, "A -> D -> C -> E -> B");
    distancia = 10;
  } else if (entrada == 'A' && salida == 'C') {
    strcpy(recorrido, "A -> D -> C");
    distancia = 7;
  } else if (entrada == 'A' && salida == 'D') {
    strcpy(recorrido, "A -> D");
    distancia = 5;
  } else if (entrada == 'A' && salida == 'E') {
    strcpy(recorrido, "A -> D -> E");
    distancia = 6;
  } else if (entrada == 'A' && salida == 'F') {
    strcpy(recorrido, "A -> D -> B -> F");
    distancia = 15;
  } else if (entrada == 'B' && salida == 'A') {
    strcpy(recorrido, "B -> E -> D -> A");
    distancia = 10;
  } else if (entrada == 'B' && salida == 'C') {
    strcpy(recorrido,"B -> C");
    distancia = 4;
  } else if (entrada == 'B' && salida == 'D') {
    strcpy(recorrido,"B -> E -> D");
    distancia = 2;
  } else if (entrada == 'B' && salida == 'E') {
    strcpy(recorrido,"B -> E");
    distancia = 1;
  } else if (entrada == 'B' && salida == 'F') {
    strcpy(recorrido,"B -> F");
    distancia = 4;
  } else if (entrada == 'C' && salida == 'A') {
    strcpy(recorrido, "C -> D -> A");
    distancia = 7;
  } else if (entrada == 'C' && salida == 'B') {
    strcpy(recorrido,"C -> B");
    distancia = 4;
  } else if (entrada == 'C' && salida == 'D') {
    strcpy(recorrido, "C -> D");
    distancia = 2;
  } else if (entrada == 'C' && salida == 'E') {
    strcpy(recorrido, "C -> E");
    distancia = 2;
  } else if (entrada == 'C' && salida == 'F') {
    strcpy(recorrido, "C -> B -> F");
    distancia = 8;
  } else if (entrada == 'D' && salida == 'A') {
    strcpy(recorrido,"D -> A");
    distancia = 5;
  } else if (entrada == 'D' && salida == 'B') {
    strcpy(recorrido, "D -> B");
    distancia = 6;
  } else if (entrada == 'D' && salida == 'C') {
    strcpy(recorrido, "D -> C");
    distancia = 2;
  } else if (entrada == 'D' && salida == 'E') {
    strcpy(recorrido, "D -> E");
    distancia = 1;
  } else if (entrada == 'D' && salida == 'F') {
    strcpy(recorrido, "D -> B -> F");
    distancia = 10;
  } else if (entrada == 'E' && salida == 'A') {
    strcpy(recorrido, "E -> D -> A");
    distancia = 6;
  } else if (entrada == 'E' && salida == 'B') {
    strcpy(recorrido, "E -> B");
    distancia = 1;
  } else if (entrada == 'E' && salida == 'C') {
    strcpy(recorrido, "E -> C");
    distancia = 2;
  } else if (entrada == 'E' && salida == 'D') {
    strcpy(recorrido, "E -> D");
    distancia = 1;
  } else if (entrada == 'E' && salida == 'F') {
    strcpy(recorrido, "E -> B -> F");
    distancia = 5;
  } else if (entrada == 'F' && salida == 'A') {
    strcpy(recorrido, "F -> B -> E -> D -> A");
    distancia = 15;
  } else if (entrada == 'F' && salida == 'B') {
    strcpy(recorrido, "F -> B");
    distancia = 4;
  } else if (entrada == 'F' && salida == 'C') {
    strcpy(recorrido, "F -> B -> C");
    distancia = 8;
  } else if (entrada == 'F' && salida == 'D') {
    strcpy(recorrido, "F -> B -> E -> D");
    distancia = 10;
  } else if (entrada == 'F' && salida == 'E') {
    strcpy(recorrido, "F -> B -> E");
    distancia = 5;
  } else {
    strcpy(recorrido, "No hay camino");
    distancia = -1;
  }

  // Imprimir el recorrido y la distancia
  if (distancia != -1) {
    printf("El camino más corto de %c a %c es: %s\n", entrada, salida, recorrido);
    printf("La distancia es: %d\n", distancia);
  } else {
    printf("No hay camino posible de %c a %c\n", entrada, salida);
  }

  return 0;
}
