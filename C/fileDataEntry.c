#include <stdio.h>

typedef struct {
	char name[20];
	int age;

}student;
student data[100], data1[100];
static int i = 0;


void fileEntry(char fileName[]);
void fileDisplay(char fileName[]);

int main(int argc, char const *argv[]){
	FILE *fptr;
	int choice;
	char fileName[] = "studentDetails.lst";
	int check;
	fileEntry(fileName);

	while(1){
		
		printf("Enter \n1 for file entry.\n2 for file display. \n3 to Stop. \nChoice: ");
		scanf("%d", &choice);

		switch(choice){
			case 1: fileEntry(fileName);
					break;
			case 2: fileDisplay(fileName);
					break;
			case 3: exit(1);

			default: printf("Please enter a valid input.");
		}

	}
	return 0;
}
void fileEntry(char fileName[]){
	char check;
	FILE *fptr;
	fptr = fopen(fileName, "ab");
	printf("Enter name: ");
	scanf("%s", data[i].name);
	printf("Enter age: ");
	scanf("%d", &data[i].age);
	printf("\n i = %d\n", i);
	fwrite(&data[i], sizeof(student), 1, fptr);
	i++;
	fclose(fptr);
}

void fileDisplay(char fileName[]){
	FILE *fptr;
	char character;
	fptr = fopen(fileName, "rb");
	for(int j = 0; j < i; j++){
		fread(&data1[j], sizeof(student), 1, fptr);
		printf("Data read is name = %s\n age = %d\n", data1[j].name, data1[j].age);
	}
	fclose(fptr);
}