#include<stdio.h>

int A[100000001];
char Q[1000000001];
int main() {
    int n;
    long long int l, r, j, max, cou, luv, kl, i;
    A[0]=0;
    for (i=1;i<100000001;i++) {
        j=i & (i-1);
        A[i]=A[j]+1;
    }
    scanf("%d",&n);
    while (n--) {
        max=0;cou=0;
        scanf("%lld %lld",&l,&r);
        for (j=l;j<=r;j++) {
            kl=0;
            if (j<100000001) {
                kl =A[j];
            }
            else {
                luv=j;
                while (luv>100000001) {
                    luv = luv &(luv-1) ;
                    kl++;
                }
                kl=kl+A[luv];
            }
            if (cou<kl) {
                cou=kl;
                max=j;
            }
        }
        printf("%lld\n",max);
    }
    return 0;
}
