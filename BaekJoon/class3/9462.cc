#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
    int t;
    cin >> t;

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<long long> dp(101);

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for(int i=3; i<=100 ; i++) dp[i] = dp[i-2] + dp[i-3];

    for(int i=0,n; i<t; i++)
    {
        cin >> n;
        cout << dp[n] << '\n';
    }
}