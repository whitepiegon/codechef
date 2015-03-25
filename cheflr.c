#include<stdio.h>

int main() {
int t;  char c;
long int ans, row, index;
scanf("%d",&t);
scanf ("%c",&c);
while (t--) {
    ans = 1, row = 0, index = 1;
    while (1) {
        scanf ("%c",&c);
        if (c == 32 || c == 10) {
            break;
        }
        if (c == 108)
            index = 2*(index)-1;
        if (c == 114)
            index = 2*(index);
        row++;
    }
    row ++;
    if (row != 1) {
        if (row%2==0) {
            row = (row/2) -1;
            while (row--) ans = ans*4;
            ans = 2*(ans-1)/3;
            ans = (ans + index) % 1000000007;
            ans = (ans * 2) % 1000000007;
        }
        else if (row%2==1) {
            row = row/2;
            while (row--) ans = ans*4;
            ans = 1*(ans-1)/3;
            ans = (ans + index) % 1000000007;
            ans = (1 + (ans-1)*2) % 1000000007;
        }
    }
}
return 0;
}
