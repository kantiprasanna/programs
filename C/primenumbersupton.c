#include<stdio.h>
#include <math.h>
#include <time.h>

double totalTime1, totalTime2;
clock_t start1, end1, start2, end2;

int prime1(int number);
int prime2(int number);

int main(int argc, char const *argv[]){
	int number;
	printf("Enter number upto which prime numbers count is required: ");
	scanf("%d", &number);

	int count1, count2;

	start1 = clock();
	count1 = prime1(number);
	end1 = clock();
 	totalTime1 = (double)(end1 - start1)/CLOCKS_PER_SEC;

	start2 = clock();
	count2 = prime2(number);
	end2 = clock();
 	totalTime2 = (double)(end2 - start2)/CLOCKS_PER_SEC;
	printf(" prime1 %d, prime2 %d\n", count1 + 1, count2 +1);
	printf("\n Time1 = %lf \nTime2 = %lf", totalTime1, totalTime2);
	return 0;
}

int prime1(int number){
	int counter = number;
	for(int i = 2; i <= number; i++){
		for(int j = 2; j <= (i/2); j++){
			if(i % j == 0){
				counter--;
				break;
			}
		}
		
	}
	return counter;
}

int prime2(int number){
	int counter = number;
	for(int i = 2; i <= (number); i++){
		for(int j = 2; j <= sqrt(i); j++){
			if(i % j == 0){
				counter--;
				break;
			}
		}
		
	}
	return counter;
}