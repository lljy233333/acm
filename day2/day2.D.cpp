#include<iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
int mapp[505][505];//��� 
int du[505];//��� 
bool flag=false;
int main(){
	int n,m;
	int x,y;
	while(cin>>n>>m){
		//�ض������ 
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
					//�ж��Ƿ�Ϊͷ 
					if(flag==false){
						cout<<j;
						flag=true;
					}
					else cout<<" "<<j;
					for(int k=1;k<=n;k++){
						//��ȥ��j�������ıߣ������ñ߶�Ӧ��k����ȼ�һ 
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
