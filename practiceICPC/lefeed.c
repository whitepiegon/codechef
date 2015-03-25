#include<stdio.h>

int main() {
    int i,T, N, M, A[50], zero[50], zeroCount, maxSame, value, izero;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&N,&M);
        zeroCount = 0;
        value = 0; izero = 0; maxSame = 0;
        for (i=0;i<N;i++) {
            scanf("%d",&A[i]);
            if (A[i]==0) {
                zero[zeroCount] = i;
                zeroCount++;
            }
        }
        if (zeroCount == 0) printf("%d\n",findMax(A));
        else if (zeroCount == N-1) {
//------
//------
        }
        else {
//------

long long int total = 1;
i=0;
while(i++<zeroCount) total = total * M;
maxSame = findMax(A);
dealzero(A,zero,0);
//------
        }
    }
    return 0;
}

int findMax(A[]) {
    int value = A[0], i=0, max=0, allmax=0;
    while (value ==0) {
        i++; value = A[i];
    }
    while (i<N) {
        i++;
        if (A[i]==value) max++;
        else {
            if (allmax<max) allmax = max;
            max = 0;

        }
    }
}
