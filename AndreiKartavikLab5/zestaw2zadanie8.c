#include <stdio.h>

typedef struct Pomiary {
    int numer_serii;
    double pomiar_1;
    double pomiar_2;
    double pomiar_3;
    double pomiar_4;
    int kod;
} Pomiary;


int main(void) {

    Pomiary P[100];
    FILE *in = fopen("Pomiary.txt", "r");
    FILE *out = fopen("Wyniki.txt", "w");
    if (in == NULL || out == NULL) {
        printf("Some error occured\n");
        return 1;
    }
    int n = 0;
    
    int k = 0;
    while (!feof(in)) {
        switch(n) {
            case 0:
                fscanf(in, "%d", &P[k].numer_serii);
                break;
            case 1:
                fscanf(in, "%lf", &P[k].pomiar_1);
                break;
            case 2:
                fscanf(in, "%lf", &P[k].pomiar_2);
                break;
            case 3:
                fscanf(in, "%lf", &P[k].pomiar_3);
                break;
            case 4:
                fscanf(in, "%lf", &P[k].pomiar_4);
                break;
            case 5:
                fscanf(in, "%d", &P[k].kod);
                break;
            default:
                printf("Error\n");
                break;
        }
        if (n == 5) {
            k++;
            n = 0;
        }
        else {
            n++;
        }
    }

    fclose(in);

    double val;
    double arr[4];
    double max;
    double min;
    for (int i = 0; i < k; i++) {
        switch (P[i].kod)
        {
        case 0:
            val = (double) (P[i].pomiar_1 + P[i].pomiar_2 + P[i].pomiar_3 + P[i].pomiar_4) / 4;
            fprintf(out, "Numer serii: %d\nWyliczona wartość: %.2lf\nKod sposobu przetwarzania: %d\n\n", P[i].numer_serii, val, P[i].kod);
            break;
        case 1:
            arr[0] = P[i].pomiar_1;
            arr[1] = P[i].pomiar_2;
            arr[2] = P[i].pomiar_3;
            arr[3] = P[i].pomiar_4;

            max = arr[0];
            for (int j = 1; j < 4; j++) {
                if (arr[j] > max) max = arr[j]; 
            }
            fprintf(out, "Numer serii: %d\nWyliczona wartość: %.2lf\nKod sposobu przetwarzania: %d\n\n", P[i].numer_serii, max, P[i].kod);
            break;
        
        case 2:
            arr[0] = P[i].pomiar_1;
            arr[1] = P[i].pomiar_2;
            arr[2] = P[i].pomiar_3;
            arr[3] = P[i].pomiar_4;

            min = arr[0];
            for (int j = 1; j < 4; j++) {
                if (arr[j] < min) min = arr[j]; 
            }
            fprintf(out, "Numer serii: %d\nWyliczona wartość: %.2lf\nKod sposobu przetwarzania: %d\n\n", P[i].numer_serii, min, P[i].kod);
            break;
        default:
            break;
        }
    }
    
    fclose(out);
}