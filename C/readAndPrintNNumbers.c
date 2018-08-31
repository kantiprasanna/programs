#include<stdio.h>

int main(int argc, char const *argv[])
{
	int  count;
	int *numbers;
	
	printf("Enter number of numbers to be read: ");
	scanf("%d", &count);
	numbers = (int* ) malloc(sizeof(int)*count);
	printf("Enter the numbers: ");
	for(int counter = 0; counter < count; counter++){
			scanf("%d", &numbers[counter]);
	}
	if(count == 1){
		printf("The number is %d", numbers[0]);
	}
	if(count > 1){	
		
		printf("The numbers are %d", numbers[0]);
		for(int counter = 1; counter < count-1; counter++){
			printf(", %d", numbers[counter]);
		}
		printf(" and %d", numbers[count - 1]);
	}
	free(numbers);
	printf(".");
	return 0;
}