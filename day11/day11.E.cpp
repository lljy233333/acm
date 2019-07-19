//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue> 
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
using namespace std;
int n,t,m;
long long tempa;
char temps[40];
int a[100005];
struct node {
    int id;
    struct node *Next[2];
    node() {
        id=0;
        for(int i=0; i<2; i++)
            Next[i]=NULL;
    }
};
void insert(node *p,char s[],int id) {
    int i=0;
    node *q=p;
    //cout<<s<<endl;
    while(i<=32) {
        int tempx=s[i]-'0';
        if(q->Next[tempx]==NULL) {
            q->Next[tempx]=new node;
        }
        q=q->Next[tempx];
        i++;
        //
    }
    
    q->id=id;
}
int serch(node *p,char s[]) {
    int i=0;
    node *q=p;
    while(i<=32) {
        int tempx=1-(s[i]-'0');
        if(q->Next[tempx]==NULL)tempx^=1;
        q=q->Next[tempx];
        i++;
    }
    return q->id;
}
int main(){
	FAST_IO;
	cin>>t;
		for(int k=1;k<=t;k++){
			cout<<"Case #"<<k<<":"<<endl;
			cin>>n>>m;
			node* p=new node;
			for(int i=1;i<=n;i++){//将临时变量转为二进制并存入字典树 
				cin>>tempa;
				a[i]=tempa;
				
				//二进制转化模板！！！！ 
				for(int j=0;j<40;j++){
					temps[j]='0';
				}
				int l=32;
	            while(tempa) {
	                if(tempa&1) {
	                    temps[l]='1';
	                }
	                tempa>>=1;
	                l--;
	            }
	    
	            //cout<<temps<<endl;
	            insert(p,temps,i);
	            
			}
			
			while(m--){
				cin>>tempa;
				for(int j=0;j<40;j++){
					temps[j]='0';
				}
				int l=32;
	            while(tempa) {
	                if(tempa&1) {
	                    temps[l]='1';
	                }
	                tempa>>=1;
	                l--;
	            }
	            //cout<<11111111<<endl;
	            int ans=serch(p,temps);//返回异或值最大的id； 
	            cout<<a[ans]<<endl;
			}
		}			
	return 0;
}                
