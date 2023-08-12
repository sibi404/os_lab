#include<stdio.h>
struct Process{
	int bt,id,wt,tat,at,ct; 
};

int main(){
	int n;
	printf("Enter number of process : ");
	scanf("%d",&n);
	struct Process p[n];
	printf("Enter arrival time and burst time of process\n");
	for (int i = 0; i < n; i++){
		scanf("%d %d",&p[i].at,&p[i].bt);
		p[i].id = i + 1;
	}

	struct Process temp;

	for (int i = 0; i < n; i++){
		for (int j = i+ 1; j < n ; j++){
			if (p[i].at > p[j].at){
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}

	p[0].ct = p[0].at + p[0].bt;
	p[0].tat = p[0].ct - p[0].at;
	p[0].wt = p[0].tat - p[0].bt;


	for (int i = 1; i < n; i++){
		int temp = 0;
		if (p[i - 1].ct < p[i].at){
			temp = p[i].at - p[i - 1].ct;
		}
		p[i].ct = p[i - 1].ct + p[i].bt+temp;
		p[i].tat = p[i].ct - p[i].at;
		p[i].wt = p[i].tat - p[i].bt;
	}

	printf("\nID\tAT\tBT\tCT\tTAT\tWT\n");
	for (int i = 0; i < n; i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	}

	return 0;
}