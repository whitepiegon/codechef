#include<stdio.h>
#include<stdlib.h>
void quicksort(long int *x,int first,int last);
void directi(long long int n, int k);

int main () {
    int t,k;
    long long int sum, n;
    scanf("%d",&t);
    while (t--) {
        scanf("%lld %d",&n,&k);
        if (k==0) {
            sum = (n*(n+1))/2;
            if (sum%2==0) printf("Chef\n");
            else printf("Mom\n");
        }
        else directi(n,k);
    }
    return 0;
}

void directi(long long int n, int k) {
    int i;
    long int *A;
    long long int sum=0, dif=0, cou, wp;

    A=(long int*)calloc(k+1,sizeof(long int));
    for (i=0;i<k;i++) scanf("%ld",&A[i]);
    quicksort(A,0,k-1);
    if (A[0]==1) {
        printf("Chef\n");
        free(A);
        return;
    }
    else if (A[0]==2) {
        printf("Mom\n");
        free(A);
        return;
    }
    dif=A[0];
    wp=A[0]-1;
    sum = (wp*(wp+1))/2;
    for (i=0;i<k-1;i++) {
        if (A[i]+1 == A[i+1]) {
            cou=0;
            while (A[i]+1 == A[i+1] && i<k-1) {
                i++;
                cou++;
                dif+=A[i];
            }
            if (cou>=(sum-wp)) {
                if (sum%2==0) printf("Chef\n");
                else printf("Mom\n");
                free(A);
                return;
            }
        }

        wp=A[i+1]-1;
        sum=(wp*(wp+1))/2 - dif;
        dif+=A[i+1];
    }
    sum=(n*(n+1))/2 - dif;
    if (sum%2==0) printf("Chef\n");
    else printf("Mom\n");
    free(A);
    return;
}

void quicksort(long int *x,int first,int last){
    int pivot,j,i;
    long int temp;
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
