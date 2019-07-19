#include<iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
using namespace std;
int T,n,s;//n点数 m边数 s起点 
int m;
vector<int>g[100005];
//int in[100005];
bool flag;
int vis[100005];
int color[100005];
void dfs(int x){
	//cout<<"x: "<<x<<" y: "<<y<<"flag"<<flag<<endl;
	//vis[x]=1;
	for(int i=0;i<g[x].size();i++){
		//if(x==i)continue;
		int y=g[x][i];
		//if(vis[y])continue;
		//cout<<"1x: "<<x<<" y: "<<y<<endl;
		//cout<<"x: "<<x<<" color[y]: "<<y<<"flag"<<flag<<endl;
		if(!color[y]){
			color[y]=3-color[x];
			//cout<<"x: "<<x<<" color[y]: "<<y<<"flag"<<flag<<endl;
			dfs(y);
		}
		else if(color[y]==color[x]){
			flag=false;
			//cout<<"x: "<<x<<" color[y]: "<<y<<"flag"<<flag<<endl;
			break;
		}
		//cout<<"x: "<<x<<" color[y]: "<<y<<"flag"<<flag<<endl;
		//dfs(y);
	}
}
int main(){
	FAST_IO;
	while(cin>>T){
		for(int t=1;t<=T;t++){
			flag=true;
			cin>>n>>m>>s;
			for(int i=0;i<n;i++){
				g[i].clear();
				color[i]=0;
			} 
			int x,y;
//			memset(in,0,n);
//			memset(visit,0,sizeof(visit));
			for(int i=0;i<m;i++){
				cin>>x>>y;
//				in[x]++;
//				in[y]++;
				g[x].push_back(y);
				g[y].push_back(x);
			}
			/*for(int i=1;i<=n;i++){
				if(in[i]==0){
					flag=false;
					break;
				}
			}*/
			color[s]=1;
			//cout<<flag<<endl;
			dfs(s);	
			//cout<<flag<<endl;
			cout<<"Case "<<t<<": ";
			if(flag==true)cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}
	}
	return 0;
} 




















