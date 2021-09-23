#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s, int n){
   string answer="";
   char alpha =' ';
   for(char c: s) { 
        if ('A' <= c && c <='Z')
            alpha ='A';
        else if('a' <= c && c<='z')
            alpha ='a';
        if ( c != ' ')
            c = (c+n-alpha)%26 + alpha;
        answer.push_back(c); 
    }
    return answer;
}