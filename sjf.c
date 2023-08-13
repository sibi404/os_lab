#include<stdio.h>
struct process{
	int pid,bt,wt,tat,at,ct;
};
int main(){
	int n;
	printf("Enter the number of process : ");
	scanf("%d",&n);
	struct process p[n];
	int is_completed[n];

	printf("Enter Burst time and Arrival time  of process\n");
	for (int i = 0; i < n; i++){
		scanf("%d %d",&p[i].bt,&p[i].at);
		p[i].pid = i + 1;
		is_completed[i] = 0;
	}

	int completed = 0;
	int current_time = 0;

	

	while(completed != n){

		int mn = 10000;
		int idx = -1;

		for(int i = 0; i < n; i++){
			if(p[i].at <= current_time && is_completed[i] == 0){
				if (p[i].bt < mn){
					mn = p[i].bt;
					idx = i;
				}

				if (p[i].bt == mn){
					if (p[i].at < p[idx].at){
						mn = p[i].bt;
						idx = i;
					}
				}
			}
		}

		if (idx != -1){
			brust_remaining[idx] -= p[idx].bt;
			current_time += p[idx].bt;

			p[idx].ct = current_time;
			p[idx].tat = current_time - p[idx].at;
			p[idx].wt = p[idx].tat - p[idx].bt;


			is_completed[idx] = 1;
			completed++;
		}else{
			current_time++;
		}
	}


	printf("\nPID\tAT\tBT\tTAT\tCT\tWT\n");
	for (int i = 0; i < n; i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].tat,p[i].ct,p[i].wt);
	}	

	return 0;
}