#include<stdio.h>
int love[10001][10001], lul[10005];
int main() {
    int t, i, j, n, q, h1, h2, ans, A[100001], luln, lulh1, lulh2;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&q);
        for (i=0;i<n;i++) scanf("%d",&A[i]);

    if (n>50) {
        for (i=0;i<(n/50);i++) {
            ans=A[i*50];
            for (j=i*50;j<(i+1)*50;j++) {
                if (ans==1) break;
                ans = hcf(ans,A[j]);
            }
            lul[i]=ans;
        }
        if (n%50 == 0) luln = n/50;
        else {
            luln = (n/50) +1;
            ans=A[(luln-1)*50];
            for(j=(luln-1)*50;j<n;j++) {
                if (ans==1) break;
                ans = hcf(ans,A[j]);
            }
            lul[luln-1]=ans;
        }

        for (i=0;i<q;i++) {
            scanf("%d %d",&h1,&h2);
            lulh1=(h1-1)/50;
            lulh2=(h2-1)/50;
            if (h1 != 1) {
                if (h1>50) {
                    ans=lul[0];
                    for (j=1;j<lulh1;j++) {
                        if (ans==1) break;
                        ans = hcf(ans,lul[j]);
                    }
                    for (j=lulh1*50;j<(h1-1);j++) {
                        if (ans==1) break;
                        ans = hcf(ans,A[j]);
                    }
                }
                else {
                    ans = A[0];
                    for (j=1;j<(h1-1);j++) {
                        if (ans==1) break;
                        ans = hcf(ans,A[j]);
                    }
                }
                if (lulh2<luln-1) {
                    for (j=h2;j<(lulh2+1)*50;j++) {
                        if (ans==1) break;
                        ans = hcf(ans,A[j]);
                    }
                    for (j=lulh2+1;j<luln;j++) {
                        if (ans==1) break;
                        ans = hcf(ans,lul[j]);
                    }
                }
                else {
                    for (j=h2;j<n;j++) {
                        if (ans==1) break;
                        ans = hcf(ans,A[j]);
                    }
                }
            }
            else {
                if (lulh2<luln-1) {
                    for (j=h2;j<(lulh2+1)*50;j++) {
                        if (ans==1) break;
                        ans = hcf(ans,A[j]);
                    }
                    for (j=lulh2+1;j<luln;j++) {
                        if (ans==1) break;
                        ans = hcf(ans,lul[j]);
                    }
                }
                else {
                    for (j=h2;j<n;j++) {
                        if (ans==1) break;
                        ans = hcf(ans,A[j]);
                    }
                }
            }
            printf("%d\n",ans);
        }
    }
    else {
        for (i=0;i<q;i++) {
            scanf("%d %d",&h1,&h2);
            if (h1 != 1) {
                ans = A[0];
                for (j=1;j<(h1-1);j++) ans = hcf(ans,A[j]);
                for (j=h2;j<n;j++) ans = hcf(ans,A[j]);
            }
            else {
                ans=A[h2];
                for (j=h2+1;j<n;j++) ans = hcf(ans,A[j]);
            }
            printf("%d\n",ans);
        }
    }
    }
    return 0;
}

int hcf(int n1, int n2)
{
    if (n1<=10000 && n2<=10000) {
        if (love[n1][n2] != 0)
            return love[n1][n2];
    }
    int ans;
    if (n2!=0) {
        ans = hcf(n2, n1%n2);
        if (n1<=10000 && n2<=10000) {
            love[n1][n2]=ans;
            love[n2][n1]=ans;
        }
        return ans;
    }
    else
        return n1;
}
