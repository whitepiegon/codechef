#include<stdio.h>
int A[1001][1001], w, h;

int main () {
    int i, j, p, x, y;
    scanf("%d %d %d",&h,&w,&y);
    for (i=0;i<h;i++) {
        for (j=0;j<w;j++) {
            A[i][j]=0;
        }
    }
    scanf("%d",&p);
    for (i=0;i<p;i++) {
        scanf("%d %d",&x,&y);
        A[x-1][y-1]=1;
    }
    int op=1, po=2;
    while (op==1) {
    scanf("%d",&p);
    op=0;
    for (i=0;i<p;i++) {
        scanf("%d %d",&x,&y);
        if (op==0 && A[w/2+x-1][h/2+y-1]!=1 && w/2+x-1>=w && h/2+y-1>=h)
            A[w/2+x-1][h/2+y-1]=po;
        else {
            if (op==0) {
                undo(po);
                po++;
            }
            op=1;
            //break;
        }
    }
    }
    for (i=0;i<h;i++) {
        for (j=0;j<w;j++) {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    return 0;
}
void undo(int k) {
    int i, j;
    for (i=0;i<h;i++) {
        for (j=0;j<w;j++) {
            if (A[i][j]==k) {
                A[i][j]=0;
            }
        }
    }
}
