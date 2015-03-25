#include<stdio.h>
void quicksort(long long int [8],int,int);

int main() {
    int T, N, i, ans = 0, chck;
    long long int M, P[8], sum;
    scanf("%d",&T);
    while(T--) {
        ans = 0; sum = 0; chck =0;
        scanf("%d %lld",&N ,&M);
        for (i=0;i<N;i++) {
            scanf("%lld",&P[i]);
        }
        quicksort(P,0,N-1);
        i = 0;
        while (i<N) {
            sum = sum + P[i];
            i++;
            ans++;
            if (sum>=M) {
                chck = 1;
                printf ("%d\n",i);
                break;
            }
        }
        if (chck==0) {
            printf("-1\n");
        }
    }
    return 0;
}

void quicksort(long long int x[8],int first,int last){
    long long int pivot,j,temp,i;

    if(first<last){
        pivot=first;
        i=first;
        j=last;

        while(i<j){
            while(x[i]>=x[pivot]&&i<last)
                i++;
            while(x[j]<x[pivot])
                j--;
            if(i<j){
                temp=x[i];
                x[i]=x[j];
                x[j]=temp;
            }
        }

        temp=x[pivot];
        x[pivot]=x[j];
        x[j]=temp;
        quicksort(x,first,j-1);
        quicksort(x,j+1,last);

    }
}
