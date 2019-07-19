#include <bits/stdc++.h>
using namespace std;
struct Node{
	int value;
	int prev,next;
}node[100005];
int num=0;
int vis[100005]={0};
int head,tail,tot;
int n,k,m;
void init(){
	tot=2;
	head=1;
	tail=2;
	node[head].next=tail;
	node[tail].prev=head;
} 
void remove(int p){
	node[node[p].prev].next=node[p].next;
	node[node[p].next].prev=node[p].prev;
	vis[p]=1;
}
void clear(){
memset(node,0,sizeof(node));
head=tail=tot=0;
}
int endnum() {
	num=n;
    for(int i=1;i<=n;i++){
    	if(vis[i]==1)num--;
	}
    return num;
}
int main(){
	cin>>n>>k;
	num=n;
		int ans[100005];
		int flag=1;
		int max=0,index_max=-1;
		for(int i=1;i<=n;i++){
			cin>>m;
			node[i].value=m;
			node[i].next=i+1;
			node[i].prev=i-1;
		}
		head=1,tail=n;
		int p=n;
		//cout<<endnum()<<endl;
		while(endnum()>0){
			//寻找有效区域内最大值 
//	cout<<"endnum"<<endnum()<<endl;
			max=0;
			for(int i=head;i<=tail;i++){
				if(node[i].value>max&&vis[i]==0){
					max=node[i].value;
					index_max=i;
				}
			}
	//cout<<"vis:";
	//for(int i=1;i<=n;i++)cout<<vis[i];
	//cout<<endl;
			//删除区域
			int temp=k;
			int ppre=node[index_max].prev;
	//cout<<"index_max:"<<index_max<<endl;
	//cout<<"ppre:"<<ppre<<endl;
			while(temp--&&ppre>0){
				remove(ppre);
				ans[ppre]=flag;
	//for(int i=1;i<=n;i++)cout<<ans[i];
	//cout<<endl;
				ppre=node[ppre].prev;
	//cout<<"ppre:"<<ppre<<endl;
			}
						//cout<<"ok"<<endl;
			temp=k;
			int nnex=node[index_max].next;
			while(temp--&&nnex<=n+1){
				remove(nnex);
				ans[nnex]=flag;
	//cout<<"right:";
	//for(int i=1;i<=n;i++)cout<<ans[i];
	//cout<<endl;
				nnex=node[nnex].next;
			}
			remove(index_max);
			ans[index_max]=flag;
			flag=3-flag;
	//for(int i=1;i<=n;i++)cout<<ans[i];
	//cout<<endl;
		}
		for(int i=1;i<=n;i++)cout<<ans[i];
		cout<<endl;
	return 0;
}














