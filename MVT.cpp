#include<stdio.h>//mvt
int main()
{
    int ms,mp[10],i,temp,n=0;
    int m=1;
    printf("\n enter the total memory available(in bytes)--");
    scanf("%d",&ms);
    temp=ms;
    for(i=0;m==1;i++){
        printf("enter memory required for process %d(in bytes)--",i+1);
        scanf("%d",&mp[i]);
        if(mp[i]<=temp)
        {
            printf("\n memory is allocated for process %d",i+1);
            temp=temp-mp[i];
        }
        else
        {
            printf("\n memory is full");
        }
        printf("\n do you want to continue (1/0)--");
        scanf("%d",&m);
        n=i;
    }
    printf("\n\n Total memory available --%d",ms);
    printf("\n\n Process\t\tmemory allocated");
    for(i=0;i<=n;i++)
        printf("\n\t%d\t\t%d",i+1,mp[i]);
    printf("\n\n Total memory allocated is %d",ms-temp);
    printf("\n total external fragmentation is %d", temp);
    return 0;
}
