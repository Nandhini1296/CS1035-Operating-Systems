#include <stdio.h>//fifo

int i,j,nof,nor,flag=0,ref[50],frm[50],pf=0,victim=-1;
int main()
{
    printf("\nEnter the no. of frames: ");
    scanf("%d",&nof);
    printf("\nEnter no. of reference string: ");
    scanf("%d",&nor);
    printf("\nEnter the reference string: ");
    for(i=0;i<nor;i++)
        scanf("%d",&ref[i]);
        for(i=1;i<nof;i++)
            frm[i]=-1;
    printf("\n");
    for(i=0;i<nor;i++)
    {
        flag=0;
        printf("\nReference: %d\t,ref[i]");
        for(j=0;j<nof;j++)
        {
            if(frm[j]==ref[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            pf++;
            victim++;
            victim=victim%nof;
            frm[victim]=ref[i];
            for(j=0;j<nof;j++)
                printf("%4d",frm[j]);
        }
    }
    printf("\nNo of. Page faults: %d",pf);
    return 0;
}