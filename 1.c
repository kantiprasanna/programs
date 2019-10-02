#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#include<ctype.h>
int main(){
    int b[10][10]={0},n=0,i,j;
    char *str="",*req;
    printf(">>");
    gets(str);
    char* token = strtok(str," ");
    while(token != NULL)
    {
        req = token;
        token = strtok(NULL," ");
    }
   // printf("%s\n",req);
    int r=toupper(req[0])-65;
    int c=req[1]-48;
    //printf("%d",r);
   // printf("%d",c);
    int l=strlen(req)-3;
    int ct=1;
    for(i=3;req[i]!='\0';i++)
    {
        int l1=req[i]-48;
       // printf("l is %d\n",l);
        n=n+(req[i]-48)*pow(10,l-ct);
        //printf("n is %d\n",n);
        ct++;
    }
    //printf("%d",n);
    b[r][c]=n;
     for(int i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }

    
    return 0;
}