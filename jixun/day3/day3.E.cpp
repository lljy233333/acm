#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
long long n,m,k;
int fa[500025],a,b,ans[500025];
struct node{
	int u,v,w;	
}edge[100005];
int get(int x){
	if(x==fa[x])return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y){
	fa[get(x)]=get(y);
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	while(cin>>n>>m){//mµã n±ß 
		long long sum=0;
		int num=m;
		if(n==0)	break;
		for(int i=0;i<m;i++){
			fa[i]=i;
		}
		for(int i=0;i<n;i++) {
			cin>>edge[i].u;
			cin>>edge[i].v;
			cin>>edge[i].w;
		}
		sort(edge,edge+n,cmp);
		for(int i=0;i<n;i++){
			if(get(edge[i].u)!=get(edge[i].v)){
				sum+=edge[i].w;
				merge(edge[i].u,edge[i].v);
				num--;
				//cout<<edge[i].u<<" "<<edge[i].v<<" "<<sum<<endl;
			}
		}
		if(num!=1)cout<<"?"<<endl;
		else
			cout<<sum<<endl;
	}
	return 0;
}
