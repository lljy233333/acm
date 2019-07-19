//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue> 
using namespace std;
int t,n,m;
char a[1000100],b[10005];
int sum;
int NEXT[10005];
void getNEXT() {   
	int i = 0,j=-1;
	NEXT[0] =-1;    
	while (i<m){     
		if (j == -1 || b[i] == b[j]) {         
			i++;j++;            
			NEXT[i] = j;        
		}        
		else {            
			j = NEXT[j];        
		}    
	} 
}
void FirstKmp() {
	int i = 0, j = 0; 
	while (i < n) {         
		if (j == -1 || a[i] == b[j]) {           
			i++, j++; 
			//cout<<i<<" "<<j<<endl;           
			if (j == m) {
				//cout<<i<<" "<<j<<endl;
                //return i - j ;  
				sum++;     
				j=0;     
			}  
		}
		else j = NEXT[j];    
	}    
	//return; 
}

int main(){
	while(scanf("%s",&a)){
		if(a[0]=='#')return 0;
		else{
			sum=0;
			scanf("%s",&b); 
			n=strlen(a);
			m=strlen(b);
			memset(NEXT,0,sizeof(NEXT)); 
			getNEXT();
			FirstKmp();
			printf("%d\n",sum);
			//cout<<sum<<endl;
			//cout<<FirstKmp()<<endl;
		}
	}
	return 0;
}
