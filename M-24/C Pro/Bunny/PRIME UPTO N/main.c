#include <stdio.h>
void main()
{
  int a,x,c,y;
  y=0;
  scanf("%d",&a);
  printf("2");
  for (x=3;x<=a;x++)
  {
    for (c=2;c<=(x/2);c++)
    {
      if (x%c==0){y+=1;}
    }
    if (y==0){printf("%d",x);}
    y=0;
  }
}





