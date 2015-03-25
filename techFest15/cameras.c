#include<stdio.h>

void quicksort(long int [100000][2],long int,long int);

int main () {
    long int N, K, nodeValue, a, b, i, C[100000][2];

    scanf("%ld %ld",&N,&K);

    for (i=0;i<N;i++) {
        scanf("%ld",&C[i][0]);
        C[i][1]=1;
    }
    quicksort(C,0,N-1);
    N = 0;
    while (K--) {
        i = 0;
        scanf("%ld %ld",&a,&b);
        i = getposition(C,a,0,N-1);
        while (C[i][0] < b) {
            if (C[i][0] >= a ) {
                if (C[i][1] != 0) {
                    N++;
                    C[i][1] = 0;
                }
                i++;
            }
            else {i++;}
        }
    }
    printf("%ld",N);
    return 0;
}

long int getposition(long int C[100000][2],long int a,long int ini,long int las) {

};

void quicksort(long int x[100000][2],long int first,long int last){
    long int pivot,j,temp,i;

    if(first<last){
        pivot=first;
        i=first;
        j=last;

        while(i<j){
            while(x[i][0]<=x[pivot][0]&&i<last)
                i++;
            while(x[j][0]>x[pivot][0])
                j--;
            if(i<j){
                temp=x[i][0];
                x[i][0]=x[j][0];
                x[j][0]=temp;
            }
        }

        temp=x[pivot][0];
        x[pivot][0]=x[j][0];
        x[j][0]=temp;
        quicksort(x,first,j-1);
        quicksort(x,j+1,last);
    }
}
