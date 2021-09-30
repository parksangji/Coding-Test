#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
    int n,m;
    cin >> n >> m;

    vector<vector<int>> dist(n+1,vector<int>(n+1,INT32_MAX));
    for(int i=0,a,b,c; i<m; i++)
    {
        cin >> a >> b >> c;
        if(dist[a][b] > c) dist[a][b] = c;
    }
    for(int k=1; k<=n ; k++)
        for(int i=1; i<=n ; i++)
            for(int j=1; j<=n; j++)
                if(dist[i][k] != INT32_MAX and dist[k][j] != INT32_MAX)
                    dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
    for(int i=1; i<=n ; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i==j or dist[i][j] == INT32_MAX) cout << "0 ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}