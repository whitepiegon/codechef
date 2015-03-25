#include<stdio.h>

int main() {
    long long int t, x, k, c;
    double i, j, o;
    scanf("%lld",&t);
    while(t--) {
        scanf("%lld %lld",&x,&k);
        c=1;
        while (k>c) {
            c*=2;
        }
        if (k==c) {o=k;i=x/(2*o);}
        else {
            o=c;
            j=x/o;
            i=2*j;
            i=j+i*(k-(o/2));
        }
        printf("%.6lf\n",i);
    }
    return 0;
}
