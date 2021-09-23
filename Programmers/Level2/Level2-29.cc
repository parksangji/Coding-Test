#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;

    for(vector<string> :: iterator it = cities.begin() ; it != cities.end() ; it++)
    {
        bool flag = false;
        transform(it->begin(),it->end(),it->begin(),::tolower);

        for(vector<string> :: iterator itt = cache.begin(); itt != cache.end(); itt++)
        {
            if(*it == *itt)
            {
                flag = true;
                cache.erase(itt);
                answer += 1;
                cache.push_back(*it);
                break;
            }
        }

        if(!flag)
        {
            answer += 5;
            if(cacheSize != 0 and cache.size() >= cacheSize) cache.erase(cache.begin());
            if(cache.size() < cacheSize) cache.push_back(*it);
        }
    }
    return answer;
}