#include <stdio.h>
#include <omp.h>

#define N 10  
int arr[N] = {3, 29, 5, 7, 31, 19, 8, 12, 9, 2};


void factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    printf("Factorial de %d es %lld\n", n, fact);
}

void fibonacci(int n) {
    long long fib[N];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    printf("Serie Fibonacci hasta el termino %d: ", n);
    for (int i = 0; i < n; i++) {
        printf("%lld ", fib[i]);
    }
    printf("\n");
}


void findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("El maximo en el arreglo es %d\n", max);
}


int main() {

      #pragma omp parallel sections
    {
        #pragma omp section
        {
            factorial(N);
        }
        
        #pragma omp section
        {
            fibonacci(N);
        }
        
        #pragma omp section
        {
            findMax(arr, N);
        }
    }

    return 0;
}