#include<stdio.h>
#include<conio.h>
void main()
{
int n,wt[20],p[20],bt[20],tat[20],i,j,pos,temp,total=0;
float avwt,avtat;
clrscr();
printf("\nEnter no. of process: ");
scanf("%d",&n);
printf("\nEnter the Burst time: ");
for(i=0;i<n;i++)
{
	printf("\nP[%d]",i+1);
	scanf("%d",&bt[i]);
	p[i]=i+1;
}
//Sorting the burst number in ascending order using selection sort
for(i=0;i<n;i++)
{
	pos=i;
	for(j=i+1;j<n;j++)
	{
		if(bt[j]<bt[pos])
		{
			pos=j;
		}
	}
	temp=bt[i];
	bt[i]=bt[pos];
	bt[pos]=temp;

	temp=p[i];
	p[i]=p[pos];
	p[pos]=temp;
}
wt[0]=0;
//Calculate the waiting time
for(i=1;i<n;i++)
{
	wt[i]=0;
	for(j=0;j<i;j++)
	{
		wt[i]+=bt[j];
	}
	total+=wt[i];
}
avwt=(float)total/n;
total=0;
printf("\nProcess\tBurst Time\tWaiting Time\tTurn Around Time");
//Calculate turn around time
for(i=0;i<n;i++)
{
	tat[i]=wt[i]+bt[i];
	total+=tat[i];
	printf("\n%d\t\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i],tat[i]);
}
avtat=(float)total/n;
printf("\nAverage waiting time: %f",avwt);
printf("\nAverage turn around time: %f",avtat);
getch();
}

