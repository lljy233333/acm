#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<int>g[250];
int vis[250],match[250];
int k,n,t;
int sum,num;
bool dfs(int x){
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if(!vis[y]){
			vis[y]=1;
			if(!match[y]||dfs(match[y])){
				match[y]=x;
				cout<<y<<" "<<x<<endl;
				return true;
			}
		}
	}
	return false;
} 
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			g[i].clear();
			match[i]=0;
			vis[i]=0;
		}
		sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>k;
				if(k==1)g[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			if(dfs(i))sum++;
		}
		if(sum==n)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
/*4 4 3
4 1
1 2
2 4*/
