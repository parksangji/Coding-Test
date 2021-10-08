#include<iostream>
#include<queue>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    priority_queue<int> pq;
    for(int i=0,flag; i<n ;i++)
    {
        cin >> flag;
        if(!flag)
        {
            if(pq.empty()) cout << "-1\n";
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            } 
        }
        else
            for(int i=0,a; i<flag; i++)
            {
                cin >> a;
                pq.push(a);
            }
    }
}

/*
5
0
2 3 2
0
0
0*/