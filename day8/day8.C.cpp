#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<int>g[250];
vector<int>bed;
vector<int>stu;
int vis[250],match[250];
int k,n,t;
int fflag[60];
int back[60],in[60];
bool dfs(int x){
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		//cout<<x<<" "<<y<<endl;
		if(!vis[y]){
			vis[y]=1;
			if((!match[y]||dfs(match[y]))&&fflag[y]==1){
				match[y]=x;
				//cout<<y<<" "<<x<<endl;
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
		bool flag=true;
		for(int i=1;i<=n;i++){
			g[i].clear();
			match[i]=0;
			vis[i]=0;
			fflag[i]=0;
		}
		bed.clear();
		stu.clear();
		for(int i=1;i<=n;i++){
			cin>>in[i];
			g[i].push_back(i);
		}
		for(int i=1;i<=n;i++){
			cin>>back[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>k;
				if(k==1)g[i].push_back(j);
				//cout<<g[i][j];
			}
		}
		/*for(int i=1;i<=n;i++){
			for(int j=0;j<g[i].size();j++){
				cout<<g[i][j]<<" ";
			}
			cout<<endl;
		}*/
		k=1;
		for(int i=1;i<=n;i++){
			if(in[i]==1){
				bed.push_back(i);
				fflag[i]=1;
			}
			if(in[i]==0||(in[i]==1&&back[i]==0)){
				stu.push_back(i);
			}
			//cout<<bed[i]<<" "<<stu[i]<<endl;
		}
		
		if(bed.size()<stu.size())cout<<"T_T"<<endl;
		else {
			for(int i=0;i<stu.size();i++){
				memset(vis,0,sizeof(vis));
				//cout<<stu[i]<<endl;
				if(!dfs(stu[i]))flag=false;
			}
			if(flag==true)cout<<"^_^"<<endl;
			else cout<<"T_T"<<endl;
		}
		
	}
	return 0;
}
/*4 4 3
4 1
1 2
2 4*/
