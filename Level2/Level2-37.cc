#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(),people.end());
    vector<int> v;
    v.push_back(people[people.size()-1]);

    int index = 0, answer = 0;

    while(people.size() > index)
    {
        int hevey_weight = people.back();
        people.pop_back();
        if(hevey_weight + people[index] <= limit)
        {
            answer++;
            index ++;
        }
        else answer++;
    }


    return answer;
}
