#include<stdio.h>
long int sum[1000001], N[1000001];
int main () {
    char A[4];
    long int n, q, i, j, k, su=0;
    scanf("%ld %ld",&n,&q);
    sum[0]=0;
    for (i=1;i<=n;i++) {
        scanf("%ld",&N[i]);
        su+=N[i];
        sum[i]=su;
    }
    for (k=0;k<q;k++) {
        scanf(" %s",&A);
        scanf("%ld %ld",&i,&j);
        printf("%ld\n",sum[j]-sum[i-1]);
    }
    return 0;
}
