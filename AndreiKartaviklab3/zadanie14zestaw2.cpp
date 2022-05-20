#include <stdio.h>
#include <ctype.h>
#include <string>
#include <cstring>

struct Komputer {
    char Nazwa[256];
    char Producent[256];
    double Cena;
} Komputer;

void N(struct Komputer T[], int k) {

    
    printf("Wprowadz nazwę komputera: ");
    scanf("%s", T[k].Nazwa);
    printf("\nWprowadz nazwę producenta: ");
    scanf("%s", T[k].Producent);
    printf("\nWprowadz cenę: ");
    scanf("%lf", &T[k].Cena);
    
    printf("\n");

}

void S(struct Komputer T[], char find[], int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(find, T[i].Nazwa) == 0) {
            printf("Nazwa: %s\nProducent: %s\nCena: %lf\n", T[i].Nazwa, T[i].Producent, T[i].Cena);
            break;
        }
    }
} 

void W(struct Komputer T[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", T[i].Nazwa);
    }
}

int U(struct Komputer T[], char find[], int n, int k) {
    for (int i = 0; i < k; i++) {
        if (strcmp(find, T[i].Nazwa) == 0) {

            for (int j = i; j < k - 1; j++) {
                T[j] = T[j+1];

            }
            return --k;
        }
    }
    return k;
}


int main(void) {
    int n = 100;
    int k = 0;
    struct Komputer* TablicaTowarow;
    TablicaTowarow = new struct Komputer[n];
    char act;
    int flag = 1;
    
    while (flag == 1) {

        printf("N | n - nowy towar\nW | w - wyświetl wszystkie towary\nS | s - szukaj komputera wg nazwy\nU | u usuń komputer według nazwy\nQ | q - koniec programu\nChoose action: ");
        scanf(" %c", &act);
        printf("\n");
        switch (tolower(act)) {
            case 'n':
                if (k > n - 1) {

                    struct Komputer* TablicaTowarow1;
                    TablicaTowarow1 = new struct Komputer[n];
                    memcpy(TablicaTowarow1, TablicaTowarow, n * sizeof(struct Komputer));
                    int n = n * 2;
                    delete [] TablicaTowarow;
                    TablicaTowarow = TablicaTowarow1;
                }

                N(TablicaTowarow, k);
                k++;
                break;
            case 'w':
                W(TablicaTowarow, k);
                break;
            case 's':
                char komp[256];
                printf("Nazwa komputera: ");
                scanf("%s", komp);
                S(TablicaTowarow, komp, k);
                break;
            case 'u':
                char komp1[256];
                printf("Nazwa komputera: ");
                scanf("%s", komp1);
                printf("\n");
                k = U(TablicaTowarow, komp1, n, k);
                break;
            case 'q':
                printf("Exit\n");
                flag = 0;
                break;
            default:
                flag = 0;
                break;
        }
        printf("\n");
    }

    delete [] TablicaTowarow;
    
}