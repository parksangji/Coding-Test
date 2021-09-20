#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;

    vector<vector<int>> matrix(1025,vector<int>(1025,0));
    vector<vector<int>> dp(1025,vector<int>(1025,0));

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            cin >> matrix[i][j];
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + matrix[i][j]; 
        }
    
    for(int i=0,a,b,c,d; i<m; i++)
    {
        cin >> a >> b >> c >> d;
        cout << dp[c][d] - dp[a-1][d] - dp[c][b-1] + dp[a-1][b-1] << "\n";
    }    
}