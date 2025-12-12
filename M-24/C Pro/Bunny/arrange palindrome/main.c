#include <stdio.h>
#include <string.h>
int main(){
	char str[1000000000000000],temp;
	int i=0,z=0;
	scanf("%s",&str);
	int n=strlen(str);
	for(int i=0;i<(n/2);i++){
		for(int j=i+1;j<n-i-1;j++){
			if (str[i]==str[j]){
				temp=str[j];
				str[j]=str[n-1-i];
				str[n-1-i]=temp;
				z+=1;
				break;
			}
		}
	}
	char hmm[n];
	strcpy(hmm,str);
	for (int i=0;i<n/2;i++){
			temp=str[i];
			str[i]=str[n-i-1];
			str[n-i-1]=temp;
		}
	if (strcmp(hmm,str)==0){
		printf("%s",hmm);
	}
	else {
		printf("NO SOLUTION");
	}
	return 0;
}
