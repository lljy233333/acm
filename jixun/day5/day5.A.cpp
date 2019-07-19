//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int n,h[6006],l,k,root;
int dp[6006][2],v[6006];
vector<int> employee[6006];
long long maxsum;
void dfs(int x){
	dp[x][0]=0;
	dp[x][1]=h[x];
	for(int i=0;i<employee[x].size();i++){
		int y=employee[x][i];
		dfs(y);
		dp[x][0]+=max(dp[y][0],dp[y][1]);
		dp[x][1]+=dp[y][0];
	}
}
void Root(){
	for(int i=1;i<=n;i++){
		if(v[i]==0)root=i;
	}
}
int main(){
	while(cin>>n){
		for(int i=1;i<=n;i++){
			cin>>h[i];
			employee[i].clear();
		}
/*		for(int i=1;i<=n;i++){
			employee[i]=i;
		}*/
		for(int i=1;i<=n;i++){
			v[i]=0;
		}
	//	memset(v+1,v+n+1,0);
		while(cin>>l>>k){
			if(l==0&&k==0)break;
			employee[k].push_back(l);
			v[l]=1;
		}
		Root();
		dfs(root);
		//cout<<"root"<<root<<endl;
		cout<<max(dp[root][0],dp[root][1])<<endl;
	}
	
		return 0;

}
