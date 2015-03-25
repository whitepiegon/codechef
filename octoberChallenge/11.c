#include<stdio.h>

int main() {
    int t;
    int N, n, max, A[101];
    long int M, diff, lol;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %ld",&N, &M);
        scanf("%d",&A[0]);
        max = A[0];
        N--;
        diff = 0;   n = 1;
        while (N--) {
            scanf("%d",&A[n]);
            max = max>=A[n]?max:A[n];
            n++;
        }
        n--;	diff = 0;
        while (n>=0) {
        	diff = diff + (max - A[n]);
        	n--;
        }
        lol = M - diff;
        if (lol == 0) printf("Yes\n");
        else if (lol>0 && lol%N==0)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
