#include <iostream>
#include <string>
#include <stack>


/*2017 팁스타운
짝지어 제거하기
*/

using namespace std;

int solution(string s)
{
    stack<char> st;

    for(int i=0; i<s.length(); i++) 
    {
        if(!st.empty() and st.top() == s[i])  st.pop();
        else st.push(s[i]);
    }
    return st.empty() ? 1 : 0;
}