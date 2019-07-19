#include <iostream>
#include <cmath>
#include <cstring>
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
using namespace std;
int n,m;
int fa[10005],u[10005],v[10005],ans[100005],num;
int Get(int x){
	if(x==fa[x])return x;
	return fa[x]=Get(fa[x]);
}
void merge(int x,int y){
	fa[Get(x)]=Get(y);
}
int main(){
	FAST_IO;
	while(cin>>n>>m){
		for(int i=0;i<n;i++){
			fa[i]=i;
		}
		memset(ans,n,0);
		num=n;
		for(int i=0;i<m;i++){
			cin>>u[i]>>v[i];
		}
		ans[m-1]=n;
		for(int i=m-1;i>=0;i--){
			if(Get(v[i])!=Get(u[i])){
				num--;
			}
			merge(v[i],u[i]);
/*
			for(int j=0;j<n;j++){
				cout<<Get(j)<<" ";
			}
			cout<<endl;*/
			ans[i-1]=num;	
		}
		for(int i=0;i<m;i++){
			cout<<ans[i];
				cout<<endl;
		}
	}
	return 0;
}
