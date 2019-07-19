#include<iostream>
#include<cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue> 
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
using namespace std;
typedef long long ll;//简化ll 
ll n,m;//下界、上界 
int a[25];//存每一位数字 
ll dp[25][25][3];//i位数 j总前缀 
//k 0：末尾不是1  1：末尾是1  2：含有13 
ll dfs(ll pos,ll state,ll have,ll lim)
//pos记录位数 state记录每次的数字总前缀 have记录种类即前一位是否为1 lim记录上限
{
    int num,i,ans,state_x,have_x;
    //num为上限值 ans为最后答案 state_x为每次余数 
    if(pos<=0)//如果位数<=0； 
        return state == 0 && have == 2;
    if(!lim && dp[pos][state][have] != -1)//没有上限并且已被访问过（避免重复处理，减少运行时间） 
        return dp[pos][state][have];
    num = lim? a[pos]:9;//计算上限 
    ans = 0;//设初值 
    for(i = 0; i<=num; i++)
    {
        state_x = (state*10+i)%13;//看是否能整除13，因为是从原来数字最高位开始算
        have_x = have;
        //末端have处理 
        if(have == 0 && i == 1)//末尾不是1，现在加入的是1
            have_x = 1;//标记为末尾是1
        if(have == 1 && i != 1)//末尾是1，现在加入的不是1
            have_x = 0;//标记为末尾不是1
        if(have == 1 && i == 3)//末尾是1，现在加入的是3
            have_x = 2;//标记为含有13
            
        ans+=dfs(pos-1,state_x,have_x,lim&&i==num);
       // cout<<ans<<endl;
        //limit&&i==up：如果这个位数不是最高位 且 前一位没有遍历到最大限制数时 这个数是不会有限制的  
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


