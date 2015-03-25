#include<stdio.h>

int main() {
    int t;
    long long int n, m, o, a, ans, a1;
    scanf("%d",&t);
    while (t--) {
        ans = 0; a1 = 0;
        scanf("%lld %lld %lld",&n,&m,&o);
        scanf("%lld",&a);
        n--;
        if (a<o) ans = -1;
        else a1++;
        while (n--) {
            scanf("%lld",&a);
            if (a>=o) a1++;
        }
        if (ans != -1 && a1>=m) printf("%lld\n",m);
        else if (ans !=-1 && a1<m) printf("%lld\n",a1);
        else printf("-1\n");
    }
    return 0;
}
