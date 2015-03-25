#include<stdio.h>
#include<string.h>
char A[1000001];
long long C[1000001], H[1000001], E[1000001], F[1000001];
long long CH[1000001], CE[1000001], CF[1000001], HC[1000001], HE[1000001], HF[1000001], EC[1000001], EH[1000001], EF[1000001], FH[1000001], FE[1000001], FC[1000001];
long long getAns(char s, long long i, long long j);
long long getWhC(char s, long long i);
long long getWhH(char s, long long i);
long long getWhE(char s, long long i);
long long getWhF(char s, long long i);
int main() {
    char s1, s2, spa;
    long long nu1, nu2, i, j, t, l, c1=0, c2=0, c3=0, c4=0, mul;
    long long c=0, h=0, e=0, f=0, ch=0, ce=0, cf=0, hc=0, he=0, hf=0, ec=0, eh=0, ef=0, fc=0, fh=0, fe=0;
    scanf(" %s",A);
    l=strlen(A);
    for (i=0;i<l;i++) {
        if (A[i]=='c') {
            c++;
            hc+=h; ec+=e; fc+=f;
            c1++;
        }
        else if (A[i]=='h') {
            h++;
            ch+=c; eh+=e; fh+=f;
            c2++;
        }
        else if (A[i]=='e') {
            e++;
            ce+=c; he+=h; fe+=f;
            c3++;
        }
        else {
            cf+=c; hf+=h; ef+=e;
            f++;
            c4++;
        }
        CH[i]=ch; CE[i]=ce; CF[i]=cf; HC[i]=hc; HE[i]=he; HF[i]=hf; EC[i]=ec; EH[i]=eh; EF[i]=ef; FH[i]=fh; FE[i]=fe; FC[i]=fc;
        C[i]=c1;
        H[i]=c2;
        E[i]=c3;
        F[i]=c4;
    }
    scanf("%ld",&t);
    while (t--) {
        scanf(" %c",&s1);
        scanf(" %c",&s2);
        scanf("%lld %lld",&i,&j);
        i=i-1; j=j-1;

        if (s1 == 'c') {
            nu1 = getWhC(s2,j);
            if (i>0) {
                nu2 = getWhC(s2,i);
                mul = getAns(s2,i,j);
                nu1 = nu1-nu2-C[i-1]*mul;
            }
            printf("%lld\n",nu1);
        }
        else if (s1 == 'h') {
            nu1 = getWhH(s2,j);
            if (i>0) {
                nu2 = getWhH(s2,i);
                mul = getAns(s2,i,j);
                nu1 = nu1-nu2-H[i-1]*mul;
            }
            printf("%lld\n",nu1);
        }
        else if (s1 == 'e') {
            nu1 = getWhE(s2,j);
            if (i>0) {
                nu2 = getWhE(s2,i);
                mul = getAns(s2,i,j);
                nu1 = nu1-nu2-E[i-1]*mul;
            }
            printf("%lld\n",nu1);
        }
        else if (s1 == 'f') {
            nu1 = getWhF(s2,j);
            if (i>0) {
                nu2 = getWhF(s2,i);
                mul = getAns(s2,i,j);
                nu1 = nu1-nu2-F[i-1]*mul;
            }
            printf("%lld\n",nu1);
        }
    }
    return 0;
}
long long getWhC(char s, long long i) {
    if (s=='h') return CH[i];
    else if (s=='e') return CE[i];
    else return CF[i];
}
long long getWhH(char s, long long i) {
    if (s=='c') return HC[i];
    else if (s=='e') return HE[i];
    else return HF[i];
}
long long getWhE(char s, long long i) {
    if (s=='h') return EH[i];
    else if (s=='c') return EC[i];
    else return EF[i];
}
long long getWhF(char s, long long i) {
    if (s=='h') return FH[i];
    else if (s=='e') return FE[i];
    else return FC[i];
}
long long getAns(char s, long long i, long long j) {
    if (s=='c') return (C[j]-C[i]);
    else if (s=='h') return (H[j]-H[i]);
    else if (s=='e') return (E[j]-E[i]);
    else return (F[j]-F[i]);
}
