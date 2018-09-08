#include <stdio.h>

union stack{
	int number;
	union stack *nextAddress;
};

union stack *top = NULL;


void display(){
	union stack *temporaryPointer;
	temporaryPointer = top;
	if(top == NULL)
		printf("Stack is empty.\n");
	else{
		while(temporaryPointer != NULL){
			if(temporaryPointer == top){
				printf("%d ", temporaryPointer -> number);
				temporaryPointer = temporaryPointer -> nextAddress;
			}
			else{
				printf(" -> %d ", temporaryPointer->number);
				temporaryPointer = temporaryPointer->nextAddress;
				
			}
			
		}
	}	
}

void push(){
	union stack *temporaryPointer;
	int value;

	printf("Enter a number which is to be added into the stack: ");
	scanf("%d", &value);
	
	temporaryPointer = (union stack *)malloc(sizeof(union stack));
	temporaryPointer -> number = value;
	if(top == NULL){
		temporaryPointer -> nextAddress = NULL;
		top = temporaryPointer;
	}
	else{
		temporaryPointer -> nextAddress = top;
		top = temporaryPointer;
	}
	display();
	printf("\n");

}

void pop(){
	union stack *temporaryPointer;
	temporaryPointer = top;
	if(top == NULL){
		printf("Stack underflow.\n");		
	}
	else{		
		printf("The value which is being deleted is %d.\n", top -> number);
		top = top -> nextAddress;
		free(temporaryPointer);
	}	
	display();
	printf("\n");

}

int main(int argc, char const *argv[]){
	int choice, check;	
	while(1){
		printf("1.Add element.\n2.Remove element.\n3.Display.\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1: push();
					break;
			case 2: pop();					
					break;
			case 3:	display();
					break;
			default : exit(1);
		}

	}
	return 0;
}