#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> scheduler;
    for(int i=0; i<speeds.size();i++)
    {
        int reserved = 100 - progresses[i];
        if(reserved % speeds[i] != 0) reserved += speeds[i];
        scheduler.push(reserved/speeds[i]);
    }
    int process_time = scheduler.front();
    int finished_process = 0;
    while(!scheduler.empty())
    {
        if(process_time < scheduler.front())
        {
            answer.push_back(finished_process);
            finished_process = 0;
            process_time = scheduler.front();
        }
        else
        {
            finished_process++;
            scheduler.pop();
        }
    }
    if(finished_process != 0) answer.push_back(finished_process);
    
    return answer;
}