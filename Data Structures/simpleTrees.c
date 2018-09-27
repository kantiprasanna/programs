#include <stdio.h>

void display();

struct node{
	int val;
	int number;	
	struct node *address1;
	struct node *address2;
};

struct node *temp, *t, *root = NULL, *new;


int main(int argc, char const *argv[]){
	int parent, child, choice;
	// enter root
	// 

	while(1){
		new = (struct node *)malloc(sizeof(struct node));
		
		if(root == NULL){
			printf("Enter number: ");
			scanf("%d", &new -> number);
			new -> address1 = NULL;
			new -> val = 1;
			new -> address2 = NULL;
			root = new;
		}
		else{
			printf("1.Add\n2.Display\n3.exit\n");
			printf("Enter choice: ");
			scanf("%d", &choice);
			switch(choice){
				case 1: printf("Enter parent: ");
						scanf("%d", &parent);
						printf("Enter number: ");
						scanf("%d", &new -> number);
						new -> address1 = NULL;
						new -> address2 = NULL;
						new -> val = 1;
						if(root -> number == parent){
							temp = root;
							while(temp -> address2 != NULL)
								temp = temp -> address2;
							temp -> address2 = new;
						}
						else{
							temp = root;
							new -> val = 0;						
							while(temp -> number != parent)
								temp = temp -> address2;
							// To check here
							if(temp -> address1 != NULL){
								if(temp -> address1 == NULL)
									t = temp;
								else 
									t = temp -> address1;
								while(t -> address2 != NULL)
									t = t -> address2;
								t -> address2 = new;
							}
							
						}
						break;
				case 2: display();
						break;
				case 3: exit(1);
			}
		}
	}

	return 0;
}


void display(){
	temp = root;
	while(temp -> address2 != NULL){
		printf("%d", temp -> number);
		if(temp -> address1 != NULL){
			t = temp -> address1;
			while(t != NULL){
				printf("%d ", t -> number);
				t = t -> address2;
			}
			// printf("%d", t -> number);
		}
		printf("\n");
		temp = temp -> address2;
	}
	printf("%d", temp -> number);
}