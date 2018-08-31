#include <stdio.h>

struct node{
	int number;
	struct node *nextAddress;
};

struct node *head = NULL, *temporaryNode, *new;

int main(int argc, char const *argv[]){
	int size, key;
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
	// while(temporaryNode -> nextAddress != NULL){
	// 	printf("%d")
	// }
	while(temporaryNode -> nextAddress != NULL){
		if(temporaryNode -> number == key){
			printf("Found.");
			break;
		}
		temporaryNode = temporaryNode -> nextAddress;
		if(temporaryNode -> number != key && temporaryNode -> nextAddress == NULL)
			printf("Not found.");
	}
	return 0;
}