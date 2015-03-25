#include<stdio.h>
#include<stdbool.h>

long int A[100001], func[100001][2], type1[100001][2], L[100001][11];
long long int sum[100001];
int chck[100001];

int main () {
    int n, i, j, q, x, y, k;
    long long int ans;
    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%ld",&A[i]);
    for (i=0;i<n;i++) {
        scanf("%ld %ld",&x,&y);
        func[i][0]=x-1;
        func[i][1]=y-1;
    }
    for (i=0;i<n;i++) {
        for (j=func[i][0];j<=func[i][1];j++) {
            sum[i]=sum[i]+A[j];
            L[i][j-func[i][0]]=A[j];
        }
    }
    scanf("%d",&q);
    i=0;
    while (q--) {
        scanf("%d %d %d",&n,&x,&y);
        x-=1;
        y-=1;
        if (n==1) {
            type1[i][0]=x;
            type1[i][1]=y;
            i++;
        }
        else if (n==2) {
            ans=0;
            for (j=x;j<=y;j++) {
                if (chck[j]<i) {
    for (k=chck[j];k<i;k++) {
        if (type1[k][0]>= func[j][0] && type1[k][0]<=func[j][1]) {
            sum[j]=sum[j]-L[j][type1[k][0]-func[j][0]]+type1[k][1]+1;
            L[j][type1[k][0]-func[j][0]]=type1[k][1]+1;
        }
    }
                chck[j]=i;
                }
            ans+=sum[j];
            }
            printf("%lld\n\n",ans);
        }
    }
    return 0;
}
