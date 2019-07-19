//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n,u,v;
vector<int> g[100005];
int vis[100005];
int deep[100005];
void dfs(int x){
	vis[x]=1;
	for(int i=0;i<g[x].size();i++){
		//if(x==i)continue;
		int y=g[x][i];
		//cout<<"1x: "<<x<<" y: "<<y<<endl;
		if(vis[y])continue;
		deep[y]=deep[x]+1;
		//cout<<"2x: "<<x<<" y: "<<y<<endl;
		dfs(y);
	}
}
int main(){
		cin>>n;
		long long sum1=0,sum2=0;
		memset(vis,n,0);
		memset(deep,n,0);
		for(int i=1;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		/*for(int k=1;k<=n;k++){
			for(int j=0;j<g[k].size();j++){
				cout<<k<<" "<<j<<" "<<g[k][j]<<endl;
			}
		}*/
		}
		dfs(1);
		for(int i=1;i<=n;i++){
			if(deep[i]%2==0){
				sum2++;
			}
			else sum1++;
		}
		//cout<<"sum1:"<<sum1<<" sum2:"<<sum2<<endl;
		cout<<sum1*sum2-(n-1)<<endl;
		return 0;

}
