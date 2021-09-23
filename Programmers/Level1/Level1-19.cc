#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int is_odd = 0;
    
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == ' ')
        {
            answer.push_back(' ');
            is_odd =0;
        }
        else
        {
            is_odd % 2 == 0 ? answer += toupper(s[i]) : answer += tolower(s[i]);
            is_odd++;
        }
    }
    return answer;
}