#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {
    int n;
    printf("Input n: ");
    scanf("%d", &n);
    int arr[n];
    int state[n];

    clock_t start, end;
    double cpu_time_used;
    
    for (int i = 0; i < n; i++) {
        arr[i] = i;
        state[i] = 0;
    }

    start = clock();
    for (int i = 2; i * i < n; i++) {
        if (state[i] == 0) {
            for (int j = i * i; j < n; j += i) {
                state[j] = 1;
            }
        }
    }

    printf("Prime numbers: \n");
    for (int i = 2; i < n; i++) {
        if (state[i] == 0) {
            printf("%d ", arr[i]);
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime used: %lf\n", cpu_time_used);
}