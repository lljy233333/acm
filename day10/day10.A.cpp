//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue> 
using namespace std;
int t,n,m,sum;
string a,b;
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
				sum++;
				      
			}  
		}
		else j = NEXT[j];    
	}    
	//return -1; 
}

int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		sum=0;
		for(int i=0;i<n;i++){
			scanf("%d", &a[i]);
		}
		for(int i=0;i<m;i++){
			scanf("%d", &b[i]);
		}
		memset(NEXT,0,sizeof(NEXT)); 
		getNEXT();
		 printf("%d\n", FirstKmp());
		//cout<<FirstKmp()<<endl;
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
