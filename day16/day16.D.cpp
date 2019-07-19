
//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue> 
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
using namespace std;
int m,t,n,sum;
long long a[510],b[510];
int dp[510][510];
int main(){
	FAST_IO;
	while(cin>>t){
		while(t--){
			cin>>n>>m;//n个城市 m条线 
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			for(int i=1;i<=m;i++){
				cin>>b[i];
			}	
		}
	}
	return 0;
}

