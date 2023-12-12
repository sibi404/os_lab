#include <stdio.h>

int process_no,resource_no;
int need[50][50],allocation[50][50],max[50][50];
int available[6],instance[6],safe[6];



void readMaxResource(){
	for (int i = 0; i < resource_no; i++){
		available[i] = 0;
		printf("%c : ",i + 97);
		scanf("%d",&instance[i]);
	}
}

void readMatrix(int matrix[50][50]){
	for (int i = 0; i < resource_no; i++){
		printf("%c ",i + 97);
	}
	printf("\n");
	for (int i = 0; i < process_no; i++){
		for (int j = 0; j < resource_no; j++){
			scanf("%d",&matrix[i][j]);
		}
	}
}

void printMatrix(int matrix[50][50]){
	for (int i = 0; i < resource_no; i++){
		printf("%c ",i + 97);
	}
	printf("\n");

	for (int i = 0; i < process_no; i++){
		for (int j = 0; j < resource_no; j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
}

void calculateNeed(){
	for (int i = 0; i < process_no; i++){
		for (int j = 0; j < resource_no; j++){
			need[i][j] = max[i][j] - allocation[i][j];
		}
	}
}

void calculateAvailable(){
	for (int i = 0; i < process_no; i++){
		for (int j = 0; j < resource_no ; j++){
			available[j] += allocation[i][j];
		}
	}

	for (int i = 0; i < resource_no; i++){
		available[i] = instance[i] - available[i];
	}
}

void banker(){
	int flag = 0,safe_index = 0;
	int finish[process_no];
	for (int i = 0; i < process_no; i++){
		finish[i] = 0;
	}
	for (int i = 0; i < process_no; i++){
		flag = 0;
		if (finish[i] == 0){
			for (int j = 0; j < resource_no; j++){
				if (need[i][j] > available[j]){
					flag = 1;
					break;
				}
			}
			if (flag == 0){
				finish[i] = 1;
				safe[safe_index] = i;
				safe_index++;

				for (int l = 0; l < resource_no; l++){
					available[l] += allocation[i][l];
				}
				i = -1;
			}
		}
	}

	flag = 0;
	for (int i = 0; i < process_no; i++){
		if (finish[i] == 0){
			flag = 1;
			printf("\nSystem in deadlock state\n");
			break;
		}
	}
	if (flag == 0){
		printf("\nSystem is in safe state and process sequence is\n");
		for (int i = 0; i < process_no; i++){
			printf("p[%d]\t",safe[i]);
		}
	}
}




int main(){
	
	printf("Enter number of process : ");
	scanf("%d",&process_no);
	printf("Enter number of resources : ");
	scanf("%d",&resource_no);


	printf("Enter max instances of each resources\n");
	readMaxResource();

	printf("Enter allocation matrix\n");
	readMatrix(allocation);

	printf("Enter max matrix\n");
	readMatrix(max);

	calculateNeed();
	calculateAvailable();

	printf("Entered data\n\n");

	printf("Allocation matrix is\n");
	printMatrix(allocation);

	printf("\nMax matrix is\n");
	printMatrix(max);

	printf("\nNeed matrix is\n");
	printMatrix(need);


	printf("\nTotal resource instances\n");
	for (int i = 0; i < resource_no; i++){
		printf("%d\t",instance[i]);
	}

	printf("\n\nAvailable\n");
	for (int i = 0; i < resource_no; i++){
		printf("%d\t",available[i]);
	}
	banker();

	return 0;
}