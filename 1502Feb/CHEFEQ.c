#include<stdio.h>

int main() {
    long int t, A[100002], ans, n, nc, max, i;
    scanf("%ld",&t);
    for (nc=0;nc<100002;nc++) {
        A[nc]=0;
    }
    while (t--) {
        scanf("%ld",&i);
        nc=i;
        max=0;
        while (nc--) {
            scanf("%ld",&n);
            A[n]++;
            max=max>n?max:n;
        }
        ans=0;
        for (nc=0;nc<=max;nc++) {
            ans=ans>A[nc]?ans:A[nc];
            A[nc]=0;
        }
        ans=i-ans;
        printf("%ld\n",ans);
    }
    return 0;
}
