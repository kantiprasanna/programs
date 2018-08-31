#include<stdio.h>

int product(int number1, int number2, int number3){
	int result;
	result = number1 * number2 * number3;
	return result;
}

int main()
{
	int number1, number2, number3;
	printf("Enter the first number: ");
	scanf("%d", &number1);
	printf("Enter the second number: ");
	scanf("%d", &number2);
	printf("Enter the third number: ");
	scanf("%d", &number3);
	int result;
	result = product(number1, number2, number3);
	printf("Product of %d,%d and %d is %d", number1, number2, number3, result);
	return 0;
}