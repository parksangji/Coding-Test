#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool solution(string s)
{
    int c_p = count(s.begin(),s.end(),'p') + count(s.begin(),s.end(),'P');
    int c_y = count(s.begin(),s.end(),'y') + count(s.begin(),s.end(),'Y');
    if(c_p==c_y){return true;}
    return false;

}