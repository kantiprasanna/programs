#include <stdio.h>

struct node{
	int number;
	struct node *nextAddress;
};

struct node *head = NULL, *temporaryNode, *new;

int main(int argc, char const *argv[]){
	int size, key, temp;
	printf("Enter size: ");
	scanf("%d", &size);
	for(int i = 0; i < size; i++){
		new = (struct node *)malloc(sizeof(struct node));
		if(head == NULL){
			scanf("%d", &new -> number);
			new -> nextAddress = NULL;
			head = new;
		}
		else{
			temporaryNode = head;
			scanf("%d", &new -> number);
			while(temporaryNode -> nextAddress != NULL)
				temporaryNode = temporaryNode -> nextAddress;
			temporaryNode -> nextAddress = new;
			new -> nextAddress = NULL;
		}
	}
	printf("Enter search element: ");
	scanf("%d", &key);
	temporaryNode = head;	
	while(temporaryNode -> nextAddress != NULL){
		if(temporaryNode -> nextAddress -> number == key){
			printf("Found.");
			temp = temporaryNode -> number;
			temporaryNode -> number = temporaryNode -> nextAddress -> number;
			temporaryNode -> nextAddress -> number = temp;

			break;
		}
		temporaryNode = temporaryNode -> nextAddress;
		if(temporaryNode -> number != key && temporaryNode -> nextAddress == NULL)
			printf("Not found.");
	}
	temporaryNode = head;	
	while(temporaryNode -> nextAddress != NULL){
		printf("%d ", temporaryNode -> number);
		temporaryNode = temporaryNode -> nextAddress;

	}
	printf(" %d",temporaryNode -> number);
	return 0;
}