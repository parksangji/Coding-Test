#include<string>
#include <iostream>
#include <stack>
using namespace std;
/* 
연습문제
올바른 괄호*/

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    for(int i=0; i<s.length(); i++)
    {
        if(st.empty())
        {
            if(s[i] == ')') return false;
            else{st.push(s[i]);}
        }
        else
        {
            if(s[i] == ')' and st.top() == '(') st.pop();
            else st.push(s[i]);
        }
    }


    return st.empty() ? true : false;
}