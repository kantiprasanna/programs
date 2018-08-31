#include<stdio.h>

static int *product;
int *firstNumberDigits, *secondNumberDigits;


int length(char number[] );
void atoiFunction (char number[], int numberDigits[]);
void mul(char firstNumber[], char secondNumber[], int firstNumberCount, int secondNumberCount);


int main(int argc, char const *argv[])
{
    char firstNumber[10000], secondNumber[10000];
    int firstNumberCount, secondNumberCount;
    printf("Enter first number: ");
    scanf("%s", &firstNumber);
    printf("Enter second number: ");
    scanf("%s", &secondNumber); 
    

    firstNumberCount = length(firstNumber);
    secondNumberCount = length(secondNumber);

    firstNumberDigits = (int *)malloc(sizeof(int) * firstNumberCount);
    secondNumberDigits = (int *)malloc(sizeof(int) * secondNumberCount);
    product = (int *)malloc(sizeof(int) * (firstNumberCount + secondNumberCount));
    
    mul(firstNumber, secondNumber, firstNumberCount, secondNumberCount);
    return 0;
}

int length(char number[] ){
    int length = 0;
    for(int counter = 0; number[counter] != '\0'; counter++){
        length++;
    }
    return length;

}


void atoiFunction (char number[], int numberDigits[]){

    int lengthOfString;
    lengthOfString = length(number);
    for (int i = 0; number[i] != '\0'; ++i){
        numberDigits[lengthOfString - i - 1] = number[i] - '0';         
        
    }
}

void mul(char firstNumber[], char secondNumber[], int firstNumberCount, int secondNumberCount){
    
    for(int i = 0; i < firstNumberCount; i++){
        firstNumberDigits[i] = firstNumber[i] - '0';
    }   
    for(int i = 0; i < secondNumberCount; i++){
        secondNumberDigits[i] = secondNumber[i] - '0';

    }

    for(int i = 0; i < firstNumberCount; i++){
        printf("Debugg: first number is");
        printf(" %d\n", firstNumberDigits[i]);
    }

    for(int i = 0; i < secondNumberCount; i++ ){
        printf("Debugg: second number is %d\n", secondNumberDigits[i]);
    }
    // for(int i= firstNumberCount - 1, j = secondNumberCount - 1, k = 0; i >= 0, j >= 0, k < secondNumberCount; i--, j--, k++){
    //     product[i + j + k] += firstNumberDigits[i] * secondNumberDigits[j];
    //     printf("Debugg: product[%d + %d + %d] =  %d * %d = %d\n", i, j, k, firstNumberDigits[i], secondNumberDigits[j], product[i + j + k]);
    // }
    for(int i = firstNumberCount; i >= 0; i--){
        for(int j = secondNumberCount; j >= 0; j--){
            product[i + j + 1] += firstNumberDigits[i] * secondNumberDigits[j];
        }
    }
    for(int i = firstNumberCount + secondNumberCount; i > 0; i--){
        if(product[i]  > 9){
                product[i - 1] += product[i]/10;
                product[i] %= 10;
                printf("Debugg: product[%d] = %d\n", i, product[i]);
            }
    }
    printf("Product of %s and %s is ", firstNumber, secondNumber);
    for(int i = 0; i < firstNumberCount + secondNumberCount - 1; i++){
        printf("%d", product[i]);
    }
}
