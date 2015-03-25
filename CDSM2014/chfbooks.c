#include<stdio.h>
void quicksort(long long int x[100001],long int first,long int last);
int main() {
    long int t;
    long long int A[100001], sum1, sum2, n, m, i;
    scanf("%ld",&t);
    while (t--) {
        sum1=0;
        scanf("%lld %lld",&n,&m);
        for (i=0;i<n;i++) {
            scanf("%lld",&A[i]);
            sum1 = sum1+A[i];
        }
        sum2=sum1;
        quicksort(A,0,n-1);
        for (i=0;i<m;i++) {
            sum1=sum1-(2*A[i]);
            sum2=sum2-(2*A[n-1-i]);
        }
        if(sum2<0) sum2*=-1;
        sum1=sum1>sum2?sum1:sum2;

        printf("%lld\n",sum1);
    }
    return 0;
}

void quicksort(long long int x[100001],long int first,long int last){
    long int pivot,j,i;
    long long int temp;

    if(first<last){
        pivot=first;
        i=first;
        j=last;

        while(i<j){
            while(x[i]<=x[pivot]&&i<last)
                i++;
            while(x[j]>x[pivot])
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
