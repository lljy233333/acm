//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue> 
using namespace std;
char a[20];
int n,t;
int trie[500000][30],tot=1;
int num[500000]={0};
void insert(char* str){
	int len=strlen(str),p=0;
	for(int k=0;k<len;k++){
		int ch=str[k]-'a';
		if(trie[p][ch]==0)trie[p][ch]=++tot;
		p=trie[p][ch];
		num[p]++;
	}
	//end[p]=true;
}
int search(char* str){
	int len=strlen(str),p=0;
	for(int k=0;k<len;k++){
		int ch=str[k]-'a';
		p=trie[p][ch];
		if(p==0)return 0;
	}
	return num[p];
}
int main(){
	for(int i=0;i<=500000;i++){
		memset(trie[i],0,sizeof(trie[i]));
	}
	while(gets(a)){
		if(a[0]==0)break;
		insert(a);
	}
	while(~scanf("%s",a)){
		cout<<search(a)<<endl;
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
