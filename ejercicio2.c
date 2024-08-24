#include <stdio.h>
#include <omp.h>

const int N = 1000000000;  

int main() {
    long long sum = 0;  
    double start_time, end_time;


    start_time = omp_get_wtime();

    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= N; i++) {
        sum += i;
    }

    end_time = omp_get_wtime();

    printf("La suma de los primeros %d numeros naturales es: %lld\n", N, sum);
    printf("Tiempo de ejecucion: %f segundos\n", end_time - start_time);

    return 0;
}