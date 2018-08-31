#include<stdio.h>

int main(int argc, char const *argv[])
{
	int number1, number2;
	scanf("%d%d", &number1, &number2);
	int sum;
	sum = number1 + number2;
	// sum of two numbers.
	printf("sum of %d anf %d is %d", number1, number2, sum);
	return 0;
}