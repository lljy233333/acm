
//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue> 
using namespace std;
int t,n,ans;
char s[1000010];
int main(){
	cin>>t;
	while(t--){
		cin>>s;
		n=strlen(s);
		//for(int i=1;i<=n;i++)s[n+i]=s[i];
		int i=0,j=1,k=0;
		while(i<n&&j<n&&k<n){
			int t=s[(i+k)%n]-s[(j+k)%n];
			if(s[(i+k)%n]==s[(j+k)%n])k++;
			else{
				if(s[(i+k)%n]>s[(j+k)%n])
					i=i+k+1;
				else {
					j=j+k+1;
				}
				if(i==j)j++;
				k=0;
			}
		}
		//cout<<i<<j<<endl;
		ans=min(i,j);
		cout<<ans+1<<endl;
	}
	return 0;
}
/*7 4 4
1 1 
2 1
2 3
2 4
3 2
3 4
4 3
4*/
