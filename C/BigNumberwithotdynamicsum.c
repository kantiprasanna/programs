#include<stdio.h>




int length(char number[]);
void atoiFunction(char number[], int numberDigits[]);
void add(int firstNumberDigits[], int secondNumberDigits[], int bigNumberCount, int smallNumberCount);
void sumOfTwoNumbers(int firstNumberDigits[], int secondNumberDigits[], int firstNumberCount, int secondNumberCount);



int main(int argc, char const *argv[]){


	char firstNumber[100000], secondNumber[100000];
	int firstNumberCount, secondNumberCount;
	int difference;
	int *firstNumberDigits;
	int *secondNumberDigits, *sum;
	int size;

	printf("Enter first number: ");
	scanf("%s", &firstNumber);
	printf("Enter second number: ");
	scanf("%s", secondNumber);

	firstNumberCount = length(firstNumber);
	secondNumberCount = length(secondNumber);


	if(firstNumberCount > secondNumberCount){
		size = firstNumberCount;
	} else {
		size = secondNumberCount;
	}

	firstNumberDigits = (int *)malloc(sizeof(int) * size);
	secondNumberDigits = (int *)malloc(sizeof(int) * size);
	sum = (int *)malloc(sizeof(int) * size) ;



	atoiFunction(firstNumber, firstNumberDigits);
	atoiFunction(secondNumber, secondNumberDigits);
	sumOfTwoNumbers(firstNumberDigits, secondNumberDigits, firstNumberCount, secondNumberCount);
	free(firstNumberDigits);
	free(secondNumberDigits);
	free(sum);

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

void sumOfTwoNumbers(int firstNumberDigits[], int secondNumberDigits[], int firstNumberCount, int secondNumberCount){

	firstNumberDigits[firstNumberCount] = 0;
	secondNumberDigits[secondNumberCount] = 0;
	firstNumberCount += 1;
	secondNumberCount += 1;
	if(firstNumberCount >= secondNumberCount){
		for (int i = secondNumberCount; i < firstNumberCount; i++){
			secondNumberDigits[i] = 0;
		}

		add(firstNumberDigits, secondNumberDigits, firstNumberCount, secondNumberCount);
	}
	if(secondNumberCount > firstNumberCount){
		for (int i = firstNumberCount; i < secondNumberCount; i++){
			firstNumberDigits[i] = 0;
		}

		add(firstNumberDigits, secondNumberDigits, secondNumberCount, firstNumberCount);
	}
}


void add(int firstNumberDigits[], int secondNumberDigits[], int bigNumberCount, int smallNumberCount){
	int carry = 0;
	for(int i = 0; i < bigNumberCount - 1; i++){


		sum[i] = firstNumberDigits[ i ] + secondNumberDigits[i] + carry;

		if(sum[i] > 9){

			sum[i] = sum[i] - 10;
			carry = 1;
		}
		else{
			carry = 0;
		}
		
	}
	printf("Sum of %s and %s is ", firstNumber, secondNumber);
	if(carry != 0){
		printf("%d", carry);
	}
	for (int i= bigNumberCount - 2; i >= 0; i--){
		printf("%d", sum[i]);
	}
	printf(".\n");
}

