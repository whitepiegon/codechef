#include<stdio.h>

long long cur[100001], khistory[50001], ans, kstart[50001][3], kend[50001][3];
void quickS (long long x[50001][3], long long y[50001][3], long long i, long long j);

int main () {
    long long n, m, k, i, j, kh=0, ks=0, ke=0;
    scanf("%lld %lld %lld",&n,&m,&k);
    for (i=0;i<k;i++) {
        scanf("%lld %lld %lld %lld",&kstart[i][0],&kstart[i][1],&kend[i][0],&kend[i][1]);
        kstart[i][2] = i; kend[i][2] = i;
    }
    if (k>0) {
        quickS (kstart,kend,0,k-1);
        quickS (kend,kstart,0,k-1);
    }
    for (i=0;i<m;i++) {
        cur[i]=1;
    }
    while (ke<k && kend[ke][0]==n+1) {
        khistory[kh]=1;
        kstart[kend[ke][2]][2]=kh;
        kh++; ke++;
    }
    while (ks<k && kstart[ks][0] == n) {
        j=kstart[ks][1];
        cur[j]=(cur[j]+1)%1000000007;
        ks++;
    }
    while (ke<k && kend[ke][0] == n) {
        khistory[kh]=cur[kend[ke][1]];
        kstart[kend[ke][2]][2]=kh;
        kh++;ke++;
    }
    for (i=2;i<=n;i++) {
        ans=0;
        for(j=0;j<m;j++) ans=(ans%1000000007+cur[j])%1000000007;
        for(j=0;j<m;j++) cur[j]=ans;
        while (ks<k && kstart[ks][0] == (n+1-i)) {
            j=kstart[ks][1];
            cur[j]=(cur[j]%1000000007+khistory[kstart[ks][2]])%1000000007;
            ks++;
        }
        while (ke<k && kend[ke][0] == (n+1-i)) {
            khistory[kh]=cur[kend[ke][1]];
            kstart[kend[ke][2]][2]=kh;
            kh++;ke++;
        }
    }
    while (ks<k && kstart[ks][0] == 0) {
        j=kstart[ks][1];
        cur[j]=(cur[j]%1000000007+khistory[kstart[ks][2]])%1000000007;
        ks++;
    }
    ans=0;
    for (i=0;i<m;i++) (ans=ans%1000000007+cur[i])%1000000007;
    printf("%lld\n",ans%1000000007);
    return 0;
}

void quickS (long long x[50001][3], long long y[50001][3], long long first, long long last) {
    long long pivot, j, temp[4], i;

    if(first<last){
        pivot=first;
        i=first;
        j=last;

        while(i<j){
            while(x[i][0]>=x[pivot][0]&&i<last)
                i++;
            while(x[j][0]<x[pivot][0])
                j--;
            if(i<j){
                y[x[i][2]][2]=j;
                y[x[j][2]][2]=i;
                temp[0]=x[i][0]; temp[1]=x[i][1]; temp[2]=x[i][2];

                x[i][0]=x[j][0]; x[i][1]=x[j][1]; x[i][2]=x[j][2];

                x[j][0]=temp[0]; x[j][1]=temp[1]; x[j][2]=temp[2];
            }
        }
        y[x[pivot][2]][2]=j;
        y[x[j][2]][2]=pivot;
        temp[0]=x[pivot][0]; temp[1]=x[pivot][1]; temp[2]=x[pivot][2];

        x[pivot][0]=x[j][0]; x[pivot][1]=x[j][1]; x[pivot][2]=x[j][2];

        x[j][0]=temp[0]; x[j][1]=temp[1]; x[j][2]=temp[2];

        quickS(x,y,first,j-1);
        quickS(x,y,j+1,last);
    }
}
