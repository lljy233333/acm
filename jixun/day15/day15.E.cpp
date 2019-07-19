
//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue> 

#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
using namespace std;
const int INF=0x3f3f3f3f;
int x,n,v;
int dp[1005][1005][2];//i£¬jÎª·¶Î§£¬kÎªÍù×ó»òÍùÓÒ 
int sum[1005];
struct node {
	int place;
	int angry;
	friend bool operator<(node a,node b){
		return a.place<b.place;
	}
};
node people[1005];
int main(){
	FAST_IO;
	while(cin>>n>>v>>x){				
		for(int i=1;i<=n;i++){
			cin>>people[i].place>>people[i].angry;	
		}		
		people[n+1].place=x;people[n+1].angry=0;	
		n++;
		sort(people+1,people+n+1);
		memset(dp,INF,sizeof(dp));
		sum[0]=0;
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+people[i].angry;
			if(people[i].place==x&&people[i].angry==0)dp[i][i][0]=dp[i][i][1]=0;
		}
		for(int l=2;l<=n;l++){
			for(int i=1;i<=n-l+1;i++){
				int j=i+l-1;
				dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][0]+(sum[n]-sum[j]+sum[i])*(people[i+1].place-people[i].place));
				dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][1]+(sum[n]-sum[j]+sum[i])*(people[j].place-people[i].place));
				dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][0]+(sum[n]-sum[j-1]+sum[i-1])*(people[j].place-people[i].place));
				dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][1]+(sum[n]-sum[j-1]+sum[i-1])*(people[j].place-people[j-1].place));
			}
		}
		//cout<<dp[1][n][0]<<endl<<dp[1][n][1]<<endl;
		cout<<min(dp[1][n][0],dp[1][n][1])*v<<endl;
	}
	return 0;
}
