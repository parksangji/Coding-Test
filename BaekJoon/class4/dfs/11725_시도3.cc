#include<iostream>
#include<vector>
using namespace std;

vector<int> matrix[100001];
bool visited[100001];
int answer[100001];
/*전역 변수로 설정안할시에 dfs속도에 영향을 끼친다.*/
void dfs(int cur)
{
    visited[cur] = true;
    for(int i=0; i<matrix[cur].size(); i++)
    {
        if(!visited[matrix[cur][i]])
        {
            answer[matrix[cur][i]] =cur;
            dfs(matrix[cur][i]);
        }
    }
}

int main(void)
{
    int n ;
    cin >> n;
    for(int i=1,a,b; i<=n-1; i++)
    {
        cin >> a >> b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    dfs(1);
    for(int i=2 ; i <= n ; i++) cout << answer[i]<< "\n";
}