//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<int >g[505];
int vis[505],match[505];
int k,m,n,u,v;
int sum;
bool dfs(int x){
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if(!vis[y]){
			vis[y]=1;
			if(!match[y]||dfs(match[y])){
				match[y]=x;
				return true;
			}
		}
	}
	return false;
} 
int main(){
	while(cin>>k){
		if(k==0)return 0;
		cin>>n>>m;
		sum=0;
		for(int i=1;i<=max(n,m);i++){
			g[i].clear();
			match[i]=0;
			vis[i]=0;
		}
		for(int i=1;i<=k;i++){
			cin>>u>>v;
			g[u].push_back(v);
			//g[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			if(dfs(i))sum++;
		}
		cout<<sum<<endl;
	}
		return 0;

}
/*7 4 4
1 1 
2 1
2 3
2 4
3 2
3 4
4 3
4*/
