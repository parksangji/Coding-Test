#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> v(n,0),dp(n,1);
    for(int i=0; i< n ; i++) cin >> v[i];
    for(int i=0; i< n ; i++) for(int j=0; j<=i ; j++) if(v[j] > v[i] and dp[i]< dp[j]+1) dp[i] = dp[j] + 1;
    cout << *max_element(dp.begin(),dp.end());
}