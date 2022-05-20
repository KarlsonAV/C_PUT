#include <stdio.h>
#include <math.h>

int sum_of_10(int n) {
    if (n % 10 == n) {
        return n;
    }
    return n % 10 + sum_of_10(n/10);
}


int main(void) {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("\n");

    printf("Sum = %d\n", sum_of_10(n));
} 