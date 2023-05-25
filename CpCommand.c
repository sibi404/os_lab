#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *fptr1,*fptr2;
	char file1[20],file2[20];
	char c;
	printf("Enter source file name : ");
	scanf("%s",&file1);
	fptr1 = fopen(file1,"r");
	if (fptr1 == NULL){
		printf("Cannnot open file\n");
		exit(0);
	}
	printf("Enter destination file name : ");
	scanf("%s",&file2);
	fptr2 = fopen(file2,"w");
	if (fptr2 == NULL){
		printf("Cannot open file\n");
		exit(0);
	}

	while((c = fgetc(fptr1)) != EOF){
		fputc(c,fptr2);
	}

	printf("Succesfully copied!!\n");

	fclose(fptr1);
	fclose(fptr2);
	return 0;
}