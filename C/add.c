#include<stdio.h>

int add(int number1, int number2);

void main(){
	int number1, number2;
	printf("Enter the first number: ");
	scanf("%d", &number1);
	printf("Enter the second number: ");
	scanf("%d", &number2);
	int sum;
	sum = add(number1, number2);
	printf("The sum of %d and %d is %d.", number1, number2, sum);
}

int add(int number1, int number2){
	int sum;
	sum = number1 + number2;
	return sum;
}