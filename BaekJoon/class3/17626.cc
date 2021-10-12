#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int answer =10000;

int dfs(vector<int>& dp,int cur)
{
    int& value = dp[cur];
    if(value != -1) return value;
    if(cur <= 1 ) return value = cur;
    value = cur;

    for(int i=0; i*i <= cur ; i++)
        value = min(value,dfs(dp,cur-(i*i)));
    return ++value;
}

int main(void)
{
    int n;
    cin >> n;
    vector<int>dp (n+1,-1);
    cout << dfs(dp,n);
}