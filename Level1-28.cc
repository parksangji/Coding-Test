#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long num1 = num;
    while(num1 != 1)
    {
        if(answer >= 500 ) return -1;
        if(num1 & 1) num1 = num1* 3 + 1;
        else num1 /= 2;
        answer++;
    }
    return answer;
}