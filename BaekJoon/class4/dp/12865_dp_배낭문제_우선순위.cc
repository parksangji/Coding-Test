#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
    int n,totalWeight;
    cin >> n >> totalWeight;

    vector<pair<int,int>> bp(101);
    vector<int> dp(100001);
    for(int i=1; i<=n ;i++)
    {
        int w,v;
        cin >> w >> v;
        bp[i] = {w,v};
    }
    for(int i=1; i<=n; i++)
        for(int j=totalWeight; j>=1; j--) 
            if(bp[i].first <= j) 
                dp[j] = max(dp[j],dp[j-bp[i].first] + bp[i].second);

    cout << dp[totalWeight];
}