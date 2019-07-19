
//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue> 

#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
using namespace std;
const int N=110005;
int t,n,ans;
char str[N]; 
char s[N*2];
int p[N*2];
int len,maxl;
void Manacher(){
	int i;
	maxl=0;
	s[0]='$';
	s[1]='#';
	for(int i=0;i<len;i++){
		s[i*2+2]=str[i];
		s[i*2+3]='#';
	}
	//cout<<i<<endl;
	len=len*2+2;
	//cout<<len<<endl;
	s[len]='\0';
	int id=0;
	memset(p,0,sizeof(p));
	for(int i=0;i<len;i++){
		//cout<<len<<endl;
		if(p[id]+id>i)p[i]=min(p[2*id-i],p[id]+id-i);
		else p[i]=1;
		//cout<<p[i]<<" ";
		while(s[i+p[i]]==s[i-p[i]]){
			p[i]++;
		}
		if(p[i]+i>p[id]+id){
			id=i;
		}
		if(p[i]-1>maxl){
			maxl=p[i]-1;
			//cout<<maxl<<endl;
		}
	}
	
	
}
int main(){
	FAST_IO;
	while(cin>>str){
		len=strlen(str);
		//cout<<len<<endl;
		Manacher();
		cout<<maxl<<endl;
	}
	return 0;
}
