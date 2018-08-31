#include<stdio.h>

typedef struct{
	// char name[20];
	int rollNumber;
} studentDetails;

int main(int argc, char const *argv[]){
	studentDetails studentOne;
	studentDetails studentOneData;
	char fileName[50], ch;
	// printf("Enter name: ");
	// scanf("%s", studentOne.name);
	printf("Enter roll number: ");
	scanf("%d", &studentOne.rollNumber);

	printf("Enter file name: ");
	scanf("%s", fileName);
	FILE *fptr;
	fptr = fopen(fileName, "wb");
	// fprintf(fptr, "Student details\n Name = %s\n Roll number = %d\n", studentOne.name, studentOne.rollNumber);
	fwrite(&studentOne, sizeof(studentDetails), 1, fptr);	
	fclose(fptr);

	fptr = fopen(fileName, "rb");
	fread(&studentOneData, sizeof(studentDetails), 1 ,fptr);
	//printf("Data in structure read from file is\nName = %s\nRoll number = %d", studentOneData.name, studentOneData.rollNumber);
	printf("Data in steucture read from file is\n roll number = %d\n", studentOneData.rollNumber);
	fclose(fptr);

	return 0;
}
