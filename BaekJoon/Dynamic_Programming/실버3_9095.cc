#include<iostream>
#include<vector>

using namespace std;
int T,N;

int main(void)
{
    for(cin >> T; T>0; T--)
    {
        cin >> N;
        vector<int> dp(N); dp[0] = 1; dp[1] = 2; dp[2] = 4;
        for(int i=3; i<N; i++) dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        cout << dp[N-1] << '\n';
    }
}