#include<stdio.h>
#include<stdlib.h>

int main() {
    int T,N,K,n,k,i,j;
    scanf("%d",&T);
    int **A, **M, *B, *sum, *maxV, *seq;
    while (T--) {
        scanf ("%d %d",&N,&K);
        n = N; k = K;
        A = (int**) malloc(N*sizeof(int*));
        M = A;
        while(n--) {
            B = (int*) malloc(k*sizeof(int));
            *M = B;
            M++;
        }
        n=N;
        for (i=0;i<n;i++) {
            for (j=0;j<k;j++) {
                scanf("%d",&A[i][j]);
            }
        }
        maxV = (int*) malloc(k*sizeof(int));
        sum = (int*) malloc(k*sizeof(int));
        seq = (int*) malloc(n*sizeof(int));

        for (i=0;i<k;i++) {
            sum[i]=0;
            scanf("%d",&maxV[i]);
        }
        i = 0; j = 0;
        knapsack(sum, &i, j, seq, maxV, N, K);
    }
    return 0;
}

void knapsack (int **sum, int *i, int j, int *seq, int *maxV, int N, int K) {

}
