
//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue> 
//#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
using namespace std;
int m,t,n,sum;
string s;
int dp[105][105];
int LIS(){
	memset(dp,0,sizeof(dp));	
 	for (int i = n-2; i>=0; i--){
        for (int j = i+1;j<n; j++){
            if ((s[i]=='('&&s[j]==')')||(s[i]=='['&&s[j]==']')){
                dp[i][j] =dp[i+1][j-1]+1;
            }
			for (int k = i; k < j; k++)
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j]);
        }
    }
    return dp[0][n - 1];
}
int main(){
	//FAST_IO;
	while(cin>>s){
		if(s=="end")break;
		n=s.length();
		cout<<LIS()*2<<endl;
	}
	return 0;
}

