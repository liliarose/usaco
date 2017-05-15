/*
ID: wzhang11
LANG: C++
TASK: subset 
*/

#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cmath>
#include<iostream>
 
using namespace std;
 
int n;
size_t d[800];
 
int main(){
    freopen("subset.in","r",stdin);
    freopen("subset.out","w",stdout);
 
    scanf("%d",&n);
    int sum=n*(1+n)/2;
     
    if (sum==0 || sum%2==1) printf("0\n");
    else{
        sum>>=1; //sum/=2;
        d[0]=1;
        for (int i=1;i<=n;i++) 
	    for (int j=sum;j>=i;j--)
                d[j]+=d[j-i];
        cout << d[sum]/2 << endl;
/*	for(int i = 0; i < sum; i++){
	    cout << d[i] << " "; 
	}
	cout << endl;
*/    }
    return 0;
}
