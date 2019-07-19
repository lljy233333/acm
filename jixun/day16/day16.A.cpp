
//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue> 
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
using namespace std;
int m,t,n,sum;
int a[25];
int dp[25][25];//i位数j开头 
int llen(int d){//获取长度 
	int num=0;
	while(d){
		num++;
		d/=10;
	}
	return num;
}
int shuweiDP(int d){
 	int ans=0;
 	int len=llen(d);
 	//获取每位数字 
 	memset(a,0,sizeof(a));
 	for(int i=1;i<=len;i++){
 		a[i]=d%10;
 		d/=10;
	 }
	 
	 for(int i=len;i>=1;i--){
		for(int j=0;j<a[i];j++){
			if(!(j==2&&a[i+1]==6)&&j!=4){
				ans+=dp[i][j];
			}
		}
		if(a[i]==4||(a[i]==2&&a[i+1]==6))break;
	 }
	 return ans;
}
int main(){
	FAST_IO;
	//初始化 
		dp[0][0]=1;
		for(int i=1;i<=7;i++){
			for(int j=0;j<10;j++){
				for(int k=0;k<10;k++){
					if(!(j==6&&k==2)&&j!=4)
						dp[i][j]+=dp[i-1][k];
				}
			}
		}
	while(cin>>n>>m){
		if(n==0&&m==0)break;
		
		//计算 
		cout<<shuweiDP(m+1)-shuweiDP(n)<<endl;
	}
	return 0;
}

