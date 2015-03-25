#include<stdio.h>
#include<string.h>

int main () {
    int t, n, s1, s2;
    char cq[100002], p;
    scanf("%d",&t);
    while (t--) {
        scanf(" %s",cq);
        p='+';
        s1=0;s2=0;n=0;
        while (cq[n] != '\0') {
            if (p == '-') p = '+';
            else p = '-';
            if (cq[n] == p) s1++;
            else s2++;
        n++;
        }
        printf("%d\n",s1>s2?s2:s1);
    }
    return 0;
}
