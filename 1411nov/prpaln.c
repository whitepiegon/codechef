#include<stdio.h>
#include<string.h>
char A[1000001];
long int l;
int main() {
    int a;
    long int t;
    scanf("%ld",&t);
    while (t--) {
        scanf(" %s",A);
        l=strlen(A);
        a=chck(0,l-1,0);
        if (a==1) printf ("YES\n");
        else printf("NO\n");
    }
    return 0;
}

int chck(long int i, long int j, int c) {
    int y=0;
    if (i>l/2) return 1;
    if (A[i]==A[j]) return chck(i+1,j-1,c);
    else if (c==1) return 0;
    y=chck(i+1,j,1);
    if (y==1) return 1;

    y=chck(i,j-1,1);
    return y;
}
