#include<stdio.h>

int main() {
    int t;
    long long int n, k, s1, s2, s3;
    scanf("%d",&t);
    while (t--) {
        scanf("%lld %lld",&n,&k);
        s1=n-k;
        if (s1>=3) {
            s1=s1*(s1-1)*(s1-2);
            s1=s1/6;
        }
        else s1=0;
        s2=n-k;
        if (s2>2) {
            s2=s2*(s2-1);
            s2=s2/2;
            s2=s2*k;
        }
        else s2=0;
        s3=k*(k-1);
        s3=s3/2;
        s3=s3*(n-k);
        s1=s1+s2+s3;
        printf("%lld\n",s1);
    }
    return 0;
}
