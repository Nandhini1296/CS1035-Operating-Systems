#include<stdio.h>
struct file
{
    int length;
    int block[100];
    int index[100];
}files[100];
int main()
{
    int i,j,nof,temp,k,i1;
    char a[]={'A','B','C','D','E'};
    printf("\nEnter the number of files: ");
    scanf("%d",&nof);
    for(i=0;i<100;i++)
        files[i].block[i]=0;
    for(i=0;i<nof;i++)
    {
        j=0;
        printf("\nEnter the file length %c : ",a[i]);
        scanf("%d",&files[i].length);
        for(k=0;k<files[i].length;k++)
        {
            label:
            printf("\nEnter the index block: ");
            scanf("%d",&temp);
            if(files[i].block[temp]==0)
            {
                for(i1=0;i1<100;i1++)
                    files[i1].block[temp]=1;
                files[i].index[j]=temp;
                j++;
            }
            else
            {
                printf("\nBlock Already Occupied");
                printf("\nTry Agaun");
                goto label;
            }
        }
    }
    printf("\nFile\tLength\tBlocks\n");
    for(i=0;i<nof;i++)
    {
        printf("%c\t%d\t",a[i],files[i].length);
        for(k=0;k<files[i].length;k++)
            printf("%d->",files[i].index[k]);
        printf("\n");
    }
    return 0;
}