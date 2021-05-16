#include <string>
#include <vector>
#include <stack>

using namespace std;

bool test(string s)
{
    stack<char> st;

    for(int i=0; i< s.length(); i++)
    {
        if(st.empty() or s[i] == '[' or s[i] == '{' or s[i] == '(')  st.push(s[i]);
        else if(s[i] == ')' and st.top() == '(') st.pop();
        else if(s[i] == '}' and st.top() == '{') st.pop();
        else if(s[i] == ']' and st.top() == '[') st.pop();
        else break;
    }
    return st.empty() ? true : false;
}

int solution(string s) {
    int answer = 0;
    for(int i=0; i<s.length(); i++)
    {
        if(test(s)) answer++;
        char ch = s.front();
        s.erase(s.begin());
        s.push_back(ch);
    }
    return answer;
}