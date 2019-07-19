//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue> 
using namespace std;
int t,n,k;
long long temp,sum,ans;
long long tempw[100010];
struct node{
	long long val;
	int deep;
	bool operator < (const node &a)const{
		return val==a.val?deep>a.deep:val>a.val;
	}
}; 
priority_queue<node> s;
int main(){
	while(cin>>n>>k){	
		ans=0;
		sum=0;	
		while(!s.empty())s.pop();
		for(int i=0;i<n;i++){
			cin>>tempw[i];	
		}
		sort(tempw,tempw+n);
		for(int i=0;i<n;i++)s.push((node){tempw[i],0});
		while((n-1)%(k-1))s.push((node){0,0}),n++;
		long long a=0,b=0;
		while(s.size()>1){
			int num=1,tempd=0;
			sum=0;
			while(num<=k){
				sum+=s.top().val;
				num++;
				//cout<<sum<<" ";
				tempd=max(tempd,s.top().deep);
				s.pop();
			}
			//cout<<endl<<s.size()<<endl;;
			//cout<<ans<<" ";
			ans+=sum;
			s.push((node){sum,tempd+1});
		}
		cout<<ans<<endl;
		cout<<s.top().deep<<endl;
	}
	return 0;
}
/*6 3 
1 
1 
3 
3 
9 
9 
daan:36 3*/

