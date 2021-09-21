#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
    int n,answer = 0;
    cin >> n;
    vector<vector<int>> tr(n+1,vector<int>(n+1,0));
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=1; i<=n; i++)
        for(int j=1; j<=i; j++) cin >> tr[i][j];

    dp[1][1] = tr[1][1];
    for(int i=2; i<=n; i++)
        for(int j=1; j<=i; j++) dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + tr[i][j];


    for(int i=1; i<=n; i++) answer = max(dp[n][i],answer);
    cout << answer ;
}