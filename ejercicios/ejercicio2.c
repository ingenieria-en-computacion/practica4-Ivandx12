#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;
    printf("Ingrese el número de filas: ");
    scanf("%d", &n);

    printf("Ingrese el número de columnas: ");
    scanf("%d", &m);

    int *matrix = (int *)calloc(m * n, sizeof(int));
    if (matrix == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    printf("Matriz inicializada con ceros:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <  m; j++) {
            printf("%d," , matrix[i * n + j]);
            
        }
        printf("\n");
    }

    printf("Ingrese las coordenadas (fila, columna) y el valor para modificar (ej. 1 2 5):\n");
    int row, col, value;
    //lee los varlores solicitados
    scanf("%d %d %d", &row, &col, &value);
    matrix[(row-1) * n + (col-1)] = value;

    printf("Matriz actualizada:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d," , matrix[i * m + j]);
        }
        printf("\n");
    }

    free(matrix);
    return 0;
}
