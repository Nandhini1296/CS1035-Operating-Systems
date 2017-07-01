#include<stdio.h>
int main()
{
    int nof,i,j,sb[10],eb[10],length[10],f[100];
    char a[]={'A','B','C','D','E'};
    printf("\nEnter the number of files");
    scanf("%d",&nof);
    for(i=0;i<100;i++)
        f[i]=0;
    for(i=0;i<nof;i++)
    {
        printf("\nEnter the length of the file %c",a[i]);
        scanf("%d",&length[i]);
        label:
        printf("\nEnter the Starting block %c",a[i]);
        scanf("%d",&sb[i]);
        for(j=sb[i];j<=(sb[i]+length[i])-1;j++)
        {
            if(f[j]==0)
                f[j]=1;
            else
            {
                printf("\nBlock already allocated");
                printf("\nTry Again");
                goto label;
            }
        }
    }
    printf("\nFile\tLength\tStart Block\tEnd Block\n");
    for(i=0;i<nof;i++)
    {
        eb[i]=(sb[i]+length[i])-1;
        printf("%c\t%d\t%d\t%d",a[i],length[i],sb[i],eb[i]);
        printf("\n");
    }
    return 0;
}