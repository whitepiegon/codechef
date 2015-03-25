#include<stdio.h>
int A[100001][2];
int main() {
    int t, n, ans, b, i, j;
    scanf("%d",&t);
    while (t--) {
        ans=0;
        scanf("%d",&n);
        for (i=0;i<n;i++) {
            scanf("%d %d",&A[i][0],&A[i][1]);
        }
        b=A[0][1];
        for (i=0;i<n;i++) {
            if (A[i][0]>=b) {
                ans++;
                if (A[i][0]==b) {
                    while (A[i][0]==b && i<n) i++;
                }
                if (i<n) {
                    b=A[i][1];
                }
            }
            else {
                if (b>A[i][1]) b = A[i][1];
            }
            if (i==(n-1)) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
