#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
    int house;
    cin >> house;
    vector<vector<int>> RGB(house,vector<int>(3,0));
    vector<vector<int>> DP(house,vector<int>(3,0));
    for(int i=0,r,g,b; i<house; i++)
    {
        cin >> r >> g >> b;
        RGB[i] = {r,g,b};
    }
    DP[0][0] = RGB[0][0];
    DP[0][1] = RGB[0][1];
    DP[0][2] = RGB[0][2];
    for(int i=1; i < house ; i++)
    {
        DP[i][0] = RGB[i][0] + min(DP[i-1][1],DP[i-1][2]);
        DP[i][1] = RGB[i][1] + min(DP[i-1][0],DP[i-1][2]);
        DP[i][2] = RGB[i][2] + min(DP[i-1][0],DP[i-1][1]);
    }
    cout << min(DP[house-1][0],min(DP[house-1][1],DP[house-1][2]));
}