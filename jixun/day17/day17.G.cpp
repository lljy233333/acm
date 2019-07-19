#include <iostream>
#include<cstdio>
#include<algorithm>
#define lowbit(x) x&(-x)
typedef long long ll;
using namespace std;

ll a[200010];
int b[200010];
ll c[200010];
int n,k;

struct s{
  ll num;int id;
}sum[200010];

bool cmp(s x,s y){
  if(x.num==y.num) return x.id<y.id;
  return x.num<y.num;
}

bool cmp2(s x,s y){
  return x.id<y.id;
}

void add(int x,int val){
   for(int i=x;i<=n;i+=lowbit(i)){
       c[i]+=val;
   }
}

ll getsum(int x){
   ll ret=0;
   for(int i=x;i>=1;i-=lowbit(i)){
       ret+=c[i];
   }
   return ret;
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i]-=k,sum[i].num=sum[i-1].num+a[i],sum[i].id=i;
    }
    sort(sum+1,sum+1+n,cmp);
    for(int i=1;i<=n;i++) b[sum[i].id]=i;
    sort(sum+1,sum+1+n,cmp2);
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(sum[i].num>=0) ans++;
        ans+=getsum(b[i]);
        add(b[i],1);
    }
    printf("%lld\n",ans);
    return 0;
}
