#include<stdio.h>

void main(int c, char *v[]){
	int sum = 0;
	printf("DEBUGG:  c: %d\n", c);
	for (int i = 0; i < c; ++i)
	{
		printf("DEBUGG: %s, d = %d ", v[i], *v[i]);

	}



	for (int i = 1; i < c; ++i)
	{
		/* code */
		if ((*v[i] >= 48)&&(*v[i] <= 57))
		{
			sum += asciiConversion(v[i]);
		}
		else{
			sum = -1;
			break;

		}

	}
	if(sum == -1){
		printf("Please Enter valid input.\n");
	}
	else{
		//printf("\nThe sum of %d and %d is %d.", asciiConversion(v[1]), asciiConversion(v[2]), sum);
		printf("The sum of %d", asciiConversion(v[1]));
		for (int i = 2; i < c - 1; ++i)
		{
			printf(", %d", asciiConversion(v[i]));
			/* code */
		}
		printf(" and %d is %d", asciiConversion(v[c - 1]), sum);

	}
	
	

}

int asciiConversion(char v[]){
	int result = 0;
	for (int i = 0; v[i] != '\0'; ++i){
        if((v[i] >= 48)&&(v[i] <= 57))
        result = result * 10 + v[i] - '0';
        //printf("\nDEBUGG:  %d", result);
	}
    return result;
}