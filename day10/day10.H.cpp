//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue> 
using namespace std;
struct node{
	int u;int v;
	int w;
};
int n,m,s,t,dis[10005],vis[10005];
priority_queue <pair <int,int> > q;
void dijkstra(){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	q.push(make_pair(0,1));
	while(q.size()){
		int x=q.top().second;
		q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=0){
			int y= ,z=;
			if(d[y]>d[x]+z){
				d[y]=d[x]+z;
				q.push(make_pair(-d[y],y));
			}
		}
	}
}
node edge[10005];
int main(){
	cin>>n>>m>>s>>t;//n地点的个数 m道路的条数 s入口
	for(int i=1;i<=m;i++){
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	dijkstra();
	cout<<
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
