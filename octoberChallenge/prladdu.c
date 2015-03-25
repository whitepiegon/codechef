#include<stdio.h>
int mod(int n);
int main() {
    long long int t, n, m, d, c, diff, ans, ij, mod1, mod2;
    int vill[100001], ne;
    scanf("%lld",&t);
    while(t--) {
    	m=0, d=0, c=0, ij=0, ans=0;
    	scanf("%lld",&n);
    	scanf("%d",&vill[c]);
    	c++;	n--;
    	while (n--) {
	    	scanf("%d",&vill[c]);
	    	ij++;
	    	if (vill[c] == 0) {
    				while (vill[c]==0) {
    				if (n>0) {
    					n--;	c++;
    					scanf("%d",&vill[c]);
    					ij++;
    				}
    				else {n=-404;break;}
    				}
    			}
    		if (n==-404) {break;}
	    	if (vill[c-ij] == 0) {
    				while (vill[c-ij]==0 && ij != 0) {
    				ij--;
    				}
    			}
    		mod1 = (vill[c]/mod(vill[c]));
    		mod2 = (vill[c-ij]/mod(vill[c-ij]));
	    	if ((mod1*mod2)<0 && ij!=0) {
    			while (vill[c] != 0 && ij > 0) {
    				if (mod(vill[c])>mod(vill[c-ij])) {
    					ans = ans + ij*mod(vill[c-ij]);
    					vill[c] = vill[c]+vill[c-ij];
    					vill[c-ij] = 0;
    					ij--;
    				}
    				else if (mod(vill[c])<mod(vill[c-ij])) {
    					ans = ans + ij*mod(vill[c]);
    					vill[c-ij] = vill[c]+vill[c-ij];
    					vill[c] = 0;
    				}
    				else {
    					ans = ans + ij*mod(vill[c]);
    					vill[c]=0;
    					vill[c-ij]=0;
    				}
    			}
    		}
    		c++;
    	}


    	printf("%lld\n",ans);
    }
    return 0;
}
int mod (int n) {
	return (n>0?n:(-1)*n);
}
