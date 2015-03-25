#include<stdio.h>

int main () {
    int t, k;
    float ans, o, r, s;
    scanf("%d",&t);
    while (t--) {
        scanf("%f %f %f",&o,&r,&s);
        r*=o;
        r+=s;
        ans=r/(o+1);
        printf("%.2f\n",ans);
    }
    return 0;
}
