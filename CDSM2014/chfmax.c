#include<stdio.h>
#include<string.h>

int main() {
    int t, i, j, sum[27];
    char A[1001], ch;
    scanf("%d",&t);
    while (t--) {
        for (i=0;i<27;i++) sum[i]=0;
        i=0;
        scanf(" %s",A);
        while (A[i]!=0) {
            j=A[i]-'a';
            sum[j]++;
            i++;
        }
        j=0;
        for (i=0;i<26;i++) {
            j=sum[j]>=sum[i]?j:i;
        }
        ch = 'a'+j;
        i=0;
        while (A[i]!=0) {
            if (A[i]==ch) printf("?");
            else printf("%c",A[i]);
            i++;
        }
        printf("\n");
    }
    return 0;
}
