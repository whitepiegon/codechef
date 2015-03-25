#include<stdio.h>
long long curFac=1, curNum=1, curAns=1, con1=0, con2=0, k,l;
void quicksort(long long [100002],long long,long long);

int main() {
    long long x[100002];
    long long n, m, i;
    scanf("%lld %lld",&n,&m);

    for(i=0;i<n;i++)
        scanf("%lld",&x[i]);

    quicksort(x,0,n-1);

    for(i=0;i<n;i++) {
        k=x[i]%m;
        l=(x[i]+1)%m;
        l=((k*l)/2)%m;
        con2=(con2+((k*l)%m))%m;
        if (x[i]!=curNum && curFac != 0) {
            while (curNum<x[i]) {
                curNum++;
                curFac=(curFac*curNum)%m;
                curAns=(curAns+(curNum*curFac)%m)%m;
            }
        }
        con1=(con1+curAns)%m;
    }

    printf("%lld",(con1+con2)%m);

  return 0;
}

void quicksort (long long x[100002],long long first,long long last){
    long long int pivot,j,i;
    long long temp;

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
