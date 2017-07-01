#include<stdio.h>
struct block
{
    int index;
    int size;
    int block1[100];
}blocks[100];
struct file
{
    char name[20];
    int block;
}file[100];
int main()
{
    int no_of_blocks,no_of_files,i,j,k=0;
    printf("\nEnter the number of block ");
    scanf("%d",&no_of_blocks);
    for(i=0;i<no_of_blocks;i++)
    {
        printf("\nEnter the block index ");
        scanf("%d",&blocks[i].index);
        printf("\nEnter the size of the block %d ",blocks[i].index+1);
        scanf("%d",&blocks[i].size);
        printf("\nEnter the block for %d ",blocks[i].index+1);
        for(j=0;j<blocks[i].size;j++)
            scanf("%d",&blocks[i].block1[j]);
    }
    printf("\nEnter the number of files ");
    scanf("%d",&no_of_files);
    for(i=0;i<no_of_files;i++)
    {
        printf("\nEnter the file name ");
        scanf("%s",&file[i].name);
        printf("\nEnter the block index ");
        scanf("%d",&file[i].block);
    }
    printf("\nFile\t\tIndex\t\tLength\t\tBlocks\n");
    for(i=0;i<no_of_files;i++)
    {
        printf("%s\t%d\t%d\t",file[i].name,file[i].block,blocks[i].size);
        for(j=0;j<blocks[i].size;j++)
        {
            printf("%d",blocks[i].block1[j]);
            k=1;
        }
        printf("\n");
    }
    return 0;
}
