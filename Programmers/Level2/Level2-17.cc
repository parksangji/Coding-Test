#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    
    vector<string> answer;
    vector<string> user_id;
    map<string,string> user_info;
    stringstream ss;
    string op,id,name;
    
    for(int i=0; i<record.size(); i++)
    {
        ss.str(record[i]);
        ss >> op; // 명령어
        if(op == "Enter")
        {
            ss >> id; // id
            ss >> name; // name
            answer.push_back("님이 들어왔습니다.");
            user_id.push_back(id);
            user_info[id] = name;
        }
        else if(op == "Leave")
        {
            ss >> id;
            answer.push_back("님이 나갔습니다.");
            user_id.push_back(id);
        }
        else
        {
            ss >> id;
            ss >> name;
            user_info[id] = name;
        }
        ss.clear();
    }
    for(int i = 0; i < answer.size(); i++)
    {
        answer[i] = user_info[user_id[i]] + answer[i];
    }
    return answer;
}