#include<stdio.h>

int main()
{
    long int t, sum, par, i, num;
    scanf("%ld",&t);
    for (i=0;i<t;i++) {
        num = 5; sum = 0;
        scanf("%ld",&par);
        while ((par/num) != 0) {
            sum = sum + par/num;
            num = num *5;
        }
        printf("%ld\n",sum);
    }
    return 1;
}
