
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
int a[1005],b[1005];
int dp[510][510];
int QuJianDP(){
	memset (dp, 0, sizeof(dp));
	a[0]=0;a[n+1]=0;
	b[0]=0;b[n+1]=0;
 	for (int i = 1; i <= n; i++){
 		for(int j=i;j<=n;j++){
 			dp[i][j]=0x3f3f3f3f;
		 }
 		//sum[i]=b[i-1]+b[i+1]+a[i];//ÉËº¦Öµ 
 	}
 	//cout<<dp[1][n]<<endl;
 	for (int len = 1; len <= n; len++){
        for (int l = 1; l <= n-len+1; l++){
        	int r=l+len-1;
        	for(int k=l;k<=r;k++){
        		dp[l][r]=min(dp[l][r],dp[l][k-1]+a[k]+dp[k+1][r]+b[l-1]+b[r+1]);
				//cout<<dp[l][r]<<endl;
			}
        }
    }
    return dp[1][n];
}
int main(){
	FAST_IO;
	while(cin>>t){
		for(int num=1;num<=t;num++){
			cin>>n;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			for(int i=1;i<=n;i++){
				cin>>b[i];
			}
			
			//sum=0;
			cout<<"Case #"<<num<<": ";
			cout<<LIS()<<endl;	
			//if(t)cout<<endl;	
		}
	}
	return 0;
}

