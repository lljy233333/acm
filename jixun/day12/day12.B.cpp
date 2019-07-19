
//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue> 
//#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
using namespace std;
const int N=2000110;
int t,n;
char str1[N];
char str2[N];
char s[N*2];
long long p[N*2];
int len1;
long long maxl;
void Manacher(){
	int i;
	maxl=0;
	s[0]='$';
	s[1]='#';
	int llen=len1;
	for(int i=0;i<llen;i++){
		s[i*2+2]=str1[i];
		s[i*2+3]='#';
	}
	llen=llen*2+2;
	s[llen]='\0';
	int id=0;
	for(int i=0;i<llen;i++){
		p[i]=0;
	}
	//memset(p,0,sizeof(p));
	for(int i=0;i<llen;i++){
		if(p[id]+id>i)p[i]=min(p[2*id-i],p[id]+id-i);
		else p[i]=1;
		while(s[i+p[i]]==s[i-p[i]])	p[i]++;
		if(p[i]+i>p[id]+id)	id=i;
	}
	for(int i=0;i<llen;i++){
		if(s[i]!='$'&&p[i]!=0)	{
			maxl+=p[i]/2;
		}
	}
}
int main(){
	//FAST_IO;
	int t1,t2;
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%s%s",str1,str2);
			//cin>>str1>>str2;
			len1=strlen(str1);
			t1=-1;
			t2=len1;
			for(int i=0;i<len1;i++){
	            if(str1[i]!=str2[i]){
	                t1=i;break;
	            } 
	        }
	        for(int i=len1-1;i>=0;i--){
	            if(str1[i]!=str2[i]){
	                t2=i;break;
	            }
	        }
			if(t1==-1){//如果完全一样 
				
				Manacher();
				printf("%lld\n",maxl);
				//cout<<maxl<<endl;
			}
			else {
				int temp=0;
				for(int i=t1;i<=t2;i++){
					if(str1[i]!=str2[t2-(i-t1)]){
						temp=1;
						break;
					}
				}
				if(temp==1)	printf("%d\n",0);
				else {
					t1--;t2++;long long sum=1;
					while(t1>=0&&t2<len1&&str1[t1]==str2[t2]&&str1[t2]==str2[t1]){
						t1--;t2++;sum++;
					}
					printf("%lld\n",sum);
					//cout<<sum<<endl;
				}
			}
		}
	}
	return 0;
}

