#include <stdio.h>
void main()
{
  int z,x;
  scanf("%d %d",&z,&x);
  for (int i=1;i<=x;i++)
  {
    for (int j=1;j<=z;j++)
    {
      if (i==1 || i==x)
      {
        if (j==1 || j==z){printf("o");}
        else {printf("-");}
      }
      else   
      {
        if  (j!=1 && j!=z){printf(" ");} 
        else {printf("|");}
      }
    }
    printf("\n");
  }
}
