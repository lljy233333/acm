//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue> 
using namespace std;
char a[5000][31];
char s[31];
int n,t;
int trie[30005][30],tot=1;
int num[30005]={0};
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
void search(char* str){
	int len=strlen(str),p=0;
	for(int k=0;k<len;k++){
		if(num[p]==1)break;
		int ch=str[k]-'a';
		cout<<str[k];
		p=trie[p][ch];
		//if(p==0)return 0;
	}
	//return num[p];
}
int main(){
	int sum=0;
	for(int i=0;i<=30000;i++){
		memset(trie[i],0,sizeof(trie[i]));
	}
	while(gets(a[sum])){
	//while(~scanf("%s",a[sum])){
		if(a[sum][0]==0)break;
		//a[sum]=s;
		//sum++;
		insert(a[sum]);
		sum++;
	}
	for(int i=0;i<sum;i++){
		cout<<a[i]<<" ";
		search(a[i]);
		cout<<endl;
	}
	return 0;
} 
