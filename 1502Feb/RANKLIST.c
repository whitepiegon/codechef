#include<stdio.h>

int main() {
    int t;
    long long n, s, se, ne;
    scanf("%d",&t);
    while (t--) {
        scanf("%lld %lld",&n,&s);
        if (n*(n+1)==2*s) printf("0\n");
        else {
            se=1;ne=1;
            while (s-se>=n-ne) {
                ne++;
                se+=ne;
            }
            ne--;
            printf("%lld\n",n-ne);
        }
    }
    return 0;
}
