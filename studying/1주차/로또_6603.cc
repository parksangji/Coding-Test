#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<int>& answer,vector<int> tmp,int cnt,int idx)
{
    if(6 == cnt)
    {
        for(int i=0; i<6 ; i++) cout << answer[i] << " ";
        cout << "\n";
        return ;
    }
    for(int i=idx; i< tmp.size() ; i++)
    {
        answer[cnt] = tmp[i];
        dfs(answer,tmp,cnt+1,i+1);
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(;;)
    {
        int num;
        cin >> num;
        if(num == 0) break;
        vector<int> tmp1,tmp2(6);
        for(int i=0,input; i< num ; i++)
        {
            cin >> input;
            tmp1.push_back(input);
        }
        dfs(tmp2,tmp1,0,0);
        cout << "\n";
    }
}