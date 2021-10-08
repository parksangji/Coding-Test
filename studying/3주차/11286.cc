#include<iostream>
#include<queue>

using namespace std;

int main(void)
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0,input; i<n; i++)
    {
        cin >> input;
        if(!input)
        {
            if(pq.empty()) cout << "0\n";
            else
            {
                cout << pq.top().second << '\n';
                pq.pop();
            }
        }
        else pq.push({abs(input),input});
    }
}