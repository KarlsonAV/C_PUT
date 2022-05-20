#include <stdio.h>

int main(void) {

    int n,m;
    double R;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("\nEnter m: ");
    scanf("%d", &m);
    printf("\n");

    R = 0;
    for (int i = 1; i <= n; i++) {

        double P = 1;
        for (int j = 1; j <= m; j++) {
            P *= (double) (i * i + j * j - 1) / (2 * i + 3 * j + 4);
        }

        R += P;
    }

    printf("R = %lf\n", R);
    
}