#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer(query.size(),0);
    map<string,vector<int>> info_;
    string lang,job,level,food,score,temp;

    for(auto v : info)
    {
        vector<vector<string>> vs(4,vector<string>(2,"-"));
        stringstream ss(v);
        ss >> lang >> job >> level >> food >> score;
        vs[0][0] = lang;
        vs[1][0] = job;
        vs[2][0] = level;
        vs[3][0] = food;
        for(int i=0 ; i<2; i++)
        {
            string t1,t2,t3,t4;
            t1 = vs[0][i];
            for(int j=0; j<2; j++)
            {
                t2 = vs[1][j];
                for(int k=0; k<2; k++)
                {
                    t3 = vs[2][k];
                    for(int l =0; l<2; l++)
                    {
                        t4 = vs[3][l];
                        info_[t1 + t2 + t3 + t4].push_back(stoi(score));
                    }
                }
            }
        }
    }
    for(auto itr = info_.begin(); itr != info_.end(); itr++)
    {
        sort(itr->second.begin(),itr->second.end());
    }
    int index = 0;
    for(auto v : query)
    {
        stringstream ss(v);
        ss >> lang >> temp >> job >> temp >> level >> temp >> food >> score;
        string s = lang + job + level + food;
        auto itr = lower_bound(info_[s].begin(),info_[s].end(),stoi(score));
        answer[index++] = info_[s].size() - (itr - info_[s].begin());
    }

    return answer;
}
