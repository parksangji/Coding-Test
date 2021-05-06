#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = n;
    int flag_n = 0;

    for(int i=0; i<21; i++) if(n & 0x01 << i)  flag_n++;
    while(1)
    {
        answer++;
        int answer_flag_n = 0;
        for(int i=0; i<21; i++) if(answer & 0x01 << i) answer_flag_n++;
        if(flag_n == answer_flag_n) return answer;

    }
}