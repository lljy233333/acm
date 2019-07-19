//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue> 
using namespace std;
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
int t,n,m;
char b[100010];
int sum;
int NEXT[100010];
void getNEXT() {   
	int i = 0,j=-1;
	NEXT[0] =-1;    
	while (i<m){     
		if (j == -1 || b[i] == b[j]) {         
			i++;j++;            
			NEXT[i] = j;        
		}        
		else {            
			j = NEXT[j];        
		}    
	} 
}
int main(){
	FAST_IO;
	while(cin>>n){
		
		while(n--){
			cin>>b;
			m=strlen(b);
			memset(NEXT,0,sizeof(NEXT)); 
			getNEXT();
			//cout<<m<<" "<<NEXT[m]<<endl;
			int ll=m-NEXT[m];
			if(ll==m)cout<<m<<endl;
			else if(m%ll==0)cout<<0<<endl;
			else cout<<ll-m%ll<<endl;

		}
	}
	return 0;
}
/*6
abcdab
ababab
aaa
abca
abcde*/
