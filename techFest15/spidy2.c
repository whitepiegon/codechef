#include<stdio.h>
long int mod (long int n);
long int min (long int m, long int n);

int main() {
    long int N[200000], dp[200000];
    long int n, i, mult;
    scanf("%ld",&n);
    for (i=0;i<n;i++) {
        scanf ("%ld",&N[i]);
    }
    dp[0]=0;
    for (i=1;i<n;i++) {
        mult = 1;
        dp[i] = dp[i-1] + mod(N[i] - N[i-1]);
        while (i>=mult) {
            dp [i] = min(dp[i],mod (N[i] - N[i-mult]) + dp[i-mult]);
            mult = mult *2;
        }
    }
    printf ("%ld",dp[n-1]);

    return 0;
}

long int mod (long int n) {
    if (n>=0) return n;
    else return (n*(-1));
}

long int min (long int m, long int n) {
    if (m<n) return m;
    else return n;
}
