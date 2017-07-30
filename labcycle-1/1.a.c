#include<stdio.h>

int main(){
	int n,wt[20],bt[20],tat[20],avwt=0,avtat=0,i,j;
	
	printf("Enter total number of processes(max-20)\n");
	scanf("%d",&n);
	printf("\nEnter the burst time\n");
	for(i=0;i<n;i++)
	{
		printf("p[%d]:",i+1);
		scanf("%d",&bt[i]);//burst time
	}
	wt[0]=0;//wait time
	for(i=1;i<n;i++)
	{
		wt[i]=0;
		for(j=0;j<i;j++)
		{
			wt[i]+=bt[j];
		}
	}
	printf("\n Process\t\tBurst time\twaitingtime\tturnaroundtime");
	
	for(i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
		avwt+=wt[i];
		avtat+=tat[i];
		printf("\np[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
	}
	avwt/=i;
	avtat/=i;
	printf("\n\n avaerage waiting time:%d",avwt);
	printf("\n Average Turnaround time:%d",avtat);
	return 0;
}	

