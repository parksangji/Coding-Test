#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;

    for(int i=1; i<= n/2 ; i++)
    {
        int temp_sum = 0;
        for(int j=i; j<=n; j++)
        {
            if(temp_sum > n) break;
            else if(temp_sum == n)
            {
                answer++;
                break;
            }
            else if(temp_sum < n) temp_sum += j;
        }
    }
    return answer;
}