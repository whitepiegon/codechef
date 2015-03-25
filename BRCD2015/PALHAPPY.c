#include<stdio.h>
#include<string.h>

int main () {
    char A[1001];
    int t, c, l, s, e;
    scanf("%d",&t);
    while (t--) {
        scanf(" %s",A);
        l=strlen(A);
        c=0;
        s=0; e=l-1;
        while (c<2 && s<e) {
            if (A[s] != A[e]) c++;
            s++; e--;
        }
        if (c>1) printf("no\n");
        else printf("yes\n");
    }
    return 0;
}
