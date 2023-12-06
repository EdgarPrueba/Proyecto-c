// -----Encabezado-----
// Programación bajo plataformas abiertas.
// Estudiantes:
//             Edgar Alvarado C10351, participacion:100 
//             Charlie Arroyo B90765, participacion:100 
// Fecha: 09-12-2023
// Proyecto #1 en C.
// Ingeniería Eléctrica.
// -----Descripción del programa-----

/* Se debe ejecutar como: gcc proyecto2.c -o exe lm */
/*Este programa recibe las coordenadas de un polígono bidimensional (de un maximo de n lados) y el programa
calcula todos los ángulos internos, donde solamente serán válidos los polígonos
convexos :( */

// -----Desarrollo del programa-----

#include <stdio.h>
#include <stdlib.h>
#include <math.h>    // Inclusión de la biblioteca estándar de funciones matemáticas

typedef struct {
    float x, y;  // Definición de una estructura llamada Punto con dos miembros: x e y
} Punto;  // Alias para referirse a la estructura como 'Punto'

// Función para calcular el producto cruz de tres puntos en un plano bidimensional
// Indica si los puntos forman una orientación en sentido horario, antihorario
// o si son colineales, lo que establece su convexidad y colinealidad.
float calcularProductoCruz(Punto a, Punto b, Punto c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

// Función para determinar si un polígono es convexo o no.
// Utiliza el signo del producto cruz entre tres puntos consecutivos.
int esConvexo(Punto puntos[], int numLados) {
    int i;
    int signo = 0;

    // Iterar sobre los puntos del polígono
    for (i = 0; i < numLados; i++) {
        // Calcular el producto cruz entre tres puntos consecutivos
        float productoCruz = calcularProductoCruz(puntos[i], puntos[(i + 1) % numLados], puntos[(i + 2) % numLados]);

        // Verificar si el producto cruz es diferente de cero
        if (productoCruz != 0) {
            // Si es el primer producto cruz no nulo, establecer el signo
            if (signo == 0) {
                signo = productoCruz > 0 ? 1 : -1; // Establecer el signo según el producto cruz
            } 
            // Si ya se ha establecido un signo, verificar si hay cambio de signo
            else if (productoCruz > 0 && signo == -1) {
                return 0; // No es convexo, se detectó un cambio de signo
            } 
            else if (productoCruz < 0 && signo == 1) {
                return 0; // No es convexo, se detectó un cambio de signo
            }
        }
    }

    // Si no se encontraron cambios de signo en los productos cruz, el polígono es convexo
    return 1;
}

// Función para calcular el ángulo entre tres puntos en un plano bidimensional
// utilizando la ley de cosenos.
float calcularAngulo(Punto a, Punto b, Punto c) {
    // Calcular las longitudes de los lados del triángulo usando el teorema de Pitágoras
    float ladoAB = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
    float ladoBC = sqrt(pow(c.x - b.x, 2) + pow(c.y - b.y, 2));
    float ladoCA = sqrt(pow(a.x - c.x, 2) + pow(a.y - c.y, 2));

    // Manejar el caso de colinealidad
    if (ladoAB == 0 || ladoBC == 0 || ladoCA == 0) {
        // Devolver un valor especial para indicar colinealidad
        // -1.0 indica que los puntos son colineales y no se puede calcular un ángulo válido
        return -1.0; 
    }

    // Calcular el ángulo utilizando la ley de cosenos
    return acos((pow(ladoAB, 2) + pow(ladoBC, 2) - pow(ladoCA, 2)) / (2 * ladoAB * ladoBC));
}



int main() {
    int numLados;

    // Solicitar al usuario ingresar el número de lados del polígono
    printf("Ingrese el número de lados del polígono (mayor o igual a 3): ");
    scanf("%d", &numLados);

    // Verificar la validez del número de lados
    if (numLados < 3) {
        // Imprimir un mensaje de error si el número de lados no es válido
        printf("Número de lados no válido. Deben ser al menos 3.\n");
        return 1; // Retornar 1 para indicar un error
    }
    // Declarar un puntero a Punto y asigna memoria dinámica según la cantidad de lados
    // ingresada por el usuario
    Punto *puntos;
    // Asignar memoria dinámica para el arreglo de puntos del polígono
    puntos = (Punto*)malloc(numLados * sizeof(Punto));

    if (puntos == NULL) {
        printf("Error al asignar memoria para el arreglo de puntos.\n");

        return 1;
    }


    // Solicitar al usuario ingresar las coordenadas de cada punto del polígono
    for (int i = 0; i < numLados; i++) {
        printf("Ingrese las coordenadas (x y) del punto %d: ", i + 1);
        scanf("%f %f", &puntos[i].x, &puntos[i].y);
    }

    // Verificar si el polígono es convexo utilizando la función esConvexo
    if (!esConvexo(puntos, numLados)) {
        // Imprimir un mensaje si el polígono no es convexo y salir con código de error
        printf("El polígono no es convexo.\n");
        free(puntos);
        return 1; // Retornar 1 para indicar un error
    }

    printf("\nÁngulos internos:\n");

    // Declarar un puntero a float para almacenar los ángulos
    float *angulos;

    // Asignar memoria dinámica para el arreglo de ángulos
    angulos = (float*)malloc(numLados * sizeof(float));

    // Verificar si se asignó correctamente la memoria
    if (angulos == NULL) {
        printf("Error al asignar memoria para el arreglo de ángulos.\n");
        free(puntos);
        return 1;
    }

    // Calcular y almacenar los ángulos en el arreglo
    for (int i = 0; i < numLados; i++) {
        angulos[i] = calcularAngulo(puntos[(i + numLados - 1) % numLados], puntos[i], puntos[(i + 1) % numLados]);
    }

    // Verificar si hay algún ángulo mayor o igual a 180 grados
    int poligonoConvexo = 1; // Suponemos que el polígono es convexo
    for (int i = 0; i < numLados; i++) {
        if (angulos[i] == -1.0) {
            printf("Los puntos son colineales. No se puede calcular un ángulo válido.\n");
            free(puntos);
            free(angulos); // Liberar la memoria del arreglo de ángulos
            return 1;
        }

        if (angulos[i] >= M_PI) {
            poligonoConvexo = 0;
            break; // Salir del bucle si se encuentra un ángulo no válido
        }
    }

    // Imprimir los resultados si el polígono es convexo
    if (poligonoConvexo) {
        for (int i = 0; i < numLados; i++) {
            printf("Ángulo %d: %.2f grados\n", i + 1, angulos[i] * (180.0 / M_PI));
        }
    } else {
        printf("El polígono no es convexo. Se encontró un ángulo mayor o igual a 180 grados.\n");
    }

    // Liberar la memoria del arreglo de ángulos
    free(angulos);

    free(puntos);
    return 0; // Retornar 0 para indicar éxito
}
