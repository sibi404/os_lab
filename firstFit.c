#include<stdio.h>
int main(){
	int process_count;
	int block_count;
	printf("Enter number of process : ");
	scanf("%d",&process_count);

	printf("Enter number of memory block : ");
	scanf("%d",&block_count);

	int blocks[block_count];
	int process[process_count];

	printf("Enter block size\n");
	for (int i = 0; i < block_count;i++){
		scanf("%d",&blocks[i]);
	}

	printf("Enter process size\n");
	for (int i = 0; i < process_count; i++){
		scanf("%d",&process[i]);
	}

	int alllcation[process_count];
	for (int i = 0; i < process_count; i++){
		alllcation[i] = -1;
	}

	for (int i =0; i < process_count; i++){
		for (int j = 0; j < block_count; j++){
			if (blocks[j] >= process[i] && alllcation[i] == -1){
				alllcation[i] = j;
				blocks[j] -= process[i];
				break;
			}
		}
	}

	printf("Process No\tProcess Size\tBlock No\n");
	for (int i = 0; i < process_count; i++){
		printf("%d\t\t%d\t\t",i + 1,process[i]);
		if (alllcation[i] != -1){
			printf("%d\n",alllcation[i] + 1);
		}else{
			printf("Not allocated\n");
		}
	}

	return 0;
}