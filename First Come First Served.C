#include<stdio.h>
#include<conio.h>
void main()
{
int n,bt[20],wt[20],tat[20],avwt=0,atat=0,i,j;
clrscr();
printf("\nEnter the number of process: ");
scanf("%d",&n);
printf("\nEnter process Burst Time: ");
for(i=0;i<n;i++)
{
	printf("P[%d]:",i+1);
	scanf("%d",bt[i]);
}
wt[0]=0;
//calculating waiting time
for(i=1;i<n;i++)
{
	wt[i]=0;
	for(j=0;j<n;j++)
	{
		wt[i]+=bt[j2];
	}
}
printf("\nProcess\t\tBurst Time\t\tWaiting Time\t\tTurn Around Time");
//calculate turn around time
for(i=0;i<n;i++)
{
	tat[i]=bt[i]+wt[i];
	avwt+=wt[i];
	avtat+=tat[i];
	printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
}
avwt/=i;
avtat/=i;
printf("\nAverage waiting time is: %d",avwt);
printf("\nAverage turn around time is: %d",avtat);
getch();
}

