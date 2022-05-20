#include <stdio.h>
#include <math.h>

int main(void) {

    int n;
    double S,a;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("\nEnter a: ");
    scanf("%lf", &a);
    printf("\n");

    S = 0;
    for (int i = 1; i <= n; i++) {
        S += (a * pow(i,3) - 7) / (i * i + 1);
    }

    printf("S = %lf\n", S);

}
