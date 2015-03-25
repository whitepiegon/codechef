#include<stdio.h>
#include<stdlib.h>

void directi(int x, int y, int n);
char A[100001];
int luv[100001];
int chk[1000000001];
int main () {
    int i, j, n, m, typ, x, y, mod;
    scanf("%d %d",&n,&m);
    scanf(" %s",&A);
    for (i=0;i<n;i++) {
        mod=A[i];j=i+1;
        while (mod%3!=0 && j<n) {
            mod=mod+A[j];
            j++;
        }
        if (mod%3==0) luv[i]=j-1;
        else luv[i]=-1;
    }
    int z=0;
    while (m--) {
        z++;
    if (z==10001) break;
        scanf("%d %d %d",&typ,&x,&y);
        if (typ==1) {
            j=A[x-1];
            A[x-1]=y;
            /*if (j%3 != y%3) {
                for (i=0;i<x;i++) {
                    if (luv[i]>=x-1) {
                        mod=A[i];j=i+1;
                        while (mod%3!=0 && j<n) {
                            mod=mod+A[j];
                            j++;
                        }
                        if (mod%3==0) luv[i]=j-1;
                        else luv[i]=-1;
                    }
                }
            }*/


    for (i=0;i<n;i++) {
        mod=A[i];j=i+1;
        while (mod%3!=0 && j<n) {
            mod=mod+A[j];
            j++;
        }
        if (mod%3==0) luv[i]=j-1;
        else luv[i]=-1;
    }


        }
        else {
            directi(x-1,y-1, n);
        }
    }
    return 0;
}

void directi(int x, int y, int n) {
    int i, j, k, ans=0;
    int *banged;
    banged=(int*)calloc(100001,sizeof(int));
    /*for (k=x;k<=y;k++) {
        j=k;
        while (luv[j] != -1 && j<=y && luv[j]<=y) {
            ans++;
            j=luv[j]+1;
        }
    }*/
    for (k=y;k>=x;k--) {
        if (luv[k]<=y && luv[k]!=-1) {
            banged[k]++;
            if (luv[k]+1<=y) banged[k]+=banged[luv[k]+1];
            ans=ans+banged[k];
        }
        else banged[k] = 0;
    }
    free(banged);
    printf("%d\n",ans);
}
