#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;
int main(void)
{
    string s1,s2;
    cin >> s1 >> s2;
    vector<vector<int>> dp(1001,vector<int>(1001));
    for(int i=1; i<=s1.length() ; i++)
        for(int j=1; j<=s2.length(); j++)
            dp[i][j] = max({dp[i][j-1],dp[i-1][j],dp[i-1][j-1] + (s1[i-1]==s2[j-1])});
    cout << dp[s1.length()][s2.length()];
}