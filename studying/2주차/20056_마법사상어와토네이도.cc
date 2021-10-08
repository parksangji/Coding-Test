#include<iostream>
#include<vector>

using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

double percentage[5][5] = {
    {0,0,0.02,0,0},
    {0,0.1,0.07,0.01,0},
    {0.05,0.45,0,0,0},
    {0,0.1,0.07,0.01,0},
    {0,0,0.02,0,0}
};

int main(void)
{
    int n;
    cin >> n;

    vector<vector<int>> map(n+1,vector<int>(n+1));

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> map[i][j];
    pair<int,int> start = {(1+n)/2,(1+n)/2};

    
}