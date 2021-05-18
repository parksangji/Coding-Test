#include <string>

using namespace std;

int solution(string s) {
    int answer = s.length();
    
    for(int i=1; i<s.length() /2 ; i++)
    {
        int count = 1;
        string temp = s.substr(0,i);
        string same_string_count;
        for(int j=i; j<s.length(); j+=i)
        {
            if(temp == s.substr(j,i)) count++;
            else
            {
                if(count >1 ) same_string_count += to_string(count);
                same_string_count += temp;
                temp = s.substr(j,i);
                count = 1;
            }
        }
        
        if(count > 1) same_string_count += to_string(count);
        same_string_count += temp;
        answer = answer < same_string_count.length() ? answer : same_string_count.length();
    }
    return answer;
}