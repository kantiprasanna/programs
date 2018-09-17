#include <stdio.h>

void swap(int *n1, int *n2){
	int temp;
	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

int partition (int number[], int low, int high) { 
    int pivot = number[high];    
    int i = (low - 1);   
	for (int j = low; j <= high- 1; j++) { 
        if (number[j] <= pivot) { 
            i++;     
            swap(&number[i], &number[j]); 
        } 
    } 
    swap(&number[i + 1], &number[high]); 
    return (i + 1); 
} 

void quickSort(int number[], int low, int high) 
{ 
    if (low < high){ 
	int pi = partition(number, low, high); 
        quickSort(number, low, pi - 1); 
        quickSort(number, pi + 1, high); 
    } 
} 


int main(int argc, char const *argv[]){
	int number[10], size;
	printf("Enter size: ");
	scanf("%d", &size);
	for(int i = 0; i < size; i++)
		scanf("%d", &number[i]);
	quickSort(number, 0, size - 1);
	for(int i = 0; i < size; i++)
		printf("%d ", number[i]);
	return 0;
}