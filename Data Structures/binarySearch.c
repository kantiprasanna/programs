#include <stdio.h>

struct node{
	int number;
	struct node *nextAddress;
};

int size, key;
struct node *head = NULL, *first, *last, *m, *e, *new, *temporaryNode, *tail;
void middle(struct node *h, struct node *t);
void search();

int main(int argc, char const *argv[]){

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
			tail = new;
		}
	}

	// tail = NULL;
	printf("Enter search element: ");
	scanf("%d", &key);
	if(head -> number == key || tail -> number == key)
		printf("found");
	else if(head -> number > key || tail -> number < key)
		printf("Not found\n");
	else
		search();

	return 0;
}


void middle(struct node *h, struct node *t){
	m = h;
	e = h -> nextAddress;;
	while(e != t){
		e = e -> nextAddress;
		if(e != t){
			m = m-> nextAddress;
			e = e -> nextAddress;
		}
	}
}

void search(){
	last = NULL;
	first = head;

	while(last == NULL || last -> nextAddress != first){
		middle(first, last);
		if(m == NULL){
			printf("Not found.\n");
			break;
		}
		else if(m -> number == key){
			printf("Found.\n");
			break;
		}
		else if(m -> number < key)
			first = m -> nextAddress;
		else
			last = m;
	}
}