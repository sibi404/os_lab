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


	int allocation[process_count];
	for (int i = 0; i < process_count; i++){
		allocation[i] = -1;
	}

	for (int i = 0; i < process_count; i++){
		int idx = -1;
		for (int j = 0; j < block_count; j++){
			if (blocks[j] >= process[i]){
				if (idx == -1){
					idx = j;
				}else if (blocks[idx] < blocks[j]){
					idx = j;
				}
			}
		}

		if (idx != -1){
			allocation[i] = idx;
			blocks[idx] -= process[i];
		}
	}

	printf("Process No\tProcess Size\tBlock No\n");
	for (int i = 0; i < process_count; i++){
		printf("%d\t\t%d\t\t",i + 1,process[i]);
		if (allocation[i] != -1){
			printf("%d\n",allocation[i] + 1);
		}else{
			printf("Not allocated\n");
		}
	}

	return 0;
}