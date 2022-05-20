#include <stdio.h>




int firstnumd(int firstNumber) {
    int firstDivisorSum = 0;
     for(int i=1;i<firstNumber;i++){
        if(firstNumber % i == 0){
            firstDivisorSum = firstDivisorSum + i;
        }
    }
    return firstDivisorSum;
}
int previous_amicable = 0;

void amicable_numbers(int firstNumber, int firstDivisorSum, int secondNumber)
{

    int i;
    int secondDivisorSum = 0;

    for(int i=1;i<secondNumber;i++){
        if(secondNumber % i == 0){
            secondDivisorSum = secondDivisorSum + i;
        }
    }

    if((firstNumber == secondDivisorSum) && (secondNumber == firstDivisorSum) && (previous_amicable != firstDivisorSum && previous_amicable != secondDivisorSum) ){

        printf("%d and %d are Amicable numbers\n",firstNumber,secondNumber);
        previous_amicable = firstDivisorSum;
    }

}


int main(void) {

    int a, idx;

    printf("Enter a: ");
    scanf("%d", &a);

    for (int i = 1; i <= a; i++) {
        int first = firstnumd(i);
        for (int j = 1; j <= a; j++) {
            if (i != j) {
                amicable_numbers(i, first, j);
            }
        }
    }

}