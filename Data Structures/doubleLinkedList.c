#include <stdio.h>

struct node{
	struct node *previousAddress;
	int number;
	struct node *nextAddress;
};

struct node *head = NULL, *temporaryNode, *newNode;

void display();
void insert();
void delete();

int main(int argc, char const *argv[]){
	int choice;
	while(1){
		printf("1.Add element\n2.Delete element.\n3.Display\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1: insert();
				break;
			case 2: delete();
			 	break;
			case 3: display();
				break;
			default: exit(1);
		}
	}
	return 0;
}

void insert(){
	int choice, value;
	newNode = (struct node *)malloc(sizeof(struct node));
	if(head == NULL){
		printf("Enter number: ");
		scanf("%d", &newNode -> number);
		newNode -> nextAddress = NULL;
		newNode -> previousAddress = NULL;
		head = newNode;
	}
	else{
		printf("1.Add Starting.\n2.Add ending.\n3.Add after element.\n4.Add before element.\nEnter choice: ");
		scanf("%d", &choice);
		temporaryNode = head;
		switch(choice){
			case 1:	printf("Enter number: ");
					scanf("%d", &newNode -> number);
					newNode -> nextAddress = head;
					newNode -> previousAddress = NULL;
					head -> previousAddress = newNode;
					head = newNode;
					break;
			case 2: printf("Enter number: ");
					scanf("%d", &newNode -> number);
					newNode -> nextAddress = NULL;
					while(temporaryNode -> nextAddress != NULL)
						temporaryNode = temporaryNode -> nextAddress;
					temporaryNode -> nextAddress = newNode;	 
					newNode -> previousAddress = temporaryNode;
					break;
			case 3: printf("Enter a number after which it has to be entered: ");
					scanf("%d", &value);
					printf("Enter number: ");
					scanf("%d", &newNode -> number);
					while(temporaryNode -> number != value)
						temporaryNode = temporaryNode -> nextAddress;
					newNode -> nextAddress = temporaryNode -> nextAddress;
					newNode -> nextAddress -> previousAddress = newNode;
					temporaryNode -> nextAddress = newNode;
					newNode -> previousAddress = temporaryNode;
					break;
			case  4: printf("Enter a number before which it has to be entered: ");
					 scanf("%d", &value);
					 printf("Enter number: ");
					 scanf("%d", &newNode -> number);
					 while(temporaryNode -> nextAddress -> number != value)
					     temporaryNode = temporaryNode -> nextAddress;
					 newNode -> nextAddress = temporaryNode -> nextAddress;
					 newNode -> nextAddress -> previousAddress = newNode;
					 temporaryNode -> nextAddress = newNode;
					 newNode -> previousAddress = temporaryNode;
					 break;
		}	
	}
	
}

void delete(){
	int choice, key;
	if(head == NULL)
		printf("underflow\n");
	else{
		printf("1.Delete start.\n2.Delete last.\n3.Delete element.\n4.Delete after element.\n5.Delete before element.\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1: temporaryNode = head;
					printf("The element which is deleted is %d.", head -> number);
					head = head -> nextAddress;
					head -> previousAddress = NULL;
					free(temporaryNode);
					break;
			case 2: temporaryNode = head;
					while(temporaryNode -> nextAddress != NULL)
						temporaryNode = temporaryNode -> nextAddress;
					newNode = temporaryNode -> nextAddress;
					temporaryNode -> nextAddress = NULL;
					free(newNode);
					break;
			case 3: temporaryNode = head;
					printf("Enter element which has to be deleted: ");
					scanf("%d", &key);
					while(temporaryNode -> nextAddress -> number != key)
						temporaryNode = temporaryNode -> nextAddress;
					newNode = temporaryNode -> nextAddress;
					temporaryNode -> nextAddress = newNode -> nextAddress;
					temporaryNode -> nextAddress -> previousAddress = temporaryNode;
					free(newNode);
					break;
			case 4: temporaryNode = head;
					printf("Enter element after which has to be deleted: ");
					scanf("%d", &key);
					while(temporaryNode -> number != key)
						temporaryNode = temporaryNode -> nextAddress;
					newNode = temporaryNode -> nextAddress;
					temporaryNode -> nextAddress = newNode -> nextAddress;
					newNode -> nextAddress -> previousAddress = temporaryNode;
					free(newNode);
					break;
			case 5: temporaryNode = head;
					printf("Enter element before which has to be deleted: ");
					scanf("%d", &key);
					while(temporaryNode -> nextAddress -> nextAddress -> number != key)
						temporaryNode = temporaryNode -> nextAddress;
					newNode = temporaryNode -> nextAddress;
					temporaryNode -> nextAddress = newNode -> nextAddress;
					newNode -> nextAddress -> previousAddress = temporaryNode;
					free(newNode);
					break;
		}
	}
}

void display(){
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