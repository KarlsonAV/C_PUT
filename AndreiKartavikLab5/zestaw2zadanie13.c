#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Student {
    char Nazwisko[256];
    char Imie[256];
    int NrAlbumu;
} Student;

typedef struct Programowanie {
    int NrAlbumu;
    double ocena;
} Programowanie;

typedef struct Fizyka {
    int NrAlbumu;
    double ocena;
} Fizyka;

void N(Student Students[], Programowanie p_oceny[], Fizyka f_oceny[], int n, int M, int K) {
    
    char nazwisko[256];
    printf("Wprowadz nazwisko studenta: ");
    scanf("%s", nazwisko);
    int numerAlbumu;
    for (int i = 0; i < n; i++) {
        if (strcmp(nazwisko, Students[i].Nazwisko) == 0) {
            numerAlbumu = Students[i].NrAlbumu;
            printf("Imie: %s\n", Students[i].Imie);
            printf("Nazwisko: %s\n", Students[i].Nazwisko);
            break;
        }
    }

    for (int i = 0; i < M; i++) {
        if (p_oceny[i].NrAlbumu == numerAlbumu) {
            printf("Ocena z programowania: %.1lf\n", p_oceny[i].ocena);
            break;
        }
    }

    for (int i = 0; i < K; i++) {
        if (f_oceny[i].NrAlbumu == numerAlbumu) {
            printf("Ocena z fizyki: %.1lf\n", f_oceny[i].ocena);
            break;
        }
    }

}

void A(Student Students[], Programowanie p_oceny[], Fizyka f_oceny[], int n, int M, int K) {
    
    int numerAlbumu;
    printf("Wprowadz numer albumu studenta: ");
    scanf("%d", &numerAlbumu);
    
    for (int i = 0; i < n; i++) {
        if (numerAlbumu == Students[i].NrAlbumu) {
            printf("Imie: %s\n", Students[i].Imie);
            printf("Nazwisko: %s\n", Students[i].Nazwisko);
            break;
        }
    }

    for (int i = 0; i < M; i++) {
        if (p_oceny[i].NrAlbumu == numerAlbumu) {
            printf("Ocena z programowania: %.1lf\n", p_oceny[i].ocena);
            break;
        }
    }

    for (int i = 0; i < K; i++) {
        if (f_oceny[i].NrAlbumu == numerAlbumu) {
            printf("Ocena z fizyki: %.1lf\n", f_oceny[i].ocena);
            break;
        }
    }

}

int main(void) {
    FILE *s = fopen("Studenci.txt", "r");
    FILE *p = fopen("Programowanie.txt", "r");
    FILE *f1 = fopen("Fizyka.txt", "r");

    if (s == NULL || p == NULL || f1 == NULL) {
        printf("Error occured\n");
        return 1;
    }

    Student Students[100];
    Programowanie p_oceny[100];
    Fizyka f_oceny[100];

    int k = 0;
    int act = 0;
    char line[256];
    int n;
    int f = 0;
     while (fgets(line, sizeof line, s) != NULL) {
         if (f == 0) {
             f = 1;
             continue;
         }

         if (act == 0) {
             for (int i = 0; i < strlen(line) - 1; i++) {
                 Students[k].Nazwisko[i] = line[i];
             }
         }

         else if (act == 1) {
             for (int i = 0; i < strlen(line) - 1; i++) {
                 Students[k].Imie[i] = line[i];
             }
         }
         else if (act == 2) {
             int val;
             while (sscanf(line, "%d%n", &val, &n) == 1) {
                Students[k].NrAlbumu = val;
                break;
            }

         }
    
         if (act == 2) {
             act = 0;
             k++;
         }

         else {
             act++;
         }
       
    }

    int n1 = 0;
    f = 0;
    while (fgets(line, sizeof line, f1) != NULL) {
        if (f == 0) {
            f = 1;
            continue;
        }
        if (act == 0) {
            int val;
             while (sscanf(line, "%d%n", &val, &n) == 1) {
                f_oceny[n1].NrAlbumu = val;
                break;
            }

        }
        else if (act == 1) {
            double val;
             while (sscanf(line, "%lf%n", &val, &n) == 1) {
                f_oceny[n1].ocena = val;
                break;
            }

        }

        if (act == 1) {
             act = 0;
             n1++;
         }

        else {
             act++;
         }
    }

    int M = 0;
    f = 0;
    while (fgets(line, sizeof line, p) != NULL) {
        if (f == 0) {
            f = 1;
            continue;
        }
        if (act == 0) {
            int val;
             while (sscanf(line, "%d%n", &val, &n) == 1) {
                p_oceny[M].NrAlbumu = val;
                break;
            }

        }
        else if (act == 1) {
            double val;
             while (sscanf(line, "%lf%n", &val, &n) == 1) {
                p_oceny[M].ocena = val;
                break;
            }

        }

        if (act == 1) {
             act = 0;
             M++;
         }

        else {
             act++;
         }
    }

    fclose(s);
    fclose(p);
    fclose(f1);

    char c;
    int koniec = 0;
   
    do {
        printf("\nChoose action: A, N, Q: ");
        scanf(" %c", &c);
        printf("\n");
        switch(c) {
            case 'A':
                A(Students, p_oceny, f_oceny, k, M, n1);
                break;
            case 'N':
                N(Students, p_oceny, f_oceny, k, M, n1);
                break;
            default:
                koniec = 1;
                break;
        }
        
        

    } while (koniec == 0);

}