#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int num(const string &s)
{
    int i;
    for(i = 0; i<s.length();i++) if(s[i] >= '0' and s[i] <= '9') break;
    return stoi(s.substr(i));
}
string head(const string &s)
{
    int i;
    for(i=0; i<s.length(); i++) if(s[i] >= '0' and s[i] <= '9') break;
    string sub_s = s.substr(0,i);
    transform(sub_s.begin(),sub_s.end(),sub_s.begin(),::tolower);
    return sub_s;
}

bool compare_num(string s1, string s2) {return num(s1) < num(s2);}
bool compare_head(string s1, string s2) {return head(s1).compare(head(s2))< 0;}

vector<string> solution(vector<string> files) {

    stable_sort(files.begin(),files.end(),compare_num);
    stable_sort(files.begin(),files.end(),compare_head);
    return files;
}
