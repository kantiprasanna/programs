#include <stdio.h>


// A recursive function to print the steps made in this game......
int towersOfHanoi(int numberOfDiscs, char source, char temporary, char destination){
	if(numberOfDiscs == 1){
		printf("%c -> %c\n", source, destination);
	}
	else{
		towersOfHanoi(numberOfDiscs - 1, source, destination, temporary);
		towersOfHanoi(1, source, temporary, destination);
		// printf("%c -> %c\n", source, destination);
		towersOfHanoi(numberOfDiscs - 1, temporary, source, destination);
	}
	return numberOfDiscs;
}

int main(int argc, char const *argv[]){
	int numberOfDiscs;
	char source, temporary, destination;
	printf("Enter number of discs to be moved from source to destination: ");
	scanf("%d", &numberOfDiscs);
	printf("Enter source value: ");
	getchar();
	scanf("%c", &source);
	printf("Enter temporary location value: ");
	getchar();
	scanf("%c", &temporary);
	printf("Enter destination value: ");
	getchar();
	scanf("%c", &destination);
	int value = towersOfHanoi(numberOfDiscs, source, temporary, destination);
	return 0;
}