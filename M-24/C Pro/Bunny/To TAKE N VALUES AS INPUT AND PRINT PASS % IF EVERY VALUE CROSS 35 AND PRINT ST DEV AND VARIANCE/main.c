#include <stdio.h>
#include <math.h>
void main(){
int n;
int fail = 0,pass=0,m;
int var,varr ;
scanf("%d",&n);
int x[n];
for (int i=0;i<n;i++) {
    scanf("%d",&x[i]);
    if ((x[i]<0) || (x[i]>100)){printf("error");}
    else if ((x[i])<35){fail+=1;}
    else {
      pass+=1;
    }
    m=m+x[i];
  }
  float r = (pass*100)/n;
printf("pass pct is %f",r);
int me = m/n;
for (int v=0;v<n;v++){
var= pow((me-x[v]),2)+var;}
varr=var/10;
int sd;
sd=sqrt(varr);
printf("varr %d",varr);
printf("strddde %d",sd);

}





