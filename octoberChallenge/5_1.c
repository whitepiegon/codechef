#include <stdio.h>

void quicksort(long int x[2000][2],int,int);

int main(){
  long int x[2000][2];
  int size,i;

  printf("Enter size of the array: ");
  scanf("%d",&size);

  printf("Enter %d elements: ",size);
  for(i=0;i<size;i++)
    scanf("%ld %ld",&x[i][0],&x[i][1]);

  quicksort(x,0,size-1);

  printf("Sorted elements: ");
  for(i=0;i<size;i++)
    printf(" %d %d\n",x[i][0],x[i][1]);

  return 0;
}

void quicksort(long int x[2000][2],int first,int last){
    int pivot,j,i,xi;
    long int temp, X=NULL;
    if(first<last){
        pivot=first;
        i=first;
        j=last;

        while(i<j){
            xi = i;
            while(x[i][0]<=x[pivot][0]&&i<last) {
                if (x[i][0]==X) {
                    ;
                }
                else {
                    if (xi!=i) {quicksorty(x,xi,i-1);xi=i-1;}
                    xi++;
                    X=x[i][0];
                }
                i++;
            }
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
