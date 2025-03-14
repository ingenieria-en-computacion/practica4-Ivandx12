#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 40


// Crea un tipo de dato estudiante que guarde el nombre del estudiante max. 40 caracteres y su edad
typedef struct {
    char nombre[TAM];
    int edad;
} Estudiante;

int main() {

    int size = 2;
    // Crea un arreglo dinámico usando malloc de tamaño size
    Estudiante *arr=(Estudiante*)malloc(size *sizeof (Estudiante));
    //Si el arreglo es nulo imprime el mensaje
    if(arr == NULL){
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    int count = 0;
    char nombre[50];
    int edad;
    printf("Ingrese estudiantes (nombre y edad, ingrese 'fin' para terminar):\n");
    while (1) {
        printf("Nombre: ");
        scanf("%s", nombre);
        if (strcmp(nombre, "fin") == 0) break;

        printf("Edad: ");
        scanf("%d", &edad);

        if (count >= size) {
            size *= 2;
            //Cambia el tamaño del arreglo
            Estudiante *temp = ((Estudiante*)realloc(arr, size *sizeof(Estudiante))) ;
            //Verifica nuevamente que si apunta a nulo se imprima el error
            if ( temp == NULL) {
                printf("Error: No se pudo reasignar memoria.\n");
                free(arr);
                return 1;   
            }
            arr = temp;
        }
        //copia el nombre leido en el nuevo estudiante y su edad
        strcpy(arr[count].nombre, nombre);
        arr[count].edad = edad;
        count++;
    }

    printf("Lista de estudiantes:\n");
    for (int i = 0; i < count; i++) {
        printf("Nombre: %s, Edad: %d\n", arr[i].nombre, arr[i].edad);
    }

    //libera la memoria
    free(arr);
    arr=NULL;
    return 0;
}
