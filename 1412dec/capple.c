#include<stdio.h>
#include<stdlib.h>

int main() {
    int t;int A[100001]={0};
    long int N, nA, i;
    scanf("%d",&t);
    while (t) {
        scanf("%ld",&N);
        i=0;
        while (N--) {
            scanf("%ld",&nA);
            if (A[nA]!=t) {
                A[nA]=t;
                i++;
            }
        }
        printf("%ld\n",i);
        t--;
    }
    return 0;
}
