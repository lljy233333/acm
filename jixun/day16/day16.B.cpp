#include<iostream>
#include<cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue> 
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
using namespace std;
typedef long long ll;//��ll 
ll n,m;//�½硢�Ͻ� 
int a[25];//��ÿһλ���� 
ll dp[25][25][3];//iλ�� j��ǰ׺ 
//k 0��ĩβ����1  1��ĩβ��1  2������13 
ll dfs(ll pos,ll state,ll have,ll lim)
//pos��¼λ�� state��¼ÿ�ε�������ǰ׺ have��¼���༴ǰһλ�Ƿ�Ϊ1 lim��¼����
{
    int num,i,ans,state_x,have_x;
    //numΪ����ֵ ansΪ���� state_xΪÿ������ 
    if(pos<=0)//���λ��<=0�� 
        return state == 0 && have == 2;
    if(!lim && dp[pos][state][have] != -1)//û�����޲����ѱ����ʹ��������ظ�������������ʱ�䣩 
        return dp[pos][state][have];
    num = lim? a[pos]:9;//�������� 
    ans = 0;//���ֵ 
    for(i = 0; i<=num; i++)
    {
        state_x = (state*10+i)%13;//���Ƿ�������13����Ϊ�Ǵ�ԭ���������λ��ʼ��
        have_x = have;
        //ĩ��have���� 
        if(have == 0 && i == 1)//ĩβ����1�����ڼ������1
            have_x = 1;//���Ϊĩβ��1
        if(have == 1 && i != 1)//ĩβ��1�����ڼ���Ĳ���1
            have_x = 0;//���Ϊĩβ����1
        if(have == 1 && i == 3)//ĩβ��1�����ڼ������3
            have_x = 2;//���Ϊ����13
            
        ans+=dfs(pos-1,state_x,have_x,lim&&i==num);
       // cout<<ans<<endl;
        //limit&&i==up��������λ���������λ �� ǰһλû�б��������������ʱ ������ǲ��������Ƶ�  
    }
    if(!lim)
        dp[pos][state][have] = ans;
    return ans;
}
ll solve(ll x)
{
	memset(a,0,sizeof(a));
	memset(dp,-1,sizeof(dp));
	ll len=0;
	while(x)
	{
		a[++len]=x%10;
		x/=10;
	}
	return dfs(len,0,0,1);
}
int main()
{
	FAST_IO;
	while(cin>>n)
	{
		cout<<solve(n)<<endl;
	}
	return 0;
}


