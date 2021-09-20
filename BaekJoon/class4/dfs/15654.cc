#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void dfs(vector<int>& arr,vector<int> tmp,vector<bool>& visited,int target,int cnt)
{
    if(target == cnt)
    {
        for(int i=0; i < target ; i++) cout << arr[i] << " ";
        cout << "\n";
        return ;
    }
    for(int i = 0 ; i < arr.size(); i++)
    {
        arr[cnt] = tmp[i];
        if(!visited[i])
        {
            visited[i] = true;
            dfs(arr,tmp,visited,target,cnt+1);
            visited[i] = false;
        }
    }
}

int main(void)
{
    int N,M;
    cin >> N >> M;
    vector<int> tmp(N),arr;
    vector<bool> visited;
    for(int i=0,input; i<N; i++)
    {
        cin >> input;
        arr.push_back(input);
        visited.push_back(false);
    }
    sort(arr.begin(),arr.end());
    dfs(tmp,arr,visited,M,0);
}