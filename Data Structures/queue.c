#include <stdio.h>
#define MAX 5

int start = -1, end = -1, queue[MAX];

void display(int queue[]){
	if((start < 0) || (start > end)){
		printf("Empty queue.");
	}
	else{
		for(int i = start; i < end; i++){
			printf("%d ", queue[i]);
		}
	}
}

void insert(int queue[]){
	int value;
	if(end == MAX ){
		printf("Queue is full.\n");
	}
	
	else{
		if((start == -1)||(end == -1)){
			start = 0;
			end = 0;
		}
		printf("Enter number to be entered in queue: ");
		scanf("%d", &queue[end]);
		end++;
		display(queue);
	}
}


void delete(int queue[]){
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
			case 1: insert(queue);
					// display(queue);
					break;
			case 2: delete(queue);
					display(queue);
					break;
			case 3: display(queue);
					break;
			default: exit(1);
		}
	}
	return 0;
}