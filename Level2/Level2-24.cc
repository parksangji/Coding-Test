#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer;
    transform(s.begin(),s.end(),s.begin(),::tolower);
    bool flag = false;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == ' ') 
        {
            flag = false;
            answer.push_back(s[i]);
        }
        else
        {
            if(flag == false and (s[i] >= 'a' and s[i] <= 'z'))
            {
                answer.push_back(toupper(s[i]));
                flag = true;
            }
            else
            {
                answer.push_back(s[i]);
                flag = true;
            }
        }
    }
    return answer;
}