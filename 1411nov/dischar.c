#include<stdio.h>
#include<string.h>

int main() {int t,j,A[27];long i,ans;char B[100001];
scanf("%d",&t);
while(t--){scanf(" %s",B);for (j=0;j<27;j++) A[j]=0;i=0,ans=0;
while(B[i]!=0){j=B[i]-'a';if(A[j]==0){A[j]=1;ans++;}if (ans==26) break;i++;}
printf("%ld\n",ans);}
return 0;}
