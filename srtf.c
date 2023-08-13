#include<stdio.h>
struct process{
	int pid,at,wt,tat,ct,start_time,rt,bt;
};

int main(){
	int n;
	printf("Enter number of process : ");
	scanf("%d",&n);
	struct process p[n];
	int is_complete[n],burst_remaining[n];
	printf("Enter Arrival time and Burst time of process\n");
	for (int i  = 0; i < n; i++){
		scanf("%d %d",&p[i].at,&p[i].bt);
		burst_remaining[i] = p[i].bt;
		p[i].pid = i + 1;
		is_complete[i] = 0;
	}

	int current_time = 0;
	int completed = 0;


	while (n != completed){
		int idx = -1;
		int mn = 10000;

		for (int i = 0; i < n; i++){
			if (p[i].at <= current_time && is_complete[i] == 0){
				if (burst_remaining[i] < mn){
					mn = burst_remaining[i];
					idx = i;
				}
				if (burst_remaining[i] == mn){
					if(p[i].at < p[idx].at){
						mn = burst_remaining[i];
						idx = i;
					}
				}
			}
		}
		if(idx != -1){
			if(burst_remaining[idx] == p[idx].bt){
				p[idx].start_time = current_time;
			}

			burst_remaining[idx] -= 1;
			current_time++;

			if(burst_remaining[idx] == 0){
				p[idx].ct = current_time;
				p[idx].tat = p[idx].ct - p[idx].at;
				p[idx].wt = p[idx].tat - p[idx].bt;
				p[idx].rt = p[idx].start_time - p[idx].at;

				is_complete[idx] = 1;
				completed++;
			}

		}else{
			current_time++;
		}

	}

	printf("PID\tAT\tBT\tTAT\tWT\tRT\tCT\n");
	for (int i = 0; i < n; i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].tat,p[i].wt,p[i].rt,p[i].ct);
	}

	return 0;

	
}