#include <stdio.h>
#include <omp.h>

#define N 10

int main() {
    int variable1 = 0;  
    int variable2 = 0;  

    #pragma omp parallel for shared(variable1) private(variable2)
    for (int i = 0; i < N; i++) {
        variable1 += i;  
        variable2 = i;   
        printf("Iteracion %d: variable1 = %d, variable2 = %d (hilo %d)\n", i, variable1, variable2, omp_get_thread_num());
    }

    return 0;
}
