#include <iostream>
#include <string>

using namespace std;
int solution(int n)
{
    int answer = 0;
    string s1 = to_string(n);
    for(int i=0; i<s1.length(); i++) answer += (int)s1[i] - 48;
    
    return answer;
}