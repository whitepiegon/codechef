#include<stdio.h>
#include<string.h>
char D[5000000], A[20];
long int sta[400000], pos[27][27][27][27][27][27]={-1}, sub;
int len[400000]={0}, org;
void chck (int u, int v, int w , int x, int l);
int compare(long int d, int l);
int main() {
    long int d, dd, i=0, seq=1, u, v, w ,x;
    int l=0;
    scanf("%ld",&d);
    char f='0', s='0', t='0', fo='0';
    sta[0]=0; len[0]=0;
    while (d--) {
        sta[seq]=l;
        scanf(" %s",A);
        i=0;
        if (A[0] != f || A[1] != s || A[2] != t || A[3] != fo) {
            f=A[0];s=A[1];t=A[2];fo=A[3];
            u=f-'a';v=s-'a';w=t-'a';x=fo-'a';
            pos[u][v][w][x][0][0] = l;
        }
        while (A[i]!=0) D[l++] = A[i++];
        D[l]='0';
        len[seq]=l-sta[seq];
        l++;
        seq ++;
    }
    /*for (i=1;i<8;i++)
    printf("%d %ld\n",len[i],sta[i]);
    printf("%s\n",D);
    printf("%ld %ld %ld",pos[0][0][0][0],pos[0][0][1][0],pos[25][0][0][0]);
    */
    while (scanf("%s",A)!=0) {
        long int list[30]={-1};
        u=A[0]-'a';v=A[1]-'a';w=A[2]-'a';x=A[3]-'a';
        l=strlen(A);
        sub=-1;org=1;
        chck(u,v,w,x,l);
    }
    return 0;
}

void chck (int u, int v, int w , int x, int l) {
    long int d=pos[u][v][w][x][0][0];
    if (org!=1 || sub!=0) prin();
    if (len[d]==l) {
        comparetype1(d,l);
    }
    else if (len[d]-l==1 && sub==-1) comparetype2(d,l);
    else if (len[d]==1-l && sub==-1) comparetype3(d,l);
}
int comparetype1 (long int d, int l) {
    int cou=0,i=0;
    long int dd=d;
    while (D[dd]==A[i] && D[dd]!='0') {
        dd++;i++;
    }
    if (D[dd]=='0') return 0;
    if (D[dd+1]==A[i] && A[i+1]==D[dd] && sub==-1) {
        dd=dd+2, i=i+2;
        while (D[dd]==A[i] && D[dd]!='0') {
            dd++;i++;
        }
        if (D[dd]=='0') sub = d;
    }
    return -1;
}
int comparetype2 (long int d, int l) {
    int cou=0,i=0;
    long int dd=d;
    while (D[dd]==A[i] && A[i]!=0) {
        dd++;i++;
    }
    if (A[i]==0) sub = d;
    else if (D[dd]==A[i+1]&& sub==-1) {
        dd=dd, i=i+1;
        while (D[dd]==A[i] && A[i]!=0) {
            dd++;i++;
        }
        if (A[i]==0) sub = d;
    }
    return -1;
}
int comparetype3 (long int d, int l) {
    int cou=0,i=0;
    long int dd=d;
    while (D[dd]==A[i] && D[dd]!='0') {
        dd++;i++;
    }
    if (D[dd]!='0') sub = d;
    else if (D[dd+1]==A[i]&& sub==-1) {
        dd=dd+1, i=i;
        while (D[dd]==A[i] && D[dd]!='0') {
            dd++;i++;
        }
        if (D[dd]!='0') sub = d;
    }
    return -1;
}
