
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
int LIS(){
 	for (int i = 1; i <= n; i++){
    	int maxs = 0;
        for (int j = 1; j <= m; j++){
            dp[i][j]=dp[i - 1][j];  
            if (a[i] == b[j]){
                dp[i][j] = maxs + 1;
            }
			if(a[i]>b[j]&&maxs<dp[i][j]){
                maxs = dp[i][j];
            }
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        sum = max (dp[n][i],sum);
    }
    return sum;
}
int main(){
	FAST_IO;
	while(cin>>t){
		while(t--){
			cin>>n;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			cin>>m;
			for(int i=1;i<=m;i++){
				cin>>b[i];
			}
			memset (dp, 0, sizeof(dp));
			sum=0;
			cout<<LIS()<<endl;	
			if(t)cout<<endl;	
		}
	}
	return 0;
}

