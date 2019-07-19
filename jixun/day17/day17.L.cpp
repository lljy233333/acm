
#include<stdio.h>

#include<string.h>
#include <iostream>

typedef long long LL;
using namespace std;
const int N=1e5+5;

int a[N],n;

LL c[N],aa[N],bb[N],cc[N],dd[N];

int lowbit(int i)

{

    return i&(-i);

}

void update(int i,int val)

{

    while(i<=N)

    {

        c[i]+=val;

        i+=lowbit(i);

    }

}

int sum(int i)

{

    int ans=0;

    while(i>0)

    {

        ans+=c[i];

        i-=lowbit(i);

    }

    return ans;

}

LL ans;

int main()

{

    int t;

    scanf("%d",&t);

    while(t--)

    {

        ans=0;

        memset(c,0,sizeof(c));

        scanf("%d",&n);

        for(int i=1;i<=n;i++)

        {

            scanf("%d",&a[i]);

            update(a[i],1);

            aa[i]=sum(a[i]-1);//左边小于a[i]的数的个数

            bb[i]=i-1-aa[i];//左边大于a[i]的数的个数

        }

        memset(c,0,sizeof(c));

        for(int i=n;i>=1;i--)

        {

            update(a[i],1);

            cc[i]=sum(a[i]-1);//右边小于a[i]的数的个数

            dd[i]=n-i-cc[i];//右边大于a[i]的数的个数

        }

        for(int i=1;i<=n;i++){
        	cout<<aa[i]<<" "<<dd[i]<<" "<<bb[i]<<" "<<cc[i]<<endl;
        	ans+=aa[i]*dd[i]+bb[i]*cc[i];
		}

            

        printf("%lld\n",ans);

    }

}

