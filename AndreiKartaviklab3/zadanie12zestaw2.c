#include <stdio.h>
#include <ctype.h>

struct Towar {
    char NazwaTowaru[256];
    int LiczbaSztuk;
    double Cena1Sztuki;
} Towar;

void N(struct Towar T[], int k) {

    if (k > 49) {
        printf("Tablica wypełniona\n");
        return;
    }

    printf("Wprowadz nazwę towaru: ");
    scanf("%s", T[k].NazwaTowaru);

    printf("\nWprowadz Liczbę Sztuk: ");
    scanf("%d", &T[k].LiczbaSztuk);
    printf("\nWprowadz cenę: ");
    scanf("%lf", &T[k].Cena1Sztuki);
    printf("\n");

}

void W(struct Towar T[], int n) {

    for (int i = 0; i < n; i++) {
        printf("%s\n", T[i].NazwaTowaru);
    }
}

double R(struct Towar T[], int n) {

    double sum = 0;

    for (int i = 0; i < n; i++) {
        sum += T[i].Cena1Sztuki * T[i].LiczbaSztuk;
    }

    return sum;
}

int main(void) {
    
    int n = 50;
    int k = 0;
    struct Towar TablicaTowarow[n];
    char act;
    int flag = 1;
    
    while (flag == 1) {

        printf("N | n - nowy towar\nW | w - wyświetl wszystkie towary\nR | r - oblicz sumę wartości wszystkich towarow\nQ | q - koniec programu\nChoose action: ");

        scanf(" %c", &act);

        switch (tolower(act)) {
            case 'n':
                N(TablicaTowarow, k);
                k++;
                break;
            case 'w':
                W(TablicaTowarow, k);
                break;
            case 'r':
                printf("Sum: %lf\n", R(TablicaTowarow, k));
                break;
            case 'q':
                printf("Exit\n");
                flag = 0;
                break;
            default:
                flag = 0;
                break;
        }
    }
}