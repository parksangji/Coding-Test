#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<double> rate;
    double size = stages.size();
    for(int i=1; i<=N; i++)
    {
        int mycount = count(stages.begin(),stages.end(),i);
        if(mycount ==0) rate.push_back(0);
        else
        {
            rate.push_back(mycount / size);
            size -= mycount;
        }
    }
    for(int i=0; i<N;i++)
    {
        auto it = max_element(rate.begin(),rate.end());
        answer.push_back(it-rate.begin()+1);
        *it = -9999;
    }

    return answer;
}