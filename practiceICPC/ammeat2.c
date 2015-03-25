#include<stdio.h>

int main() {
    int T, N, K, max, ans;

    scanf ("%d",&T);
    while (T--) {
    scanf("%d %d",&N,&K);
    if (N==1) {printf("1\n");}
    else {
        max = N/2;
        if (K>max) printf("-1\n");
        else {
            ans = max;
            while (K--) {
                printf ("%d ",ans*2);
                ans--;
            }
            printf("\n");
        }
    }}
    return 0;
}
