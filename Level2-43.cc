#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dy[4]={0,-1,0,1};
int dx[4]={-1,0,1,0};

int area(vector<vector<int>> picture,vector<vector<bool>> visited,int M,int N,int x,int y,int number)
{
    visited[y][x] = true;
    int ret = 1;
    
    for(int i=0; i<4; i++)
    {
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny<0 || nx<0 || ny>=M || nx>=N || visited[ny][nx]) continue;
        if(picture[ny][nx]!=number) continue;
        ret += area(picture,visited,M,N,ny,nx,number);
    }
    
    return ret;
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<vector<bool>> visited(100,vector<bool>(100,false));
    
    for(int i = 0; i< m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(!visited[i][j] and !picture[i][j])
            {
                number_of_area ++;
                max_size_of_one_area = max(max_size_of_one_area,area(picture,visited,m,n,i,j,picture[i][j]));
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
