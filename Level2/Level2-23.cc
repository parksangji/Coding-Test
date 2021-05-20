#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

//2018 KAKAO BLIND RECRUITMENT [1차] 뉴스 클러스터링

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    multiset<string> compare1,compare2;
    transform(str1.begin(),str1.end(),str1.begin(),::toupper);
    transform(str2.begin(),str2.end(),str2.begin(),::toupper);
    for(int i=0; i < str1.length()-1; i++) 
    {
        if((str1[i]>='A' && str1[i]<='Z') && (str1[i+1]>='A' && str1[i+1]<='Z')) compare1.insert(str1.substr(i,2));
    }
    for(int i=0; i < str2.length()-1; i++) 
    {
        if((str2[i]>='A' && str2[i]<='Z') && (str2[i+1]>='A' && str2[i+1]<='Z')) compare2.insert(str2.substr(i,2));
    }

    vector<string> buff1(compare1.size()+compare2.size());

    const auto iter1 = set_union(compare1.begin(),compare1.end(),compare2.begin(),compare2.end(),buff1.begin());

    buff1.erase(iter1,buff1.end());

    vector<string> buff2(compare1.size()+compare2.size());
    const auto iter2 = set_intersection(compare1.begin(),compare1.end(),compare2.begin(),compare2.end(),buff2.begin());

    buff2.erase(iter2,buff2.end());

    const pair<double, double> value = make_pair(buff1.size(),buff2.size());

    if(value.first == 0 and value.second == 0) answer = 65536;
    else  answer = (value.second / value.first) * 65536;

    return answer;
}