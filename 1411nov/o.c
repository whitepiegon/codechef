#include<stdio.h>
#include<string.h>
int c1();
int c3();
int c2();
int chck();
char  A[160], D[160][4000000];
long int sub, sta[160][400000], l[150], pos[160][27][27][27][27];
int org, alen, len[160][400000]={0};

int main() {
    long int d=0, i=0, u, v, w ,x;
    int seq[150]={1}, slen;
    scanf("%ld",&d);
    char f[150]={'0'}, s[150]={'0'}, t[150]={'0'}, fo[150]={'0'};
    while (d--) {
        scanf(" %s",A);
        slen=strlen(A);
        sta[slen][seq[slen]]=l[slen];
        i=0;
        if (A[0] != f[slen] || A[1] != s[slen] || A[2] != t[slen] || A[3] != fo[slen]) {
            if (slen>=4) {
                f[slen]=A[0];s[slen]=A[1];t[slen]=A[2];fo[slen]=A[3];
                u=f[slen]-'a';v=s[slen]-'a';w=t[slen]-'a';x=fo[slen]-'a';
            }
            else if (slen == 3){
                f[slen]=A[0];s[slen]=A[1];t[slen]=A[2];fo[slen]='0';
                u=f[slen]-'a';v=s[slen]-'a';w=t[slen]-'a';x=0;
            }
            else if (slen == 2){
                f[slen]=A[0];s[slen]=A[1];t[slen]='0';fo[slen]='0';
                u=f[slen]-'a';v=s[slen]-'a';w=0;x=0;
            }
            else if (slen == 1){
                f[slen]=A[0];s[slen]='0';t[slen]='0';fo[slen]='0';
                u=f[slen]-'a';v=0;w=0;x=0;
            }
            pos[slen][u][v][w][x] = l[slen];
        }
        while (A[i]!=0) D[slen][l[slen]++] = A[i++];
        D[slen][l[slen]]='0';
        len[slen][seq[slen]]=l[slen]-sta[slen][seq[slen]];
        l[slen]++;
        seq[slen] ++;
    }
int ono = 100;
    while (ono-- && scanf(" %s",A)==1) {
        org = 1;
        sub = -1;
        alen = strlen(A);
        if (A[alen-1]=='.') {
            org=0;A[alen-1]=0;
            alen=alen-1;
        }
        int u = chck();
        if (u==1) printf("%s",A);
        else if (alen == 1 && A[0] >= '0' && A[0] <= '9') printf("%s",A);
        else {
        u=-1;/*
        if (alen>1) {
            u=c1(); // one extra letter in A
            if (u!=-1) {
                while (D[alen-1][u]!='0') printf("%c",D[alen-1][u++]);
                u=1;
            }
        }
        if (u==-1) {
            u=c2(); // one letter skipped in A
            if (u!=-1) {
                while (D[alen+1][u]!='0') printf("%c",D[alen+1][u++]);
                u=1;
            }
        }*//**/
        if (u==-1) {
            u=c3(); // one letter mistyped in A
            if (u!=-1) {
                while (D[alen][u]!='0') printf("%c",D[alen][u++]);
                u=1;
            }
        }
        if (u==-1) printf("%s",A);
        }
        if (org==0) {printf(".");org=1;}
        printf(" ");
    }
    return 0;
}
int c3() {
    long int i, j, cou, po=0,ct;
        if (l[alen]==0) return -1;
    while (1) {
        cou=0;i=0;j=0;ct=1;

        while (i<alen) {
            if (A[i]==D[alen][po+j]) {cou++;}
            else if (ct==1){ct++;}
            else break;
            i++;j++;
        }
        if (cou==alen-1) return po;
        po=po+alen+1;
        if (po>=l[alen]) return -1;
    }
}
int c2() {
    long int i, j, cou, po=0,ct;
    while (1) {
        cou=0;i=0;j=0;ct=1;
        while (i<alen) {
            if (A[i]==D[alen+1][po+j]) {cou++;}
            else if (ct==1){i--;ct++;}
            else break;
            i++;j++;
        }
        if (cou==alen) return po;
        po=po+alen+2;
        if (po>=l[alen+1]) return -1;
    }
}

int c1() {
    long int i, j, cou, po=0, ct;
    while (1) {
        cou=0;i=0;j=0;ct=1;
        while (j<alen-1) {
            if (A[i]==D[alen-1][po+j]) {cou++;}
            else if (ct==1){j--;ct++;}
            else break;
            i++;j++;
        }
        if (cou==alen-1) return po;
        po=po+alen;
        if (po>=l[alen-1]) return -1;
    }
}
int chck() {
    int i, cou, u,v,w,x;
    if (alen>=4) u=A[0]-'a', v=A[1]-'a', w=A[2]-'a', x=A[3]-'a';
    else if (alen==3) u=A[0]-'a', v=A[1]-'a', w=A[2]-'a', x=0;
    else if (alen==2) u=A[0]-'a', v=A[1]-'a', w=0, x=0;
    else if (alen==1) u=A[0]-'a', v=0, w=0, x=0;

    long int po=pos[alen][u][v][w][x];

        while (1) {
            cou=0;
            for (i=0;i<alen;i++) {
                if (A[i]<D[alen][po+i]) return 0;
                else if (A[i]==D[alen][po+i]) {cou++;}
            }
            if (cou==alen) return 1;
            po=po+alen+1;
            if (po>=l[alen]) return 0;
        }

}
