#include<stdio.h>
main(){long n,t=1;scanf("%ld",&n);while(n>t)t*=2;h(n,t);return 0;}
h(long n,long t){if(n!=0){if(n>=t){h(n-t,t/2);printf("%ld ",t);}else h(n,t/2);}}
