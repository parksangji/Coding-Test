#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int N,H,T;
    cin >> N >> H >> T;
    priority_queue<int> pq;

    for(int i=0,input; i<N; i++) 
    {
        cin >> input;
        pq.push(input);
    }
    int cnt= 0;
    for(cnt; cnt<T; cnt++)
    {
        if(pq.top() >= H and pq.top() != 1) 
        {
            pq.push(pq.top()/2);
            pq.pop();
        }
        else break;
    }

    if(pq.top() < H or pq.empty()) cout << "YES\n" << cnt;
    else cout << "NO\n" << pq.top();
    return 0;
}
