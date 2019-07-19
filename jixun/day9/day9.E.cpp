#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#define N 105
using namespace std;
int aa[N],d[N],a[N][N];
int l[N];
int r[N];
bool v[1005];
int mmap[N][N];
int n,k;
int main()
{
	while(cin>>n>>k){
		memset(a,0x3f,sizeof(a));
		memset(aa,0,sizeof(aa));
		for(int i=2;i<=n-1;i++){
			cin>>aa[i];
		}
		for(int i=1;i<=n;i++){         
		   for(int j=1;j<=n;j++){            
		       if(i==j) mmap[i][j]=0;                
			   else mmap[i][j]=N;//对地图初始化            
			}        
		}
		for(int i=1;i<=n;i++){
			cin>>l[i]>>r[i];
		}
		for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(i==j) continue;
                int k1=abs(l[i]-l[j])+abs(r[i]-r[j]);
                mmap[i][j]=k*k1-aa[j];
        	
			}
		}
		for(k=1; k<=n; k++) {             
			for(int i=1; i<=n; i++) {                
			    for(int j=1; j<=n; j++) {     
				   	if(i==j)                     	
					continue;                        
					if(mmap[i][j]>(mmap[i][k]+mmap[k][j]))        
					      mmap[i][j]=mmap[i][k]+mmap[k][j]; 
				}                
			}            
		}
		cout<<mmap[1][n]<<endl;
	}
	return 0;
} 
