//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue> 
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
using namespace std;
ll t,sum,mmax,mmin,n,a[200005],x,y,m,ans;
string s;
struct node{
	int l,r;
	ll sum,lz,max,min;
	void update(ll v){
		sum=v;
		lz=0;
		max=v;
		min=v;
	}
}tree[4*200005];
void pushup(int x){
	tree[x].sum=tree[2*x].sum+tree[2*x+1].sum;
    tree[x].max=max(tree[2*x].max,tree[2*x+1].max);
    tree[x].min=min(tree[2*x].min,tree[2*x+1].min);
}
void build(int x,int l,int r){
	tree[x].l=l;
	tree[x].r=r;
	tree[x].sum=tree[x].max=tree[x].min=tree[x].lz=0;
	if(l==r){
		tree[x].sum=tree[x].max=tree[x].min=a[l];
		return ;
	}
	int mid=(l+r)/2;
	build(2*x,l,mid);
	build(2*x+1,mid+1,r);
	pushup(x);
}

void pushdown(int x){
	if(tree[x].lz!=0){
		tree[2*x].update(tree[x].lz);
		tree[2*x+1].update(tree[x].lz);
		tree[x].lz=0;
	}
}
ll querrySUM(int x,int l,int r){
	int L=tree[x].l,R=tree[x].r;
	int mid=(L+R)/2;
	ll res=0;
	if((l<=L)&&(r>=R)){
		return tree[x].sum;
	}
	pushdown(x);
	if(l<=mid)res+=querrySUM(2*x,l,r);
	if(r>mid)res+=querrySUM(2*x+1,l,r);
	pushup(x);
	return res;
}
ll querryMAX(int x,int l,int r){
	int L=tree[x].l,R=tree[x].r;
	int mid=(L+R)/2;
	ll res=0;
	if((l<=L)&&(r>=R)){
		return tree[x].max;
	}
	pushdown(x);
	if(l<=mid)res=max(res,querryMAX(2*x,l,r));
	if(r>mid)res=max(res,querryMAX(2*x+1,l,r));
	pushup(x);
	return res;
}
void update(int x,int l,int r,ll c) {
    int L=tree[x].l,R=tree[x].r;
    int mid=(L+R)/2;
    if((l<=L)&&(r>=R)){
      tree[x].update(c);
      return;
    }
    pushdown(x);
    if (l<=mid)update(2*x,l,r,c);
    if (r>mid)update(2*x+1,l,r,c);
    pushup(x);
}
int main(){

	FAST_IO;
	while(cin>>n>>m){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		build(1,1,n);
		while(m--){
			cin>>s;
			if(s[0]=='Q'){
				cin>>x>>y;
				ans=querryMAX(1,x,y);
				cout<<ans<<endl;
			}
			else {
				cin>>x>>y;
				update(1,x,x,y);
			}
		}
	}
	return 0;
}
