#include<stdio.h>
struct process{
	int at,bt,ct,wt,tat,pid;
};

int main(){
	int n,time_quantum;
	printf("Enter number of process : ");
	scanf("%d",&n);
	printf("Enter time quantum : ");
	scanf("%d",&time_quantum);
	struct process p[n];
	int is_completed[n];
	int burst_remaining[n];

	printf("Enter Arrival time and Burst time of process\n");
	for (int i = 0; i < n; i++){
		scanf("%d %d",&p[i].at,&p[i].bt);
		is_completed[i] = 0;
		burst_remaining[i] = p[i].bt;
		p[i].pid = i + 1;
	}

	struct process temp;

	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			if (p[i].at > p[j].at){
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}

	

	int current_time = 0;
	int completed = 0;

	while(completed != n){
		for (int i = 0; i < n; i++){
			if (p[i].at <= current_time){
				if (is_completed[i] == 0){
					if (burst_remaining[i] >= time_quantum){
						burst_remaining[i] = burst_remaining[i] - time_quantum;
						current_time += time_quantum;
					}else if (burst_remaining[i] < time_quantum && burst_remaining[i] > 0){
						current_time += burst_remaining[i];
						burst_remaining[i] = 0;
					}

					if (burst_remaining[i] == 0){
						p[i].ct = current_time;
						p[i].tat = p[i].ct - p[i].at;
						p[i].wt = p[i].tat - p[i].bt;

						is_completed[i] = 1;
						completed++;
					}
				}
			}else{
				current_time++;
			}
		}
	}

	printf("\nPID\tAT\tBT\tTAT\tCT\tWT\n");
	for (int i = 0; i < n; i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].tat,p[i].ct,p[i].wt);
	}

	return 0;
}