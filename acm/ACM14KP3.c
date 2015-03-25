#include<stdio.h>
#include<conio.h>

int chechkleft(char A[1000001],char B[1000001],long int n, long int st, long int i);
int chechkright(char A[1000001],char B[1000001],long int n, long int st, long int i);

int main() {
    int T, ma, leftt, rightt;
    long int n, ans, i, lol, rofl;
    scanf("%d",&T);
    char A[1000001], B[1000001];
    for (ma=1;ma<=T;ma++) {
        ans = 0;
        scanf(" %s",A);
        scanf(" %s",B);
        n = strlen(A);
        n= n*1;
        i=0;
        while (ans==0) {
            if (A[0] == B[n-1-i]) {/**/
                lol  = n-1-i;
                rofl = n-i;
                leftt = chechkleft(A,B,rofl,0,lol);
                rightt = chechkright(A,B,rofl,0,0);
                if (leftt ==1 || rightt == 1) {
                    ans = n-i;
                }
            }
            i++;
        }
    printf("Case %d: %ld\n",ma,ans);
    }
return 0;
}

int chechkleft(char A[1000001],char B[1000001],long int n, long int st, long int i) {
    st++; i--;
    if (st==n) return 1;
    else if (A[st]==B[i]) return chechkleft(A,B,n,st,i);
    else return 0;
}

int chechkright(char A[1000001],char B[1000001],long int n, long int st, long int i) {
    st++;
    if (st==n) return 1;
    else if (A[st]==B[i]) {
        i++;
        return chechkright(A,B,n,st,i);
    }
    else return 0;
}
