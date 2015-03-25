#include<stdio.h>
#include<string.h>

double prob[28][28][28][28], A[28][28], ans, duct, sum;
char word1[40], word2[40];
int main () {
    int t, n, l, i, j, p, q, x;
    scanf("%d",&t);
while (t--) {
    scanf("%d %d",&n,&l);
    scanf(" %s",word1);
    for (i=1;i<=26;i++) for (j=1;j<=26;j++) {
        scanf("%lf",&sum);
        A[i][j]=sum;
    }
    for (i=0;i<27;i++) {
        for (j=0;j<27;j++) {
            if (i==0 || j==0)
                prob[i][j][0][0]=0;
            else prob[i][j][0][0] = A[i][j];
        }
    }

    for (i=1;i<27;i++) {
        for (j=1;j<27;j++) {
            for (p=1;p<27;p++) {
                prob[i][j][p][0]=prob[i][j][0][0]*A[j][p];
            }
        }
    }

    for (i=1;i<27;i++) {
        for (j=1;j<27;j++) {
            for (p=1;p<27;p++) {
                for (q=1;q<27;q++) {
                    prob[i][j][p][q]=prob[i][j][p][0]*A[p][q];
                }
            }
        }
    }
    ans = 0;
    while (n--) {
        duct=0;
        scanf(" %s",word2);
        p=strlen(word1);
        if (p == strlen(word2)) {
            if (l==1) {
                i=word1[0]-'a'+1;
                j=word2[0]-'a'+1;
                duct+=prob[i][j][0][0];
                if (p>1) {
                    i=word1[1]-'a'+1;
                    j=word2[1]-'a'+1;
                    duct*=prob[i][j][0][0];
                }
                if (p>2) {
                    i=word1[2]-'a'+1;
                    j=word2[2]-'a'+1;
                    duct*=prob[i][j][0][0];
                }
            }
            else if (l==2) {
                i=word1[0]-'a'+1;
                j=word2[0]-'a'+1;
                sum=0;
                for (q=1;q<27;q++) {
                	sum=sum+prob[i][q][j][0];
                }
                duct+=sum;
                if (p>1) {
                    i=word1[1]-'a'+1;
                    j=word2[1]-'a'+1;
                    sum=0;
                    for (q=1;q<27;q++) {
                        sum=sum+prob[i][q][j][0];
            }
                    duct*=sum;
                }
                if (p>2) {
                    i=word1[2]-'a'+1;
                    j=word2[2]-'a'+1;
                    sum=0;
                    for (q=1;q<27;q++) {
                    	sum=sum+prob[i][q][j][0];
                   } duct*=sum;
                }
            }
            else if (l==3) {
                i=word1[0]-'a'+1;
                j=word2[0]-'a'+1;
                sum=0;
                for (q=1;q<27;q++) {
                    for (x=1;x<27;x++)
                    sum=sum+prob[i][q][x][j];
                }
                duct+=sum;
                if (p>1) {
                    i=word1[1]-'a'+1;
                    j=word2[1]-'a'+1;
                    sum=0;
                    for (q=1;q<27;q++) {
                        for (x=1;x<27;x++)
                        sum=sum+prob[i][q][x][j];
                    }
                    duct*=sum;
                }
                if (p>2) {
                    i=word1[2]-'a'+1;
                    j=word2[2]-'a'+1;
                    sum=0;
                    for (q=1;q<27;q++) {
                        for (x=1;x<27;x++)
                        sum=sum+prob[i][q][x][j];
                    }
                    duct*=sum;
                }
            }
        }
    ans+=duct;
    }
    printf("%lf\n",ans);

}
return 0;
}
