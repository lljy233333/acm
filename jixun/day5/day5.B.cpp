//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int N=100005;
int n,u,v;
vector<int> g[N];
int vis[N],size[N],sum;
void dfs(int x){
	vis[x]=sum;
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if(vis[y])continue;
		dfs(y);
	}
}
int main(){
	while(cin>>n){
		for(int i=1;i<=n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(n%2==1)cout<<-1<<endl;
		else if(n==2)cout<<0<<endl;
		else {
			for(int i=1;i<=n;i++){
				if(!vis[i]){
					sum++;
					dfs(i);
				}
			}
		}
	}
		return 0;
}

