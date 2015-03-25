#include<stdio.h>

int main() {
    char c;
    int n, k, count, t, op;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&k);
        count=0;
        op=1;
            scanf("%c",&c);
        while (n--) {
            scanf("%c",&c);
            if (c=='.') count=0;
            else count++;
            if (count>=k) {
                op=0;
            }
        }
        if (op==1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
