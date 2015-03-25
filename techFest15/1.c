#include<stdio.h>
void quicksort(short int [], int, int);
void printans(short int x[],long int n, long int k);

int main() {
    long int a=0, b=0, c=0, d=0, e=0, N, i;
    short int n, A[100000], B[100000], C[100000], D[100000], E[100000];
    scanf("%ld",&N);
    char ch;
    for (i=0;i<N;i++) {
        scanf (" %c %hd",&ch,&n);
        if (ch == 65){
            A[a]=n;
            a++;
        }
        else if (ch == 66){
            B[b]=n;
            b++;
        }
        else if (ch == 67){
            C[c]=n;
            c++;
        }
        else if (ch == 68){
            D[d]=n;
            d++;
        }
        else if (ch == 69){
            E[e]=n;
            e++;
        }
    }
    quicksort(A,0,a-1);
    if (a>0) printans(A,N,a);
    else printf("Nothing Unusual\n");
    quicksort(B,0,b-1);
    if (b>0) printans(B,N,b);
    else printf("Nothing Unusual\n");
    quicksort(C,0,c-1);
    if (c>0) printans(C,N,c);
    else printf("Nothing Unusual\n");
    quicksort(D,0,d-1);
    if (d>0) printans(D,N,d);
    else printf("Nothing Unusual\n");
    quicksort(E,0,e-1);
    if (e>0) printans(E,N,e);
    else printf("Nothing Unusual\n");
    return 0;
}

void quicksort(short int x[],int first,int last){
    long int pivot,j,temp,i;

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

void printans(short int x[],long int n, long int k) {
    long int count=1, limit, i;
    n = k;
    short int lvalue = x[0], chck = 0;
    limit = (0.1 * n) + 1;

    for (i=1;i<k;i++) {
        if (x[i] == lvalue) {
            count ++;
        }
        else {
            if (count>=limit) {
                chck = 1;
                printf ("%hd ",lvalue);
            }
            lvalue = x[i];
            count = 1;
        }
    }
    if (count>=limit) {printf("%hd\n",lvalue);  chck = 1;}
    else if (chck == 0) printf("Nothing Unusual\n");
    else printf("\n");
}
