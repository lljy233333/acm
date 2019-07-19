#include<iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
int mapp[505][505];//存边 
int du[505];//入度 
bool flag=false;
int main(){
	int n,m;
	int x,y;
	while(cin>>n>>m){
		//重定义变量 
		flag=false;
		memset(mapp,0,sizeof(mapp));
		memset(du,0,sizeof(du));
		for(int i=0;i<m;i++){
			cin>>x>>y;
			if(!mapp[x][y]){
				mapp[x][y]=1;
				du[y]++;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(du[j]==0){
					du[j]--;
					//判断是否为头 
					if(flag==false){
						cout<<j;
						flag=true;
					}
					else cout<<" "<<j;
					for(int k=1;k<=n;k++){
						//减去与j点相连的边，并将该边对应的k的入度减一 
						if(mapp[j][k]==1){
							du[k]--;
						}
					} 
					break;
				}
			}
		}
		cout<<endl;
	}
	return 0;
} 
