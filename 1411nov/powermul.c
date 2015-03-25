#include<stdio.h>
#include<math.h>
int main() {
    int A[501], q;
    long int t,n,p,l,i;
    long long int m, ans, r, k;
    long long int num, deno;
    scanf("%ld",&t);
    while (t--) {
        scanf("%ld %lld %lld",&n,&m,&r);
        while (r--) {
    scanf("%ld",&p);
l=n-p;
if (p>l) {
    p=l; l=n-p;
}
l=l+1;
for (q=0;q<l;q++) A[q]=0;
while (l<n) {

}
if (m<n) {
    if (A[m]!=0) printf("0\n");
}
else {
    num = 1;
    while (l<=n) {
        long long int o = pow((l%m),(l%(m-1)));
        num=num*(o%m);
        l++;
    }
    deno=1;
    while (p>=1) {
        long long int u = pow((p%m),(p%(m-1)));
        deno=deno*(u%m);
        p--;
    }
    if (num!=0 && deno!=0)
    num = (num/deno)%m;
    else num=0;
    printf("%lld\n",num);
}
        }
    }
}
