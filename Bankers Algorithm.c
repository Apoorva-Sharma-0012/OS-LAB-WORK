#include<stdio.h>
int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  int max[n][m], alloc[n][m], need[n][m], available[m];
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      scanf("%d",&alloc[i][j]);
  
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      scanf("%d",&max[i][j]);
  
  for(int i=0;i<m;i++)
    scanf("%d",&available[i]);
  
  int finished[n],index=0,sequence[n];

  for(int i=0;i<n;i++)
    finished[i]=0;

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      need[i][j] = max[i][j] - alloc[i][j];
    
  for(int i=0;i<n;i++)
  {  for(int j=0;j<m;j++)
      printf("%d ",need[i][j]);
  printf("\n");
  }
  for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)
    {
      if(finished[i]==0)
      {
        int flag=0;
        for(int j=0;j<m;j++)
          if(need[i][j] > available[j])
          {
            flag=1;
            break;
          }
        if(flag==0)
        {
          sequence[index++] = i;
          for(int j=0;j<m;j++)
            available[j] += alloc[i][j];
          finished[i] = 1;
        }
      }
    }
  printf("\n");
  for(int i=0;i<n;i++)
  printf("%d ", finished[i]);
  printf("\n");
    // for(int i=0;i<n;i++)
    //   if(finished[i]==0)
    //     {
    //       printf("Unsafe State ");
    //       return 0;
    //     }

  printf("Safe Sequence :\n");
  for(int i=0;i<n;i++)
  printf("P%d ",sequence[i]);
}
