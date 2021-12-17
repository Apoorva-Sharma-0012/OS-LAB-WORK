#include<stdio.h>

int front = 0,back = -1,cs = 0,nf;

int isfound(int x, int f[])
{
    int i;
    for(i=0;i<cs;i++) if(f[i]==x) return 1;
    return 0;
}

void enq(int x,int f[])
{
    if(++back==nf)  back=0;
    f[back]=x;
    cs++;
}

void dis(int f[])
{
    int i;
    for(i=0; i<cs;i++)  printf(" %d",f[i]);
    printf("\n");
}

void deq()
{
    cs--;
    if(++front == nf) front=0;
}

void main()
{
    int pf=0,rfs,i;
    printf("\n Enter the size of reference string : ");
    scanf("%d",&rfs);

    int rf[rfs];
    printf("\n Enter the reference string : ");

    for(i=0;i<rfs;i++) scanf("%d",&rf[i]);

    printf("\n Enter the number of free frames: ");
    scanf("%d",&nf);

    int f[nf];

    enq(rf[0],f);
    pf=1;

    for(i=0;i<rfs;i++)
    {
        if(!isfound(rf[i],f))
        {   
            pf++;
            if(cs==nf) deq();
            enq(rf[i],f);
        }
        printf("\n");
        dis(f);
    }

    printf("\n No of page faults :%d",pf);
}
