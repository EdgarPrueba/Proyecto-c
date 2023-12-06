// -----Encabezado-----
// Programación bajo plataformas abiertas.
// Estudiantes:
//     Edgar Alvarado C10351
//     Charlie Arroyo B90765
// Fecha: 02-12-2023.
// Proyecto3 en C.
// Ingeniería Eléctrica.
// -----Descripción del programa-----
/* Se desea crear un programa que reciba una
   cantidad arbitraria de números enteros que representan la
   posición en una matriz NXM, lo cual debe poseer una
   memoria dinámica para colocar cada uno de los números
   ingresados por el usuario. Finalmente se le
   retorna al usuario las direcciones de memoria de los números que
   inician cada fila. */

// -----Desarrollo del programa-----
// Incluyendo librerías que permiten entradas y salidas en C.
#include <stdio.h>
#include <stdlib.h>

/* Función para asignar direcciones de inicio de cada fila
   por medio de punteros */
int *iniciar_filas(int n, int m, int *) {
    // Se reserva memoria para guardar las direcciones
    int *direcciones = (int *)malloc(n * sizeof(int));
    if (direcciones == NULL) {
        // Error en la asignación de memoria
        return NULL;  // Error al asignar memoria
    }

    // Se itera sobre las filas y se asignan las direcciones correspondientes.
    for (int i = 0; i < n; i++) {
        // Direcciones de inicio de cada fila.
        direcciones[i] = i * m;
    }

    return direcciones; // Se devuelve el arreglo con las direcciones
}

// Función principal (main).
int main() {
    int n, m;
    char opcion;

    do {
        // Solicitar al usuario el tamaño de la matriz
        printf("Ingrese el número de filas: ");
        scanf("%d", &n);
        printf("Ingrese el número de columnas: ");
        scanf("%d", &m);

        // Solicitando los números enteros para la matriz.
        printf("Ingrese los números enteros para la matriz (%d elementos): ", n * m);
        // Se reserva memoria para la matriz de enteros
        int *numeros = (int *)malloc(n * m * sizeof(int));
        if (numeros == NULL) {
            // Mensaje de error.
            printf("Error: no se pudo asignar memoria.\n");
            return -1;
        }

        // Solicitando los valores para la matriz
        for (int i = 0; i < n * m; i++) {
            scanf("%d", &numeros[i]);
        }

        // Se llama a la función para obtener las direcciones de inicio de cada fila
        int *direcciones = iniciar_filas(n, m, numeros);
        // Ciclo if, si las no se puede asignar memoria.
        if (direcciones == NULL) {
            printf("Error: no se pudo asignar memoria para las direcciones.\n");
            // Liberando memoria.
            free(numeros);
            return -1;
        }

        // Imprimiendo la dirección de inicio de cada fila en hexadecimal.
        printf("Direcciones de inicio de cada fila:\n");
        for (int i = 0; i < n; i++) {
            printf("Fila %d: %p\n", i + 1, (void *)&direcciones[i]);
        }
        // Liberando la memoria de la matriz
        free(numeros);
        // Liberando la memoria de las direcciones
        free(direcciones);
        // Consultar al usuario si desea repetir el programa.
        printf("¿Desea ejecutar de nuevo? (s/n): ");
        scanf(" %c", &opcion);
    // Ciclo while.
    } while (opcion == 's' || opcion == 'S');

    return 0;
}
