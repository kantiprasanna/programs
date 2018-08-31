#include<stdio.h>

int main(int argc, char const *argv[])
{
	int number = 1, counter = 1;
	while(number < 10){
		 while(counter <= 10){
		 	printf("%d X  %2d = %d\t%d X  %2d = %d\n", number, counter, number * counter, number + 1, counter, (number + 1) * counter);
			counter++;
		}
		counter = 1;
		printf("\n");
		number += 2;
		
	}
	return 0;
}