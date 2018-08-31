#include <stdio.h>

int factorial(int number){
	if(number == 1)
		return 1;
	else{
		return number * factorial(number - 1);
	}
}

int main(int argc, char const *argv[]){
	int number, result;
	printf("Enter number whose factorial is required: ");
	scanf("%d", &number);
	result = factorial(number);
	printf("Factorial of %d is %d.", number, result);
	return 0;
}