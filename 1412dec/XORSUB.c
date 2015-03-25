#include <stdio.h>

int ans, k, n;
int B[1024];
int main() {
    int t, p, i, A[1001];
    scanf("%d",&t);
    while (t--) {
        for (i=0;i<1024;i++) B[i]=0;
        scanf("%d %d",&n,&k);
        for (i=0;i<n;i++) scanf("%d",&A[i]);
        ans = k;
        for (i=0;i<n;i++) getmax(A,i+1,A[i]);
        printf("%d\n",ans);
    }
    return 0;
}

int getmax(int A[], int i, int p) {
    if (B[p]==1) return 0;
    if (i==n) {
        B[p]=1;
        p=p^k;

        if (p>ans) ans=p;
        return 0;
    }
    getmax(A,i+1,p^A[i]);
    getmax(A,i+1,p);
}
