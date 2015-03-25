#include<stdio.h>

int main() {
    int t, x, y, p, c, n, k, ans;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d %d %d",&x,&y,&k,&n);
        x=x-y;ans=0;
        while (n--) {
            scanf("%d %d",&p,&c);
            if (c<=k && p>=x)
                ans=1;
        }
        if (ans==1) printf("LuckyChef\n");
        else printf("UnluckyChef\n");
    }
    return 0;
}
