#include<stdio.h>

int main() {
    int t, val, i, ndas, n, b, sum;
    float f1, f2;
    scanf("%d",&t);
    while (t--) {
        sum=0;
        scanf("%d",&n);
        ndas=n;
        for(i=0;i<n;i++){
            scanf("%d",&b);
            sum=sum+b;
            if (b==0) ndas--;
        }
        if (sum==100) printf("YES\n");
        else if(sum>100) {
            f1=ndas*0.9999999;
            f2=sum-100;
            if (f2<=f1)
            printf("YES\n");
            else printf("NO\n");
        }
        else printf("NO\n");
    }
    return 0;
}
