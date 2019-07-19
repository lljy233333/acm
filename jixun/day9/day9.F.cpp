#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#define N 10010
using namespace std;
int a[1005][1005],d1[1005],d2[1005];
bool v[1005];
int n,m,s;

void dijkstra()
{
	memset(d1,0x3f,sizeof(d1));
	memset(d2,0x3f,sizeof(d2));
	memset(v,0,sizeof(v));
	d1[s]=0;
	for(int i=1;i<=n;i++)
	{
		int x=0;
		for(int j=1;j<=n;j++)
			if(!v[j]&&(x==0||d1[j]<d1[x])) x=j;
		v[x]=1;
		for(int y=1;y<=n;y++)
			d1[y]=min(d1[y],d1[x]+a[x][y]); 
	}
	d2[s]=0;
	memset(v,0,sizeof(v));
	for(int i=1;i<=n;i++)
	{
		int x=0;
		for(int j=1;j<=n;j++)
			if(!v[j]&&(x==0||d2[j]<d2[x])) x=j;
		v[x]=1;
		for(int y=1;y<=n;y++)
			d2[y]=min(d2[y],d2[x]+a[y][x]); 
	}
}
int main()
{
	cin>>n>>m>>s;
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		a[x][y]=min(a[x][y],z);
	}
	dijkstra();
	int sum=0;
	for(int i=1;i<=n;i++){
		//cout<<d2[i]+d1[i]<<" ";
		sum=max(sum,d2[i]+d1[i]);
	}
	//cout<<endl;
	cout<<sum<<endl;
	return 0;
} 
