#include <stdio.h>

struct node{
	int number;
	struct node *nextAddress;
};

void insertAtStart();
void insertAtEnd();
void insertAfter();
void insertBefore();
// void deleteBefore();
// void deleteAfter();
// void delete();
// void deleteAtStart();
// void deleteAtEnd();
void display();

int main(int argc, char const *argv[]){
	int choice;
	while(1){
		printf("1.Insert At start.\n2.Insert At End.\n3.Insert after element.\n4.Insert before element.\n5.Delete before element.\n");
		printf("6.Delete after element.\n7.Delete the element.\n8.Delete at start.\n9.Delete at end.\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:	insertAtStart();
					break;
			case 2: insertAtEnd();
					break;
			case 3: insertAfter();
					break;
			case 4: insertBefore();
					break;
			case 5: deleteBefore();
					break;
			case 6: deleteAfter();
					break;
			case 7: delete();
					break;
			case 8: deleteAtStart();
					break;
			case 9: deleteAtEnd();
					break;
			default: exit(1);			
		}
	}
	return 0;
}

void display(){
	struct node *temporaryNode;
	temporaryNode = head;
	if(head == NULL){
		printf("Empty queue.\n");
	}
	else{
		while(temporaryNode != NULL){						
			if(temporaryNode == head){
				printf("%d ", temporaryNode -> number);
				temporaryNode = temporaryNode -> nextAddress;
			}
			else{
				printf(" -> %d ", temporaryNode->number);
				temporaryNode = temporaryNode->nextAddress;
				
			}
			
		}
	}
}


void insertAtStart(){
	struct node *temporaryPointer;
	int value;

	printf("Enter a number which is to be added into the stack: ");
	scanf("%d", &value);
	
	temporaryPointer = (struct stack *)malloc(sizeof(struct stack));
	temporaryPointer -> number = value;
	if(head == NULL){
		temporaryPointer -> nextAddress = NULL;
		top = temporaryPointer;
	}
	else{
		temporaryPointer -> nextAddress = head;
		head = temporaryPointer;
	}
	
	printf("\n");
}

void insertAtEnd(){
	int value;
	struct node *temporaryNode = (struct node *)malloc(sizeof(struct node));
	struct node *new = (struct node *)malloc(sizeof(struct node));
	printf("Enter a number to be inserted: ");
	scanf("%d", &value);
	if(head == NULL){
		temporaryNode -> number = value;
		temporaryNode -> nextAddress = NULL;
		head = temporaryNode;
	}
	else{
		temporaryNode = head;
		while(temporaryNode -> nextAddress != NULL){
			temporaryNode = temporaryNode -> nextAddress;
		}
		new -> number = value;
		temporaryNode -> nextAddress = new;
		new -> nextAddress = NULL;
		
		
	}
}

void insertAfter(){
	int key, value;
	struct node *temporaryNode;
	struct node *new = (struct node *)malloc(sizeof(struct node));
	printf("Enter element after which node has to be inserted: ");
	scanf("%d", &key);
	printf("Enter a number to be inserted: ");
	scanf("%d", &value);
	if(head == NULL){
		printf("No elements\n");
	}
	else{
		temporaryNode = head;
		while(temporaryNode -> number != key)
			temporaryNode = temporaryNode -> nextAddress;
		new -> number = value;
		new -> nextAddress = temporaryNode -> nextAddress;
		temporaryNode -> nextAddress = new;
	}
}

void insertBefore(){
	int key, value;
	struct node *temporaryNode;
	struct node *new = (struct node *)malloc(sizeof(struct node));
	printf("Enter element after which node has to be inserted: ");
	scanf("%d", &key);
	printf("Enter a number to be inserted: ");
	scanf("%d", &value);
	if(head == NULL){
		printf("No elements\n");
	}
	else{
		temporaryNode = head;
		while(temporaryNode -> nextAddress -> number != key)
			temporaryNode = temporaryNode -> nextAddress;
		new -> number = value;
		new -> nextAddress = temporaryNode -> nextAddress;
		temporaryNode -> nextAddress = new;
	}	
}

void deleteAtStart(){
	struct node *temporaryPointer;
	temporaryPointer = head;
	if(head == NULL){
		printf("Underflow.\n");		
	}
	else{		
		printf("The value which is being deleted is %d.\n", temporaryPointer -> number);
		temporaryPointer = temporaryPointer -> nextAddress;
		free(temporaryPointer);
	}	
	printf("\n");
}

void deleteAtEnd(){
	struct node *temporaryPointer, *tail;
	temporaryPointer = head;
	while(temporaryPointer -> nextAddress != NULL)
		temporaryPointer = temporaryPointer -> nextAddress;
	tail = temporaryPointer -> nextAddress;
	temporaryPointer -> nextAddress = NULL;
	free(tail);
}

void deleteAfter(){
	int key;
	printf("Enter element after which node has to be deleeted: ");
	scanf("%d", &key);
	struct node *temporaryPointer, *pointer;
	temporaryPointer = head;
	while(temporaryPointer -> nextAddress != key){
		temporaryPointer = temporaryPointer -> nextAddress;
	}
	pointer = temporaryPointer -. nextAddress;
	temporaryPointer -> nextAddress = pointer -> nextAddress;
	free(pointer);

}

