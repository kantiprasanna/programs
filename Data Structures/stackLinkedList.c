#include <stdio.h>

struct stack{
	int number;
	struct stack *nextAddress;
};

struct stack *top = NULL;


void display(){
	struct stack *temporaryPointer;
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
	struct stack *temporaryPointer;
	int value;

	printf("Enter a number which is to be added into the stack: ");
	scanf("%d", &value);
	
	temporaryPointer = (struct stack *)malloc(sizeof(struct stack));
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
	struct stack *temporaryPointer;
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