#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int start = 0,end = distance,mid;
    sort(rocks.begin(),rocks.end());
    // 각 지점 사이의 거리의 최솟값이 x가 될 수 있는가??
    // 만족하는 x들 중에 최댓값을 찾는다.
    while(start <= end)
    {
        mid = (start + end) / 2; // 거리의 최솟값 x
        int prev = 0, count = 0; // prev : 이전 바위의 위치, count : 제거한 바위의 개수

        for(int i=0;i < rocks.size(); i++)
        {
            if(rocks[i] - prev < mid) count ++; // 이전 바위와의 거리가 mid보다 작으므로 현재 바위를 제거한다.
            else prev = rocks[i]; //바위를 제거할 필요가 없으므로, 현재 바위가 다음 바위의 prev가 됨
        }
        if(distance - prev < mid) count ++;
        if(count <= n) //count가 n보다 작으면 바위 사의 거리의 최솟값이 mid가 될 수 있다.
        {
            start = mid + 1;
            answer = max(answer,mid);
        }
        else end = mid - 1; //mid 값을 줄여서 최댓값 x를 찾는다.
    }
    return answer;
}

int main()
{
    int a = solution(25,{2, 14, 11, 21, 17},2);
}