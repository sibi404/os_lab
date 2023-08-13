// C++ implementation of Best - Fit algorithm
#include<stdio.h>
// Method to allocate memory to blocks as per Best fit algorithm
void bestFit(int blockSize[], int m, int processSize[], int n)
{
	// Stores block id of the block allocated to a process
	int allocation[n];

	// Initially no block is assigned to any process
	for (int i = 0; i < n; i++)
		allocation[i] = -1;

	// pick each process and find suitable blocks
	// according to its size ad assign to it
	for (int i = 0; i < n; i++)
	{
		// Find the best fit block for current process
		int bestIdx = -1;
		for (int j = 0; j < m; j++)
		{
			if (blockSize[j] >= processSize[i]){
				if (bestIdx == -1)
					bestIdx = j;
				else if (blockSize[bestIdx] > blockSize[j])
					bestIdx = j;
			}
		}

		// If we could find a block for current process
		if (bestIdx != -1){
			allocation[i] = bestIdx;
			blockSize[bestIdx] -= processSize[i];
		}
	}

	printf("\nProcess No.\tProcess Size\tBlock no.\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t\t%d\t\t",i+1,processSize[i]);
		if (allocation[i] != -1)
			printf("%d\n",allocation[i] + 1);
		else
			printf("Not Allocated\n");
	}
}

int main(){

	int blocks,process;
	printf("Enter number of memory blocks : ");
	scanf("%d",&blocks);
	printf("Enter number of process : ");
	scanf("%d",&process);

	int blockSize[blocks],processSize[process];

	printf("Enter memory blocks size\n");
	for (int i = 0; i < blocks; i++){
		scanf("%d",&blockSize[i]);
	}

	printf("Enter process size\n");
	for (int i = 0; i < process; i++){
		scanf("%d",&processSize[i]);
	}

	// int blockSize[] = {100, 500, 200, 300, 600};
	// int processSize[] = {212, 417, 112, 426};
	// int m = sizeof(blockSize) / sizeof(blockSize[0]);
	// int n = sizeof(processSize) / sizeof(processSize[0]);

	bestFit(blockSize,blocks, processSize,process);

	return 0 ;
}
