#include <stdio.h>

int main(int argc, char const *argv[]){
	int number, counter = 1, square = 1;
	printf("Enter the number upto which the series is required: ");
	scanf("%d", &number);
	if(number <= 0){
		printf("Enter a positive number.");
	}

	printf("Terms in the series upto %d are %d", number, counter);
	counter++;
	do{
		
		square = counter * counter;
		if(square <= number){
			printf(", %d", square);
		}
		counter++;
	}while(square < number);
	printf(".");

	return 0;
}