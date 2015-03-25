#include<stdio.h>
#include<stdlib.h>
int love(int i, int num, int parent);
int query (int u, int v, int parent, int mn);

int n, q, b, ans, min;
int Q[10001][1001], A[10001], P[10001][1001], S[10001];
int main() {
    int k, i, u, v;

/*    P = calloc(10001, sizeof(*P));
    int *data = (int*)(calloc(10001*10001, sizeof(int)));
    for (i = 0; i < 10001; i++)
        P[i] = &data[i * 10001];
*/

    scanf("%d %d %d",&n,&k,&b);
    for (i=0;i<n-1;i++) {
        scanf("%d %d",&u,&v);
        Q[u][v]=1;
        Q[v][u]=1;
    }
    for (u=1;u<=n;u++)
    love (0,u,0);
    /*for (u=1;u<=n;u++) {
        for (v=1;v<=n;v++) printf("%d ",P[u][v]);
        printf("\n");
    }*/
    for (i=1;i<=n;i++) {
        scanf("%d",&A[i]);
    }
    scanf("%d",&q);
    for (i=0;i<q;i++) {
        scanf("%d %d",&u,&v);
        ans=-1; min=-1;
        if (A[u]==v) {
            ans=u; min=P[u][b];
            int j;
            for (j=1;j<=n;j++) {
                if(Q[u][j]==1) {
                    query(j,v,u,P[u][b]);
                }
            }
        }
        else query(u,v,0,P[u][b]);

        printf("%d\n",ans);
    }
    return 0;
}

int love(int i, int num, int parent) {
    S[i]=num;
    int j;
    for (j=1;j<=n;j++) {
        if(Q[num][j]==1 && j!=parent) {
            love(i+1,j,num);
        }
    }
    for (j=i-1;j>=0;j--) {
        P[num][S[j]]=i-j;
        P[S[j]][num]=i-j;
    }
    S[i]=0;
    return 0;
}

int query (int u, int v, int parent, int mn) {
    if (A[u]==v) {
        mn=mn<P[u][b]?mn:P[u][b];
        if (min==-1) {
            ans = u;
            min=mn;
        }
        if (min<mn) {
            ans = u;
            min=mn;
        }
        if (min==mn && ans>u) {
            ans=u;
        }
    }
    int j;
    mn=mn<P[u][b]?mn:P[u][b];
    for (j=1;j<=n;j++) {
        if(Q[u][j]==1 && j!=parent) {
            query(j,v,u,mn);
        }
    }
    return 0;
}
