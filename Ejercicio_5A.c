/*
 * Archivo: Ejercicio_5A.c
 * Descripción: Este programa cuenta cuántas veces aparece un valor específico 
 * ('key') en un arreglo de números aleatorios.
 * 
 * Funcionalidad:
 * - Genera un arreglo de tamaño N con valores aleatorios.
 * - Inserta manualmente el valor 'key' en tres posiciones específicas del arreglo.
 * - Cuenta cuántas veces aparece 'key' en el arreglo usando una función llamada count_key().
 * - Imprime el número de apariciones de 'key' en el arreglo.
 * 
 * Referencia:
 * Chandra, . R. et al. Parallel Programming in OpenMP
 *
 * Fecha modificación: 08-16-2024
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 131072

long count_key_parallel(long *a, long key, long start, long end) {
    long count = 0;

    if (end - start == 1) {
        if (a[start] == key) count++;
    } else {
        long mid = (start + end) / 2;
        long count1 = 0, count2 = 0;

        #pragma omp task shared(count1)
        count1 = count_key_parallel(a, key, start, mid);

        #pragma omp task shared(count2)
        count2 = count_key_parallel(a, key, mid, end);

        #pragma omp taskwait
        count = count1 + count2;
    }

    return count;
}

int main() {
    long a[N], key = 42, nkey = 0;

    #pragma omp parallel for
    for (long i = 0; i < N; i++) a[i] = rand() % N;

    a[N % 43] = key; 
    a[N % 73] = key; 
    a[N % 3] = key;

    #pragma omp parallel
    {
        #pragma omp single
        nkey = count_key_parallel(a, key, 0, N);
    }

    printf("El numero de apariciones de %ld es %ld\n", key, nkey);

    return 0;
}