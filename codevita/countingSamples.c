#include <stdio.h>
#include <stdlib.h>
int *counter;

void sample(){
	int numberOfRanges, numberOfRockSamples, *sizeOfSamples, *ranges;
	int i, j;
	scanf("%d%d", &numberOfRockSamples, &numberOfRanges);
	sizeOfSamples = (int *) malloc(numberOfRockSamples * sizeof(int));
	ranges = (int *) malloc(2 * numberOfRanges * sizeof(int));
	counter = (int *) malloc(numberOfRanges * sizeof(int));
	for(i = 0; i < numberOfRockSamples; i++)
		scanf("%d", &sizeOfSamples[i]);
	for(i = 0; i < numberOfRanges * 2; i++)
		scanf("%d", &ranges[i]);
	for(i = 0; i < numberOfRanges; i++)
		counter[i] = 0;
	j = 0;

	for(j = 0; j < numberOfRanges * 2; j+=2){
		for(i = 0; i < numberOfRockSamples; i++){		
			if((sizeOfSamples[i] > ranges[j]) && (sizeOfSamples[i] < ranges[j + 1])){
				counter[j/2]++;
				
			}	
		}
	}
	for(i = 0; i < numberOfRanges; i++){
		printf("%d", counter[i]);
	}
}

int main(int argc, char const *argv[]){
	sample();
	return 0;
}