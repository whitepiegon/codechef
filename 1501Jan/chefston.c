#include<stdio.h>
long int A[100001];
int main() {
    int n, t, i;
    long int k;
    long long int b, ans;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %ld",&n,&k);
        for (i=0;i<n;i++) {
            scanf("%ld",&A[i]);
            A[i]=k/A[i];
        }
        ans = 0;
        for (i=0;i<n;i++) {
            scanf("%lld",&b);
            b = A[i]*b;
            ans = ans>b?ans:b;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
