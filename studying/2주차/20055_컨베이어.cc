#include<iostream>
#include<deque>

using namespace std;

struct robot
{
    int strong;
    bool is_robot;
};

int main(void)
{
    int n,k;
    cin >> n >> k;

    deque<robot> dq;

    for(int i=1,input; i<= 2*n; i++)
    {
        cin >> input;
        dq.push_back({input,false});
    }
    int answer =0;
    while(1)
    {
        int count =0;
        for(int i=0; i<2*n ; i++)
        {
            if(dq[i].strong == 0) count++;
        }
        if(count >= k) break;
        answer ++;
        dq.push_front(dq.back());
        dq.pop_back();

        if(dq[n-1].is_robot == true) dq[n-1].is_robot = false;

        for(int i= n-2; i>=0; i--)
        {
            if(dq[i].is_robot == true and dq[i+1].strong >= 1 and dq[i+1].is_robot == false)
            {
                dq[i+1].strong--;
                dq[i].is_robot = false;
                if(i == n-2) continue;
                dq[i+1].is_robot = true;
            }
        }

        if(dq[0].strong >= 1 and dq[0].is_robot == false)
        {
            dq[0].is_robot = true;
            dq[0].strong--;
        }
    }

    cout << answer;
}