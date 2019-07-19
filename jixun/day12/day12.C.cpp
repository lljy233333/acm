
//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue> 
using namespace std;
int t,n;
long long temp,sum;
int main(){
	cin>>t;
	while(t--){
		sum=0;
		priority_queue<long long,vector<long long>,greater<long long> > s;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>temp;
			s.push(temp);
		}
		long long a=0,b=0;
		while(true){
			a=s.top();
			s.pop();
			if(s.empty()){
				break;
			}
			b=s.top();
			s.pop();
			sum+=(a+b);
			s.push(a+b);
		}
		cout<<sum<<endl;
		if(t!=0)
		cout<<endl;
	}
	return 0;
}
/*7 4 4
1 1 
2 1
2 3
2 4
3 2
3 4
4 3
4*/
