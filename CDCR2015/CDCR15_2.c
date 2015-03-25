#include<stdio.h>

int main () {
    long int t, x, y, z;
    scanf("%ld",&t);
    while (t--) {
        scanf("%ld %ld %ld",&x,&y,&z);
        x=x*z;
        x=x-y*z;
        if (x%y==0) printf("%ld\n",x/y);
        else printf("%ld\n",(x/y)+1);
    }
    return 0;
}
