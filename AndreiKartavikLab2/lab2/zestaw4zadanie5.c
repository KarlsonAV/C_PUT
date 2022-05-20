#include <stdio.h>

int perfect_number(int n) {

    int sum[n/2 + 1];
    int idx = 0;

    for (int i = 1; i < n; i++) {
        
        if (n % i == 0) {
            sum[idx++] = i;
        }
    }
    int res = 0;
    for (int i = 0; i < idx; i++) {
        res += sum[i];
    }

    if (res == n) {
        return 1;
    }

    return 0;
}


int main(void) {

    int a, idx;

    printf("Enter n: ");
    scanf("%d", &a);

    int perfect_numbers[a];

    idx = 0;
    for (int i = 1; i <= a; i++) {
        if (perfect_number(i) == 1) {
            perfect_numbers[idx++] = i;
        }
    }

    printf("Perfect numbers: ");
    for (int i = 0; i < idx; i++) {
        printf("%d ", perfect_numbers[i]);
    }

    printf("\n");
}
