#include<iostream>
#include<queue>

using namespace std;

int main(void)
{
    priority_queue<int,vector<int>,greater<int>> q;
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for(int i=0,input; i< n; i++)
    {
        cin >> input;
        if(input == 0)
        {
            if(q.empty()) cout << 0 << '\n';
            else
            {
                cout << q.top() << '\n';
                q.pop();
            }
        }
        else q.push(input);
    }
}