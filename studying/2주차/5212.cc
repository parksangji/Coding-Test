#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
    int n,m;

    cin >> n >> m;

    vector<vector<char>> matrix(n,vector<char>(m));
    for(int i=0; i< n ; i++)
        for(int j=0; j<m; j++)
            cin >> matrix[i][j];
    
}