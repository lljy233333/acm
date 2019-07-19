#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int n,m,t,num,num2;
string a,b;
int fa[2000010][20],deep[1000005];
struct node{
	int x,y;
};
struct que{
	string s;
	int index;
};
node g[2000010];
que ss[2000010];
int get(int x){
	if(x==fa[x])return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y){
	fa[get(x)]=get(y);
}
bool cmp(que x,que y){
	return x.s>y.s;
}
void dfs(int u,int f){
	fa[u][0]=f;
	for(unsigned int i=0;i<g[u].size();i++){
		int v=g[u][i].v;
		if(v==f)continue;
		deep[v]=deep[u]+1;
		dfs(v,u);
	}
}
int main(){
	cin>>t;
		while(t--){
			cin>>n>>m;//N¸öÄ¿Â¼
			for(int i=1;i<=n;i++){
				g[i].x=0;
				g[i].y=0;
			}
			for(int i=1;i<n;i++){
				cin>>a>>b;
				ss[++num].s=a;ss[num].index=i;
				ss[++num].s=b;ss[num].index=i;
			}
			sort(ss+1,ss+num,cmp);
			for(int i=1;i<=num;i++){
	            if(ss[i].s!=ss[i-1].s)num2++;
	            if(g[ss[i].index].x==0)g[ss[i].index].x=num2;
            	else g[ss[i].index].y=num2;
	        }
	        for(int i=1;i<=2*n;i++)
				fa[i]=i;
			for()

		}
	
	return 0;
}
