//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue> 
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
using namespace std;
const long long INF=0x3f3f3f3f3f3f3f;
int m,n;
long long f[12][1<<12];//地i行j列的二进制情况 
bool in_s[1<<12];
int main(){
	FAST_IO;
	while(cin>>n>>m){//n行m列 
		if(n==0&&m==0)break;
		
		for(int i=0;i<(1<<m);i++){
			bool cnt = 0,has_odd=0;
			for(int j=0;j<m;j++){
				if(i>>j&1)has_odd|=cnt,cnt=0;// 
				else cnt^=1;
				in_s[i]=has_odd|cnt?0:1;
			}	
		}
		f[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<(1<<m);j++){
				f[i][j]=0;
				for(int k=0;k<(1<<m);k++){
					if((j&k)==0&&in_s[j|k])
						f[i][j]+=f[i-1][k];
				}
			}
		}
		
		cout<<f[n][0]<<endl;
	}
	return 0;
}
