#include<stdio.h>

long long curAns=1, con1=0, con2=0, k,l;
long long c2[100000002];
int main() {
    long long n, m, i, x;
    scanf("%lld %lld",&n,&m);

    c2[0]=1;
    for (i=1;i<m;i++) {
        c2[i]=(i*c2[i-1])%m;
    }

    for(i=0;i<n;i++) {
        scanf("%lld",&x);
        if (x%2==0) {
            k=x/2;
            k=k%m;
            l=(x+1)%m;
            l=(k*l)%m;
        }
        else {
            k=x%m;
            l=(x+1)/2;
            l=l%m;
            l=(k*l)%m;
        }
        k=x%m;
        l=(k*l)%m;
        con2=(con2+l)%m;
        if (x<m-1) {
            curAns = c2[x+1]-1;
        }
        else curAns = -1;
        con1=(con1+curAns)%m;
    }
    con1=(con1+con2)%m;
    printf("%lld",con1);

  return 0;
}
