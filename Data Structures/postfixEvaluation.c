#include<stdio.h>
#include<stdlib.h>

#define MAX 100

void push(char);
int pop();
int isOperator(char);
int perfOperation(int,int,char);

int arr[MAX],top=-1,values[2][10];

void main()
{
    char str[100];
    int i=0,k=0,encountered[26]={0},first,second;
    printf("Enter an infix expression : ");
    scanf("%s",str);
    while(str[i])
    {
        if(!isOperator(str[i]))
        {
            if(encountered[str[i]-97]==0)
            {
                printf("Enter the value of %c : ",str[i]);
                scanf("%d",&values[1][k]);
                values[0][k]=str[i];
                k++;
                encountered[str[i]-97]=1;
            }
        }
        i++;
    }
    i=0;
    while(str[i])
    {
        if(!isOperator(str[i]))
        {
            k=0;
            while(values[0][k]!=str[i])
                k++;
            push(values[1][k]);
        }
        else
        {
            second=pop();
            first=pop();
            push(perfOperation(first,second,str[i]));
        }
        i++;
    }
    printf("%d",arr[top]);
}
int isOperator(char ch)
{
    if(ch>='a'&&ch<='z')
        return 0;
    return 1;
}
void push(char ch)
{
    arr[++top]=ch;
}
int pop()
{
    return arr[top--];
}
int perfOperation(int a,int b,char ch)
{
    switch(ch)
    {
        case '+':return a+b;
        case '-':return a-b;
        case '*':return a*b;
        case '/':return a/b;
    }
}
