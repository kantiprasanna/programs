#include<stdio.h>
#include<string.h>
#define MAX 10

// extern char postfixExpression[20];
char st[20];
int top = -1;

void push(char st[], char val);
char pop(char st[]);
void infixToPostfix(char source[], char target[]);
int getPriority(char op);

int main(int argc, char const *argv[]){
	char infix[20], postfix[20];
	printf("Enter infix: ");
	gets(infix);
	strcpy(postfix, " ");
	infixToPostfix(infix, postfix);
	printf("postfix: ");
	puts(postfix);

	return 0;
}

int getPriority(char op){
	int priority;
	if((op == '/')||(op == '*'))
		priority = 1;
	else
		priority = 0;
	return priority;
}

void push(char st[], char value){
	if(top == MAX - 1){
		printf("Stack overflow.");
	}
	else{
		top++;
		st[top] = value;
	}
}

char pop(char st[]){
	char value = ' ';
	if(top == -1){
		printf("Stack underflow");
	}
	else{
		value = st[top];
		top--;
	}
	return value;
}

void infixToPostfix(char source[], char target[]){
	int i = 0, j = 0;
	char temp;
	strcpy(target, "");
	while(source[i] != '\0'){
		if(source[i] == '('){
			push(st, source[i]);
			i++;
		}
		else if(source[i] == ')'){
			while((top != -1)&&(st[top] != '(')){
				target[j] = pop(st);
				j++;
			}
			if(top == -1){
				printf("Wrong.");
				exit(1);
			}
			temp = pop(st);
			i++;

		}
		else if(isdigit(source[i])||isalpha(source[i])){
			target[j] = source[i];
			j++;
			i++;
		}
		else if((source[i] == '+')||(source[i] == '-')||(source[i] == '*')||(source[i] == '/')){
			while((top != -1)&&(st[top] != '(')&&(getPriority(st[top])>getPriority(source[i]))){
				target[j] = pop(st);
				j++;
			}
			push(st, source[i]);
			i++;
		}
		else{
			printf("Incorrect");
			exit(1);
		}

	}
	while((top != -1)&&(st[top] != '(')){
		target[j] = pop(st);
		j++;
	}
	target[j] = '\0';
	// strcpy(postfixExpression, postfix);
}

