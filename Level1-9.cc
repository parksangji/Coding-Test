#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int global_value;

bool compare(string s1, string s2) /*비교함수*/
{
    if(s1[global_value] == s2[global_value]) return s1 < s2; /*문자가 같은 경우 사전순으로 정렬.*/
    return (s1[global_value] < s2[global_value]); /*지정 인덱스의 문자 비교*/
}

vector<string> solution(vector<string> strings, int n) {
    global_value = n;
    sort(strings.begin(),strings.end(),compare);
    return strings;
}