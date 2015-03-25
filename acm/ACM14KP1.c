#include<stdio.h>
#include<math.h>

void quicksort(float x[100001][2],long int first,long int last);

int main() {
    int T;
    long int N, i, j, k;
    float A[100001][2], ans;
    scanf("%d",&T);
    while(T--) {
        scanf("%ld",&N);
        for (i=0;i<N;i++) {
            scanf("%f %f",&A[i][0],&A[i][1]);
        }
        quicksort(A,0,N-1);
        /*float d12 = sqrtf((A[0][0]-A[1][0])*(A[0][0]-A[1][0]) + (A[0][1]-A[1][1])*(A[0][1]-A[1][1]));
        float d23 = sqrtf((A[1][0]-A[2][0])*(A[1][0]-A[2][0]) + (A[1][1]-A[2][1])*(A[1][1]-A[2][1]));
        float d13 = sqrtf((A[0][0]-A[2][0])*(A[0][0]-A[2][0]) + (A[0][1]-A[2][1])*(A[0][1]-A[2][1]));
        float ans = d12 + d13 + d23;

        float dij, dik, djk;
        for (i=0;i<N;i++){
            for (j=i+1;j<N;j++) {
                dij = sqrtf((A[i][0]-A[j][0])*(A[i][0]-A[j][0]) + (A[i][1]-A[j][1])*(A[i][1]-A[j][1]));
                for (k=j+1;k<N;k++) {
                    dik = sqrtf((A[i][0]-A[k][0])*(A[i][0]-A[k][0]) + (A[i][1]-A[k][1])*(A[i][1]-A[k][1]));
                    djk = sqrtf((A[j][0]-A[k][0])*(A[j][0]-A[k][0]) + (A[j][1]-A[k][1])*(A[j][1]-A[k][1]));
                    if (ans> dij+dik+djk) ans = dij+dik+djk;
                }
            }
        }
        */
        prinf("%f",ans);
        for(i=0;i<N;i++) printf("%f %f\n",A[i][0],A[i][1]);
    }
    return 0;
}

void quicksort(float x[100001][2],long int first,long int last){
    long int pivot,j,i;
    float temp;

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
