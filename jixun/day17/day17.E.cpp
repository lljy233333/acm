
//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue> 
#define ll long long
//#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
using namespace std;
int t,n,x,y,m;
ll a[100005];
string s;
struct node{
	int l,r;
	ll sum,lz,max,min;
	void update(ll v){
		sum+=v*(r-l+1);
		lz+=v;
		max+=v;
		min+=v;
	}
}tree[4*100005];
void pushup(int x){
	tree[x].sum=tree[2*x].sum+tree[2*x+1].sum;
	//tree[x].flag=tree[x*2].flag|tree[x*2+1].flag;
    //tree[x].max=max(tree[2*x].max,tree[2*x+1].max);
    //tree[x].min=min(tree[2*x].min,tree[2*x+1].min);
}
void build(int x,int l,int r){
	tree[x].l=l;
	tree[x].r=r;
	
	if(l==r){
		tree[x].sum=a[l];
		//if(tree[x].sum<=1)tree[x].flag=0;
		return ;
	}
	int mid=(l+r)/2;
	build(2*x,l,mid);
	build(2*x+1,mid+1,r);
	pushup(x);
}
ll querrySUM(int x,int l,int r){
	int L=tree[x].l,R=tree[x].r;
	int mid=(L+R)/2;
	if((l<=L)&&(r>=R)){
		return tree[x].sum;
	}
	ll res=0;
	if(l<=mid)res+=querrySUM(2*x,l,r);
	if(r>mid)res+=querrySUM(2*x+1,l,r);
	//pushup(x);
	return res;
}
void update(int x,int l,int r) {
    int L=tree[x].l,R=tree[x].r;
    int mid=(L+R)/2;
    if(tree[x].sum==R-L+1) return;
    if((l<=L)&&(r>=R)&&(L==R)){
    	tree[x].sum=(ll)sqrt(1.0*tree[x].sum);	 
    	//if(tree[x].sum<=1)tree[x].flag=0;
    	return ;
	}
    if (l<=mid)update(2*x,l,r);
    if (r>mid)update(2*x+1,l,r);
    pushup(x);
}
int main(){
	//≥ı ºªØ 
//	FAST_IO;
	int tt=1;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		build(1,1,n);
			scanf("%d",&m);
			cout<<"Case #"<<tt++<<":"<<endl;
			while(m--){
				scanf("%d%d%d",&t,&x,&y);
				if(x>y){
					int temp=x;
					x=y;
					y=temp;
				}
				if(t==1){
					ll ans=querrySUM(1,x,y);
					printf("%lld\n",ans);
				}
				else {
					update(1,x,y);
				}
			}
			printf("\n");
	}
	return 0;
}

