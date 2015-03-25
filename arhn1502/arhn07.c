#include<stdio.h>
#include<string.h>

int main() {
    int t,n,i,ans;
    char A[1001], B[1001];
    scanf("%d",&t);
    while (t--) {
        scanf(" %s",&A);
        scanf(" %s",&B);
        n=strlen(A);
        if (n==strlen(B)) {
            ans=0;
            for (i=0;i<n;i++) {
                if (A[i]!=B[i]) ans++;
            }
            printf("%d\n",ans);
        }
        else {
            printf("-1\n");
        }
    }
    return 0;
}
