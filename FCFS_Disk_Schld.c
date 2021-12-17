 #include<stdio.h>

int main()
{
    int n;
    printf("\n Enter the no. of cylinder : ");
    scanf("%d",&n);

    int queue[n], init_pos, total_head = 0;

    printf("\n Enter the cylinder no. : ");
    for(int i=0; i<n; i++) scanf("%d",&queue[i]);

    printf("\n Enter initial position : ");
    scanf("%d", &init_pos);

    for(int i=0; i<n; i++)
    {   total_head += abs(init_pos - queue[i]);
        init_pos = queue[i];
    }

    printf("\n Total No. of Head Movement : %d",total_head);
    printf("\n Average Head Movement : %.2f", (float)total_head/n);

    return 0;
}
