//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdio>
//#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
using namespace std;
int a[35];
struct node{
	int l,r;
	int sum;
}tree[400110];
void build(int x,int l,int r){
	tree[x].l=l;
	tree[x].r=r;
	tree[x].sum=1;
	if(l==r){
		return ;
	}
	int mid=(l+r)/2;
	build(2*x,l,mid);
	build(2*x+1,mid+1,r);
	//pushup(x);
}
void querryMIX(int x,int l,int r){
	if(tree[x].sum!=-1){
    	a[tree[x].sum]=1;
    	return ;
	}
	int L=tree[x].l,R=tree[x].r;
	int mid=(L+R)/2;
	//pushdown(x);
	if (l>mid){
    	querryMIX(2*x+1,l,r);
	}
	else if(r<=mid){
		querryMIX(2*x,l,r);
	}
	else {
		querryMIX(2*x,l,mid);
		querryMIX(2*x+1,mid+1,r);
	}
	//pushup(x);
}
void update(int x,int l,int r,int c) {
    int L=tree[x].l,R=tree[x].r;
    int mid=(L+R)/2;
    if(l==L&&r==R){
      tree[x].sum=c;
      return;
    }
    if(tree[x].sum==c)return ;
    if(tree[x].sum!=-1){
    	tree[2*x].sum=tree[x].sum;
    	tree[2*x+1].sum=tree[x].sum;
    	tree[x].sum=-1;
	}
    if (l>mid){
    	update(2*x+1,l,r,c);
	}
	else if(r<=mid){
		update(2*x,l,r,c);
	}
	else {
		update(2*x,l,mid,c);
		update(2*x+1,mid+1,r,c);
	}
}
int main(){
	//FAST_IO;
	int t,n,m,sum;
	while(scanf("%d%d%d",&n,&m,&t)!=EOF){
		build(1,1,n);
		while(t--){
			char ch;
			int x,y,z;
			getchar();
			scanf("%c",&ch);
			if(ch=='C'){//Í¿É« 
				scanf("%d%d%d",&x,&y,&z);
				if(x>y){
					int temp=x;
					x=y;
					y=temp;
				}
				update(1,x,y,z);
			}
			else{//Í³¼Æ 
				scanf("%d%d",&x,&y);
				if(x>y){
					int temp=x;
					x=y;
					y=temp;
				}
				memset(a,0,sizeof(a));
				querryMIX(1,x,y);
				sum=0;
				for(int i=1;i<=m;i++){
					if(a[i]==1){
						sum++;
					}
				}
				printf("%d\n",sum);
			}
		}
	}
	return 0;
}
