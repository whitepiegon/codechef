#include<stdio.h>
int heavy(long long int A[22], int n, int mag);
int main() {
    int t, n, k, i, ans, zeroc, chck;
    long long int A[22], sum, mag, pnum;
    scanf("%d",&t);
    while (t--) {
        ans=0; sum=0; zeroc=0;
        scanf("%d %d",&n,&k);
        for (i=0;i<n;i++) {
            scanf("%lld",&A[i]);
            sum = sum+A[i];
            if (A[i]==0) zeroc++;
        }
        if (n>=k && sum==0) {ans=1;}
        else if (k>n-zeroc) {ans=0;}
        else if (sum%k!=0) {ans=0;}
        else if (A[n-1]>sum/k) {ans=0;}
        else {
            mag = sum/k;
            n=n-1;

            while (k) {
                while (A[n]==0) n--;
                if (n==-1) break;
                chck=heavy(A,n,mag);
                if (chck==0) break;
                k--;
            }
            if (k==0) ans=1;

        }
        if (ans==0) printf("no\n");
        else printf("yes\n");
    }
    return 0;
}

int heavy(long long int A[22], int n, int mag) {
    int chck;
    while (A[n]==0) n--;
    if (n == -1) return 0;
    if (A[n]==mag) {
        A[n]=0; return 1;
    }
    else if (A[n]<mag) {
        chck = heavy(A,n-1,mag-A[n]);
        if (chck==1) {
            A[n]=0;
            return 1;
        }
        return heavy(A,n-1,mag);
    }
    else return heavy(A,n-1,mag);
}
