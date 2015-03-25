#include<stdio.h>
char A[8]={'d','h','a','p','u','s','v','\0'};
long long int getNum(long long int n,long long int m,long long int i);
int main() {

    int t;
    long long int n, o, i, m, div;
    scanf("%d",&t);

    while (t--) {
        scanf("%lld",&n);
        o=n; i=1; m=7;
        while (o>m) {
            o=o-m;
            m=m*7;
            i++;
        }
        m=m/7;
        while (i--) {
            if (o!=0) {
                div=(o-1)/m;
                o=o%m;
                m=m/7;
                printf("%c",A[div]);
            }
            else {printf("%c",A[6]);}
        }
        printf("\n\n");
        // printf("o=%lld i=%lld\n",o,i);
        // d, h, a, p, u, s, v
    }

    return 0;
}

long long int getNum(long long int n,long long int m,long long int i){
    if (n<m) return i;
    else {
        return getNum(n-m,m*7,i+1);
    }
}
