#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
long long n,m,k;
int fa[500025],a,b,ans[500025];
int get(int x){
	if(x==fa[x])return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y){
	fa[get(x)]=get(y);
}
int main(){
	while(cin>>n>>m){
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		memset(ans,n,0);
		for(int i=0;i<m;i++){
			cin>>k;
			if(k==1){
				cin>>a;
				fa[get(a)]=get(a);
				//cout<<"1fa[a]"<<fa[a]<<endl;
			}
			else if(k!=0){
				cin>>a;	
				//cout<<"2fa[a]"<<fa[a]<<endl;
				k--;
				while(k--){
					cin>>b;
					if(get(b)!=get(a))
						merge(b,a);
					//cout<<fa[b]<<endl;
				}
			} 
	//cout<<"ok"<<endl;			
		} 
		for(int i=1;i<=n;i++){
			fa[i]=get(i);
			//cout<<fa[i]<<" ";
		}
		//cout<<endl;
		for(int i=1;i<=n;i++){
			ans[fa[i]]++;
		}
		for(int i=1;i<=n;i++){
			cout<<ans[get(i)];
			if(i!=n)
				cout<<" ";
		}
		cout<<endl;
	}
}
