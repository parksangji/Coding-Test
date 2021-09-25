#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
    int n,cnt = 0;
    cin >> n;
    vector<pair<int,bool>> answer;
    for(int i=1 ; i<= 9 ; i++)
        for(int j=1; j<=9; j++)
            for(int k=1; k<=9; k++)
                if(i != j and j != k and i != k) answer.push_back({i * 100 + j * 10 + k,true});
    for(int i=0; i< n; i++)
    {
        int num,strike,ball;
        cin >> num >> strike >> ball;
        string cmp1 = to_string(num);
        for(int j=0; j< answer.size(); j++)
        {
            int s = 0 , b = 0;
            string cmp2 = to_string(answer[j].first);
            if(cmp1[0] == cmp2[0]) s++;
            if(cmp1[1] == cmp2[1]) s++;
            if(cmp1[2] == cmp2[2]) s++;
            if(cmp1[0] == cmp2[1] or cmp1[0] == cmp2[2]) b++;
            if(cmp1[1] == cmp2[0] or cmp1[1] == cmp2[2]) b++;
            if(cmp1[2] == cmp2[0] or cmp1[2] == cmp2[1]) b++;
            if(strike != s or ball != b) answer[j].second = false;
        }
    }
    for(auto a : answer) if(a.second) cnt++;
    cout << cnt;
}