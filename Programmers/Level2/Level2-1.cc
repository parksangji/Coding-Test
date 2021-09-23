#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    string temp[3] = {"4","1","2"};
    while(n>=1)
    {
        answer = temp[n%3] + answer;
        n = (n-1) / 3;
    }
    return answer;
}