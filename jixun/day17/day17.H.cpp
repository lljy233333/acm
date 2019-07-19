#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
typedef long long ll;
using namespace std;
int a[100010];
ll c[100010];
ll ls[100010];
ll rs[100010];
ll lb[100010];
ll rb[100010];
int n,k,t;
void add(int x,int val){
   for(int i=x;i<=n;i+=(i&-i)){
       c[i]+=val;
   }
}
ll sum(int x){
   int ret=0;
   for(int i=x;i>0;i-=(i&-i)){
       ret+=c[i];
   }
   return ret;
}
int main()
{
	scanf("%d",&t);
    while(t--){
		scanf("%d",&n);
		memset(c,0,sizeof(c));
    	for(int i=1;i<=n;i++){
        	scanf("%d",&a[i]);
        	add(a[i],1);
        	ls[i]=sum(a[i]-1);
        	lb[i]=i-1-ls[i];
    	}
    	memset(c,0,sizeof(c));
    	for(int i=n;i>=1;i--){
        	add(a[i],1);
        	rs[i]=sum(a[i]-1);
        	rb[i]=n-i-rs[i];
    	}
    	ll ans=0;
    	for(int i=1;i<=n;i++){
    		cout<<ls[i]<<" "<<rb[i]<<" "<<lb[i]<<" "<<rs[i]<<endl;
        	ans+=ls[i]*rb[i]+lb[i]*rs[i];
    	}
		printf("%lld\n",ans);
    }	
    return 0;
}
