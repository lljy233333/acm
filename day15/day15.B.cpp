#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue> 

#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
using namespace std;
int m,t,n,sum;
int a[150005];
int dp[150005][2];//1Îª+£¬0Îª-£» 
int LIS(){
 	for (int i = 1; i <= n; i++){
        if(dp[i-1][0]+a[i]>dp[i-1][1]){
        	dp[i][1]=dp[i-1][0]+a[i];
        	dp[i][0]=dp[i-1][0];
		}
		else {
			dp[i][1]=dp[i-1][1];
			//cout<<dp[i][1]<<endl;
		}
		dp[i][0]=max(dp[i-1][1]-a[i],dp[i-1][0]);
		//cout<<i<<" "<<dp[i][1]<<" "<<dp[i][0]<<endl;
    }
    
    return dp[n][1];
}
int main(){
	FAST_IO;
	while(cin>>n){
		int maxi=0,mini=0x3f3f3f;
		a[0]=a[n+1]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<LIS()<<endl;
	}
	return 0;
}
