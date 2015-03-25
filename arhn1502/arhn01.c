#include<stdio.h>

int main() {

    int i1, i2, i3;
    scanf("%d %d %d",&i1,&i2,&i3);
    while (i1 !=0 || i2!=0 || i3!=0) {
        if ((i2-i1)==(i3-i2)) printf("AP %d\n",i2+i3-i1);
        else printf("GP %d\n",(i2*i3)/i1);

        scanf("%d %d %d",&i1,&i2,&i3);
    }
    return 0;
}
