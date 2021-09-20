#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
    int T;
    cin >> T;
    for(int i=0,n; i<T; i++)
    {
        cin >> n;
        vector<vector<int>> sticker(2,vector<int>(n,0));
        vector<vector<int>> dp(2,vector<int>(n,0));
        for(int i=0; i< sticker.size(); i++)
            for(int j=0; j<sticker[i].size();j++) cin >> sticker[i][j];

        dp[0][0] = sticker[0][0];
        dp[1][0] = sticker[1][0];
        dp[0][1] = sticker[1][0] + sticker[0][1];
        dp[1][1] = sticker[0][0] + sticker[1][1];

        for(int i=2; i<n; i++)
        {
            dp[0][i] = sticker[0][i] + max(dp[1][i-1],dp[1][i-2]);
            dp[1][i] = sticker[1][i] + max(dp[0][i-1],dp[0][i-2]);
        }
        cout << max(dp[0][n-1],dp[1][n-1]) << '\n';
    }
}