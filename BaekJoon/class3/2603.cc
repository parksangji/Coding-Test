#include<iostream>
#include<vector>

using namespace std;

int blue = 0;
int white = 0;

int devide(vector<vector<int>>& matrix, int x, int y,int n)
{
    if(n == 1)
    {
        if(matrix[x][y] == 1) blue++;
        else white++;
        return matrix[x][y];
    }
    int answer = 0;
    answer += devide(matrix,x,y,n/2);
    answer += devide(matrix,x+ n/2,y,n/2);
    answer += devide(matrix,x,y+ n/2,n/2);
    answer += devide(matrix,x+ n/2,y+ n/2,n/2);


    if(answer == 4)
    {
        blue -= 3;
        return 1;
    }
    if(answer == 0)
    {
        white -= 3;
        return 0;
    }
    return -1000;
}

int main(void)
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n,vector<int>(n,0));
    for(int i=0; i< n; i++) for(int j=0; j<n; j++) cin >> matrix[i][j];
    devide(matrix,0,0,n);
    cout << white << "\n" << blue;
}