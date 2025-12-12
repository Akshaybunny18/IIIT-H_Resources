// Must create a struct called Vector

/*
 Lab 5D problem 3
*/
#include<stdio.h>
#include <stdlib.h>
struct vector {
		float	a[3];
		};
int main()
{
    // write your code here
	
	struct vector hi[2];
	scanf("%f %f %f",&hi[0].a[0],&hi[0].a[1],&hi[0].a[2]);
	scanf("%f %f %f",&hi[1].a[0],&hi[1].a[1],&hi[1].a[2]);
	if(hi[0].a[0]==0 && hi[0].a[1]==0 && hi[0].a[2]==0 && hi[1].a[0]==0 && hi[1].a[1]==0 && hi[1].a[2]==0){
		printf("0\nYES");
		return 0;
	}
	/*if(abs(hi[0].a[0]/hi[1].a[0]) == abs(hi[0].a[1]/hi[1].a[1]) && abs(hi[0].a[0]/hi[1].a[0]) == abs(hi[0].a[2]/hi[1].a[2]) ){
	printf("0\nYES");
	return 0;}*/
	int f[2];
	f[0]=(hi[0].a[1])*(hi[1].a[2])-(hi[1].a[1])*(hi[0].a[2]);
	int s[2];
	s[0]=-1*((hi[0].a[0])*(hi[1].a[2])-(hi[1].a[0])*(hi[0].a[2]));
	int t[2];
	t[0]=(hi[0].a[0])*(hi[1].a[1])-(hi[0].a[1])*(hi[1].a[0]);
/*	if(fi==0){
		
		else if (th[0]<-1){
			th[1]='-';
		}
		if(se[0]==0){
			if(th[0]==1){
				printf("k\nNO");
			}
			else if (th[0]==-1){
				printf("-k\nNO");
			}
			else{
				printf("%fk\nNO",th[0]);
			}
		else if(th[0]==1 || th[0]==-1){
			if(th[0]==1){
				printf("%fj k\nNO");
			}
			else if (th[0]==-1){
				printf("%fj -k\nNO");
			}
		else{	
			if(th[0]>1){
				th[1]='+';
				printf("%fj %c%fk\nNO",se[0],th[1],th[0]);
			}
			else{
				printf("%fj %fk\nNO",se[0],th[0]);
			
		}*/
	/*	 if(t[1]>0){
		 	t[0]='+';
		 	t[1]=abs(t[1]);
		 }
		 else{
			t[0]='-';
			t[1]=abs(t[1]);
		 if(s[1]>0){
		 	s[0]='+';
		 	s[1]=abs(s[1]);
		 }
		 else{
			s[0]='-';
			s[1]=abs(s[1]);
	      	 if(f[1]>0){
		 	f[0]='+';
		 	f[1]=abs(f[1]);
		 }
		 else{
			f[0]='-';
			f[1]=abs(f[1]);
		 }
		if(f[1]!=0 && t[1]!=0 && s[1]!=0 && f[1]!=1 && t[1]!=1 && s[1]!=1){
			if(f[0]=='-'){
			printf("%c%di %c%dj %c%dk\nNO",f[0],f[1],s[0],s[1],t[0],t[1]);}
			else{
			printf("%di %c%dj %c%dk\nNO",f[1],s[0],s[1],t[0],t[1]);}
		}
		if(f[1]==1 && t[1]==1 && s[1]==1){
			if(f[0]=='-'){
				printf("%ci %cj %ck\nNO",f[0],s[0],t[0]);
			}
			else {
				printf("i %cj %ck\nNO",s[0],t[0]);
			}
		}*/
	if(f[0]==0 && t[0]==0 && s[0]==0){
		printf("0\nYES");
		return 0;
	}
	if(s[0]==0 &&  t[0]==0 ){
      if(f[0]!=0){
		if(f[0]==1){
			printf("i");
		}
		else if(f[0]==-1){
			printf("-i");
		}
		else{
		printf("%di",f[0]);
		}
	}
	}
	else {
    if(f[0]!=0){
		if(f[0]==1){
			printf("i ");
		}
		else if(f[0]==-1){
			printf("-i ");
		}
		else{
		printf("%di ",f[0]);
		}
	}}
	if(t[0]==0){
		if(f[0]!=0){
		if(s[0]>0){
		if(s[0]==1){
			printf("+j ");
		}
		else{
		printf("+%dj ",s[0]);
		}}
		else if(s[0]<0){
		if(s[0]==-1){
			printf("-j ");
		}
		else{
		printf("%dj ",s[0]);
		}}
	}
	else{
		if(s[0]>0){
		if(s[0]==1){
			printf("j ");
		}
		else{
		printf("%dj ",s[0]);
		}}
		else if(s[0]<0){
		if(s[0]==-1){
			printf("-j ");
		}
		else{
		printf("%dj ",s[0]);
		}}
	}
	}


	//ucngsh
	else{
		if(f[0]!=0){
		if(s[0]>0){
		if(s[0]==1){
			printf("+j ");
		}
		else{
		printf("+%dj ",s[0]);
		}}
		else if(s[0]<0){
		if(s[0]==-1){
			printf("-j ");
		}
		else{
		printf("%dj ",s[0]);
		}}
	}
	else{
		if(s[0]>0){
		if(s[0]==1){
			printf("j ");
		}
		else{
		printf("%dj ",s[0]);
		}}
		else if(s[0]<0){
		if(s[0]==-1){
			printf("-j ");
		}
		else{
		printf("%dj ",s[0]);
		}}
	}
	}

	if(f[0]==0 && s[0]==0){
		if(t[0]>0){
		if(t[0]==1){
			printf("k");
		}
		else{
		printf("%dk",t[0]);
		}}
		else if(t[0]<0){
		if(t[0]==-1){
			printf("-k");
		}
		else{
		printf("%dk",t[0]);
		}}
	}
	else{
		if(t[0]>0){
		if(t[0]==1){
			printf("+k");
		}
		else{
		printf("+%dk",t[0]);
		}}
		else if(t[0]<0){
		if(t[0]==-1){
			printf("-k");
		}
		else{
		printf("%dk",t[0]);
		}}
	}
	
printf("\nNO");

    return 0;
} 
