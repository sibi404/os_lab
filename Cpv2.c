#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
	if (argc < 3){
		printf("Argument missing\n");
	}else{
		FILE *fptr1,*fptr2;
		fptr1 = fopen(argv[1],"r");
		if (fptr1 == NULL){
			printf("%s Doesnot exist\n",argv[1]);
			exit(0);			
		}
		fptr2 = fopen(argv[2],"r+");
		if (fptr2 == NULL){
			printf("%s Doesnot exist\n",argv[2]);
			exit(0);
		}
		char c;

		while((c = fgetc(fptr1)) != EOF){
			fputc(c,fptr2);
		}

		printf("Succesfully Copied!!\n");
		fclose(fptr1);
		fclose(fptr2);

	}
	return 0;
}