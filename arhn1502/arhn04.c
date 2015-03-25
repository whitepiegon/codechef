#include<stdio.h>
#include<string.h>

void subst(int le1, int le2);
void add(int, int, int);
int sub1(int rem, int le1, int le2);
int sub2(int rem, int le1, int le2);
char A[202], B[202], c;
int main () {
    int t, i, le1, le2, k;
    scanf("%d",&t);
    while (t--) {
        i=0;
        scanf("%c",&c);
        scanf("%c",&c);
        while (c != '+' && c != '-') {
            A[i]=c;
            scanf(" %c",&c);
            i++;
        }
        le1=i;

        scanf(" %s",&B);
        le2=strlen(B);
        if (c=='+') add(0,le1-1,le2-1);
        else if(c=='-') subst(le1,le2);
        printf("\n");
    }
    return 0;
}
int sub2(int rem, int le1, int le2) {
    if (le1==-1 && le2==-1) {
        return 1;
    }
    int t1=0, t2=0, i, k;

    if (le1!=-1) {
        t1=B[le1]-'0';
        le1--;
    }
    if (le2!=-1) {
        t2=A[le2]-'0';
        le2--;
    }
    t1=t1+rem;
    rem=0;
    if (t1<t2) {
        t1=t1+10;
        rem=-1;
    }
    k=t1-t2;
    i=sub2(rem,le1,le2);
    if (i!=1 || k!=0) {
        printf("%d",k);
        return 0;
    }
    else return 1;
}
int sub1(int rem, int le1, int le2) {
    if (le1==-1 && le2==-1) {
        return 1;
    }
    int t1=0, t2=0, i, k;

    if (le1!=-1) {
        t1=A[le1]-'0';
        le1--;
    }
    if (le2!=-1) {
        t2=B[le2]-'0';
        le2--;
    }
    t1=t1+rem;
    rem=0;
    if (t1<t2) {
        t1=t1+10;
        rem=-1;
    }
    k=t1-t2;
    i=sub1(rem,le1,le2);
    if (i!=1 || k!=0) {
        printf("%d",k);
        return 0;
    }
    else return 1;
}
void subst(int le1, int le2) {
    int i=0,k=-1;
    if (le1>le2) {
        k=sub1(0,le1-1,le2-1);
        if(k==1) printf("0");
    }
    else if(le2>le1) {
        printf("-");
        k=sub2(0,le2-1,le1-1);
    }
    else {
        while(i<le1 && k==-1) {
            if (A[i]>B[i]) {
                k=sub1(0,le1-1,le2-1);
                if(k==1) printf("0");
            }
            else if (A[i]<B[i]){
                printf("-");
                k=sub2(0,le2-1,le1-1);
            }
            i++;
        }
    }
    if(k==-1) {
                k=sub1(0,le1-1,le2-1);
                if(k==1) printf("0");
            }
}
void add(int rem, int le1, int le2) {
    if (le1==-1 && le2==-1) {
        if (rem!=0) printf("%d",rem);
        return;
    }
    int t1=0, t2=0, i, k;

    if (le1!=-1) {
        t1=A[le1]-'0';
        le1--;
    }
    if (le2!=-1) {
        t2=B[le2]-'0';
        le2--;
    }
    i=t1+t2+rem;
    k=i%10;
    i=i/10;
    add(i,le1,le2);
    printf("%d",k);
}
