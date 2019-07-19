#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
using namespace std;
int n,t;
struct node{
	int u,v,e;
};
vector<node> g;
vector<int> b;
int fa[2000010];
int get(int x){
	if(x==fa[x])return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y){
	fa[get(x)]=get(y);
}
bool flag;
bool cmp(node x,node y){
	return x.e>y.e;
} 
int id(int x){
	return lower_bound(b.begin(),b.end(),x)-b.begin()+1;
}
int main(){
	FAST_IO;
	cin>>t;
		while(t--){
			flag=true;
			cin>>n;
			b.clear();
			g.clear();
			for(int i=1;i<=n;i++){
				int x,y,id;
				cin>>x>>y>>id;
				b.push_back(x);
				b.push_back(y);
				g.push_back({x,y,id});
			}
			sort(b.begin(),b.end());
			b.erase(unique(b.begin(),b.end()),b.end());
			sort(g.begin(),g.end(),cmp);
			for(int i=1;i<=2*n;i++)
				fa[i]=i;
			for(int i=0;i<n;i++){
				if(g[i].e==1){
					merge(id(g[i].u),id(g[i].v));
					//cout<<g[i].e;
				}
				else {
					int fx=get(id(g[i].u));
					int fy=get(id(g[i].v));
					//cout<<g[i].e;
					if(fx==fy){
						flag=false;
						break;
					}
				}
			}
				if(flag==true)cout<<"YES"<<endl;
				else cout<<"NO"<<endl;
		}
	return 0;
}








