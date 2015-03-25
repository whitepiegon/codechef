#include<stdio.h>
#include<string.h>
int main() {
    char ch[5], dh;
    long int q, x, y, c, in, up;
    int inx=1;//black
    scanf("%ld",&q);
    while (q--) {
        scanf(" %s",&ch);

        if (ch[1]=='i') inx=(inx+1)%2;
        else {
            scanf("%ld",&x);
            scanf("%ld",&y);
            c=1; in=1;
            while (x!=y) {
                if (x>y) {
                    if (x%2==0) x/=2;
                    else x=(x-1)/2;
                    c++;
                    in++;
                }
                else {
                    if (y%2==0) y/=2;
                    else y=(y-1)/2;
                    c++;
                }
            }
            if (c%2==0) printf("%ld\n",c/2);
else {
    up=0;
    while (x!=1) {
        if (x%2==0) x/=2;
        else x=(x-1)/2;
        up++;
    }
    if ((ch[1]=='b' && inx==1)||(ch[1]=='r' && inx==0)) {
        if (up%2==0) {
            if (in%2==0) printf("%ld\n",c/2);
            else printf("%ld\n",(c+1)/2);
        }
        else {
            if (in%2==1) printf("%ld\n",c/2);
            else printf("%ld\n",(c+1)/2);
        }
    }
    else  {
        if (up%2==0) {
            if (in%2==1) printf("%ld\n",c/2);
            else printf("%ld\n",(c+1)/2);
        }
        else {
            if (in%2==0) printf("%ld\n",c/2);
            else printf("%ld\n",(c+1)/2);
        }
    }
}
        }
    }
}
