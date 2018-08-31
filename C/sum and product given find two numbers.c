#include<stdio.h>

void findNumbers(int sum, int product);

int main(int argc, char const *argv[]){
	int sum, product; 
	printf("Enter the sum of two numbers: ");
	scanf("%d", &sum);
	printf("Enter product of two numbers: ");
	scanf("%d", &product);
	findNumbers(sum, product);
	return 0;
}

void findNumbers(int sum, int product){
	int counter = 0, firstNumber, secondNumber;
	if((sum < 0) || (product < 0)){
		printf("Enter positive sum and product.");
		exit(1);
	}
	while(counter <= sum / 2){
		firstNumber = counter;
		secondNumber = sum - counter;
		if((firstNumber * secondNumber) == product){
			printf("Sum of two numbers is %d and their product is %d.", sum, product);
			printf(" The two numbers are %d and %d.", firstNumber, secondNumber);
			break;
		}
		counter++;
	}

}