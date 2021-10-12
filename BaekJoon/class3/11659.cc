#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<long long> dp(n+1);

    for(long long i=0,input,sum=0; i<n; i++)
    {
        cin >> input;
        sum += input;
        dp[i+1] = sum;
    }
    for(int k=0,i,j; k<m; k++)
    {
        cin >> i >> j;
        cout << dp[j] - dp[i-1] << '\n';
    }

}