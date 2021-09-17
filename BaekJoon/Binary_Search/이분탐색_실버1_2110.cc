#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int home,wifi;
    cin >> home >> wifi;
    vector<int> homes(home);
    for(int i=0; i<home; i++) cin >> homes[i];
    sort(homes.begin(),homes.end());
    int start = 1,end = homes.back(),answer = 0;
    while(start <= end)
    {
        int mid = (start + end) /2;
        int prev = 0, cnt = 1;

        for(int i=1; i<homes.size(); i++)
        {
            if(homes[i] - homes[prev] >= mid)
            {
                prev = i;
                cnt ++;
            }
        }
        if(cnt >= wifi) 
        {
            start = mid + 1;
            answer = mid;
        }
        else end  = mid -1;

    }
    cout << answer;
}