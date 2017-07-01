#include<stdio.h>//mft
int main()
{
    int mem[7][10], n, i,j,psize[10];
    printf("original memory:");
    for(i=0;i<7;i++)
    {
        printf("\n%d (10MB)|",i+1);
        for(j=0;j<10;j++)
        {
            mem[i][j]=0;
            printf(" %d",mem[i][j]);
        }
        printf("|");
    }
    printf("\nEnter the number of processes:");
    scanf("%d",&n);
    printf("\nEnter the size of process:");
    for(i=0;i<n;i++)
    {
        printf("\n%d:",i+1);
        scanf("%d",&psize[i]);
    }
    for(i=0;i<n;i++)
    {
        if(psize[i]<=10)
        {
            for(j=0;j<psize[i];j++)
            {
                mem[i][j]=i+1;
            }
        }
        else
        {
            printf("\n process %d is too big", i+1);
        }
    }

    printf("\nMemory after allocation:");
    for(i=0;i<7;i++)
    {
        printf("\n%d (10MB)",i+1);
        for(j=0;j<10;j++)
            printf("%d ",mem[i][j]);
    }
    return 0;
}

