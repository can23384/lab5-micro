#include <stdio.h>
#include <omp.h>

#define N 1000000

int main() {
    int sum = 0;

    // Obtener el tiempo de inicio
    double start_time = omp_get_wtime();

    // Parallel for loop with reduction clause
    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= N; i++) {
        sum += i;
    }

    // Obtener el tiempo de finalización
    double end_time = omp_get_wtime();

    // Calcular el tiempo de ejecución
    double execution_time = end_time - start_time;

    // Mostrar el resultado y el tiempo de ejecución
    printf("La suma de los primeros %d números naturales es: %d\n", N, sum);
    printf("Tiempo de ejecución: %f segundos\n", execution_time);

    return 0;
}