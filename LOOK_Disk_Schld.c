#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int comparator(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int total_cylinder,n,init_pos,direction;

    printf("\n Enter the total number of cylinders : ");
    scanf("%d",&total_cylinder);

    printf("\n Enter the number of cylinders : ");
    scanf("%d",&n);

    int queue[n];
    bool visit[n];

    for(int i=0; i<n; i++) visit[i]=false;
    
    printf("\n Enter %d number of cylinders in ready queue : ",n);
    for(int i=0; i<n; i++) scanf("%d",&queue[i]);

    printf("\n Enter the current position of head : ");
    scanf("%d",&init_pos);

    printf("\n Enter the direction of movement : ");
    scanf("%d",&direction);   // 0 = lower side  1 = higher side

    int total_movement=0;

    qsort(queue,n,sizeof(int),comparator);

    if(direction == 0)
    {   
        total_movement += abs(init_pos - queue[0]);
        total_movement += abs(queue[0] - queue[n-1]);
    }
    else 
    { 
        total_movement += abs(queue[n-1] - init_pos);
        total_movement += abs(queue[n-1] - queue[0]);  
    }

    printf("\n Total head movement : %d",total_movement);
    printf("\n Average head movement : %.2f",(float)total_movement/n);

    return 0;
}
