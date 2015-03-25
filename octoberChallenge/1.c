#include<stdio.h>

int main() {
    int t;
    int N, n, ne, max;
    long int M, diff, lol;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %ld",&N, &M);
        scanf("%d",&ne);
        max = ne;
        N--;
        diff = 0;   n = 1;
        while (N--) {
            scanf("%d",&ne);
            if (ne>max) {
                diff = diff + ((ne-max) * n);
                max = ne;
            }
            else {
                diff = diff + (max - ne);
            }
            n++;
        }
        lol = diff - M;
        if (lol == 0) printf("Yes\n");
        else if (lol>0 && lol%N==0)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
