#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<int>g[1100];
int vis[1100],match[1100];
int k,m,n,u,v;
int sum,num;
int flag[1100];
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
	while(cin>>m>>n>>k){
		sum=0;
		num=0;
		for(int i=1;i<=n*m;i++){
			g[i].clear();
			match[i]=0;
			vis[i]=0;
		}
		for(int i=1;i<=m*n;i++){
				flag[i]=0;
		}
		for(int i=1;i<=k;i++){
			cin>>u>>v;
			flag[n*(v-1)+u]=2;
		}
		if((n*m-k)%2!=0)cout<<"NO"<<endl;
		else {
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					int f=n*(j-1)+i;
					if((i+j)%2==1&&flag[f]!=2){
						//cout<<f<<" ";
						flag[f]=1;
					}
					else if(flag[f]!=2) num++;
				}
			}
			//cout<<endl;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					int f1=n*(j-1)+i;
					if(flag[f1]==0){
						if((i+1)<=n&&flag[f1+1]!=2){//”“±ﬂ 
							int f2=f1+1;
							g[f1].push_back(f2);
						}
						if((i-1)>0&&flag[f1-1]!=2){//◊Û±ﬂ 
							int f2=f1-1;
							g[f1].push_back(f2);
						}
						if((j-1)>0&&flag[f1-n]!=2){//…œ±ﬂ 
							int f2=f1-n;
							g[f1].push_back(f2);
						}
						if((j+1)<=m&&flag[f1+n]!=2){//œ¬±ﬂ 
							int f2=f1+n;
							g[f1].push_back(f2);
						}
					}
				}
			}
			for(int i=1;i<=n*m;i++){
				memset(vis,0,sizeof(vis));
				//cout<<flag[i]<<" ";
				if(flag[i]!=0)continue;
				//cout<<i<<" "<<dfs[i]<<endl;
				if(dfs(i))sum++;
			}
			//cout<<sum<<" "<<num<<endl;
			if(sum==num)cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
		return 0;

}
/*4 4 3
4 1
1 2
2 4*/
