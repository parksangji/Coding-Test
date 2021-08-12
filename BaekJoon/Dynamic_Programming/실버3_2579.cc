#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<int> v(N),dp(N);
    for(int i=0; i<N; i++) cin >> v[i];

    dp[0] = v[0];
    dp[1] = v[1] + v[0];
    dp[2] = max(v[0]+v[2],v[1]+v[2]);

    for(int i = 3 ; i < N; i++) dp[i] = max(v[i]+dp[i-2],v[i]+v[i-1] + dp[i-3]);
    cout << dp[N-1];
}
/*
6 10 20 15 25 10 20
*/