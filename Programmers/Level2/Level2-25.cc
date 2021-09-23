#include <string>
#include <vector>
#include <algorithm>
#include <map>
/*Summer/Winter Coding(~2018) 스킬트리*/
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char,int> m;
    for(int i=0; i<skill.length(); i++) m.insert(make_pair(skill[i],i+1));
    for(int i=0; i<skill_trees.size(); i++)
    {
        vector<int> v;
        bool flag = true;
        for(int j=0; j<skill_trees[i].length(); j++)
        {   
            if(m[skill_trees[i][j]]) v.push_back(m[skill_trees[i][j]]);
        }
        for(int j=0; j<v.size(); j++)
        {
            if(v[j] == (j+1)) continue;
            else
            {
                flag = false;
                break;
            }
        }
        if(flag== true) answer++;
    }
    return answer;
}