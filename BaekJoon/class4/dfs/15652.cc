#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<int>& arr,vector<bool>& visited,int cur,int target,int cnt)
{
    if(target == cnt)
    {
        for(int i=0; i<target; i++) cout << arr[i] << " ";
        cout << "\n";
        return ;
    }
    for(int i=cur; i<=arr.size(); i++)
    {
        arr[cnt] = i;
        dfs(arr,visited,i,target,cnt+1);
    }
}

int main(void)
{
    int N,M;
    cin >> N >> M;
    vector<int> arr(N,0);
    vector<bool> visited(N,false);
    dfs(arr,visited,1,M,0);
}