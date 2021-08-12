#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
    int day =0 ; cin >> day;
    vector<int> T(day+1),P(day+1),dp(day+1);
    for(int i=0; i< day; i++) cin >> T[i] >> P[i];
    for(int i=0; i< day; i++)
    {
        if(T[i] + i < T.size()) dp[T[i] + i] = max(dp[i] + P[i],  dp[T[i]+i]);
        if(i+1 < T.size()) dp[i+1] = max(dp[i+1],dp[i]);
    }
    cout << *max_element(dp.begin(),dp.end());
}

/*
7
3 10 
5 20
1 10
1 20
2 15
4 40
2 200
T  3  5   1  1  2  4  2
P  10 20 10 20 15 40 200
dp          10 25      20

*/