#include<stdio.h>

char firstNumber[100000], secondNumber[100000];
int firstNumberCount, secondNumberCount;
int difference;
int *firstNumberDigits, *secondNumberDigits, *sum;

int length(char number[]);
void atoiFunction(char number[], int numberDigits[]);
void add(int firstNumberDigits[], int secondNumberDigits[], int bigNumberCount, int smallNumberCount);
void sumOfTwoNumbers(int firstNumberDigits[], int secondNumberDigits[], int firstNumberCount, int secondNumberCount);



int main(int argc, char const *argv[]){
	printf("Enter first number: ");
	scanf("%s", &firstNumber);
	printf("Enter second number: ");
	scanf("%s", secondNumber);

	firstNumberCount = length(firstNumber);
	secondNumberCount = length(secondNumber);
	

	if(firstNumberCount > secondNumberCount){
		firstNumberDigits = (int*)malloc(sizeof(int)*firstNumberCount);
		secondNumberDigits = (int*)malloc(sizeof(int)*firstNumberCount);;
		sum = (int*)malloc(sizeof(int)*firstNumberCount);
	}

	else{
		firstNumberDigits = (int*)malloc(sizeof(int)*secondNumberCount);
		secondNumberDigits = (int*)malloc(sizeof(int)*secondNumberCount);;
		sum = (int*)malloc(sizeof(int)*secondNumberCount);	
	}


	atoiFunction(firstNumber, firstNumberDigits);
	atoiFunction(secondNumber, secondNumberDigits);
	sumOfTwoNumbers(firstNumberDigits, secondNumberDigits, firstNumberCount, secondNumberCount);

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

	printf("\nNumber is " );
	for (int i = lengthOfString - 1; i >= 0; i--){
		
		printf("%d", numberDigits[i] );
	}
   
}

void sumOfTwoNumbers(int firstNumberDigits[], int secondNumberDigits[], int firstNumberCount, int secondNumberCount){
	if(firstNumberCount >= secondNumberCount){
		/*for (int i = 0; i < secondNumberCount; i++){
			secondNumberDigits[i] = 0;
		}*/
		//difference = firstNumberCount - secondNumberCount;
		add(firstNumberDigits, secondNumberDigits, firstNumberCount, secondNumberCount);
	}
	if(secondNumberCount > firstNumberCount){
		/*for (int i = 0; i < firstNumberCount; i++){
			firstNumberDigits[i] = 0;
		}*/
	//	difference = secondNumberCount - firstNumberCount;
		add(firstNumberDigits, secondNumberDigits, secondNumberCount, firstNumberCount);
	}
}


void add(int firstNumberDigits[], int secondNumberDigits[], int bigNumberCount, int smallNumberCount){
	for(int i = bigNumberCount - 1; i >= 0; i--){

		sum[i] = firstNumberDigits[ i ] + secondNumberDigits[i];
		if(sum[i] > 9){
			sum[i+1] = sum[i+1] + 1;
			sum[i] = sum[i] - 10;
		}
	}
	printf("Sum of %s and %s is ", firstNumber, secondNumber);
	for (int i= 0; i < bigNumberCount; i++){
		printf("%d", sum[i]);
	}
}



