#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    answer.push_back(x);
    if(n==1) return answer;
    for(int i =2 ; i <= n ; i++ )
    {
        answer.push_back(x*i);
    }
    return answer;
}