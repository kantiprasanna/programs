#include <stdio.h>
#define MAX 5

int start = -1, end = -1, queue[MAX], priority[MAX];

void display(){
	if((start < 0) || (start > end)){
		printf("Empty queue.");
	}
	else{
		for(int i = start; i < end; i++){
			printf("%d  %d \n", queue[i], priority[i]);
		}
	}
}

void insert(){
	int value, number, priorityValue;
	if(end == MAX ){
		printf("Queue is full.\n");
	}
	
	else{
		if((start == -1)||(end == -1)){
			start = 0;
			end = 0;
		}
		printf("Enter priority: ");
		scanf("%d", &priorityValue);
		printf("\n priority: %d\n", priorityValue);
		printf("Enter number to be entered in queue: ");
		scanf("%d", &number);
		if(start == end){
			queue[start] = number;
			priority[start] = priorityValue;

		}
		else{
			for(int i = 0; i < end; i++){
				if(priority[i] > priorityValue){
					for(int j = end - 1; j >= i; j--){
						priority[j + 1] = priority[j];
						queue[j + 1] = queue[j];
					}
					priority[i] = priorityValue;										
					queue[i] = number;
					printf("\n Priority = %d\n", priority[i]);
					break;
				}
			}
			if(priority[end - 1] < priorityValue){
				priority[end] = priorityValue;
				queue[end] = number;
			}

		}

		end++;
		display();
	}
}


void delete(){
	if((start > end)||(start == -1)){
		printf("Underflow.\n");
	}
	else{
		printf("Element which is removed is %d\n", queue[start]);
		start++;
		if(start > end){
			start = -1;
			end = -1;
		}
	}
}

int main(int argc, char const *argv[]){
	int choice, size;
	
	while(1){
		printf("1.Add element\n2.Delete element\n3.Display elements\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1: insert();
					// display(queue);
					break;
			case 2: delete();
					display();
					break;
			case 3: display();
					break;
			default: exit(1);
		}
	}
	return 0;
}