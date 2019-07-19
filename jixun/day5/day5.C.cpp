//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int N=20050;
int n,u,v,t;
vector<int> g[N];
int vis[N],size[N],mmax,pos,ans;
void dfs(int x){
	vis[x]=1;size[x]=1;
	int mmax=0;
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if(vis[y])continue;
		dfs(y);
		size[x]+=size[y];
		mmax=max(mmax,size[y]);
	}
	mmax=max(mmax,n-size[x]);
	//cout<<x<<" "<<mmax<<endl;
	if(mmax<ans){
		ans=mmax;//重心对应的值 
		pos=x;//中心 
	}
}
int main(){
	while(cin>>t){
		while(t--){
			cin>>n;
			for(int i=1;i<=n;i++){
				g[i].clear();
				vis[i]=0;
				size[i]=0;
			}
			ans=n+1;pos=0;
			for(int i=1;i<n;i++){
				cin>>u>>v;
				g[u].push_back(v);
				g[v].push_back(u);
			}
			dfs(1);
			cout<<pos<<" "<<ans<<endl;
		}
	}	
		return 0;
}
/*1
9
1 2
1 7
1 4
2 8
2 5
4 3
4 6
3 9
1 4*/
