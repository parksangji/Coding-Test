#include<iostream>
#include<vector>

using namespace std;

int turn(vector<vector<int>>& matrix,int black_white,int count)
{

    while(!test(matrix,black_white))
    {
        
    }

    return count;
}

bool test(vector<vector<int>> matrix,int black_white)
{
    for(int i=0; i<matrix.size(); i++)
        for(int j=0; j<matrix.size(); j++)
            if(matrix[i][j] != black_white) return false;
    return true;
}

int main(void)
{
    int N,black =0,white=0,answer = 0;
    cin >> N;
    vector<vector<int>> matrix(N,vector<int>(N));
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            cin >> matrix[i][j];
            if(matrix[i][j] == 1) white++;
            else black++;
        }
    if(black < white) answer = turn(matrix,0,0);
    else answer = turn(matrix,1,0);
}