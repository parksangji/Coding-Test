#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool cmp(pair<int,int> p1, pair<int,int> p2)
{
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}

int main(void)
{
    int r,c,k;
    cin >> r >> c >> k;
    vector<vector<int>> matrix(101,vector<int>(101,0));
    vector<int> number(101,0);
    for(int i=1; i<=3; i++)
        for(int j=1; j<=3; j++)
            cin >> matrix[i][j];
    
    if(matrix[r][c] == k) cout << 0 ;
    else
    {
        int answer =0;
        int row= 3,cal = 3;
        while(1)
        {
            if(matrix[r][c] == k) break;
            if(answer > 100) 
            {
                answer =-1;
                break;
            }
            vector<int> v;
            if(row >= cal)
            {
                for(int i=1; i<= row; i++)
                {
                    vector<pair<int,int>> tmp;
                    number.assign(101,0);
                    for(int j=1; j<=cal; j++) number[matrix[i][j]]++;
                    for(int j=1; j<101; j++) if(number[j] != 0) tmp.push_back({j,number[j]});
                    sort(tmp.begin(),tmp.end(),cmp);
                    for(int j=1; j<= cal; j++) matrix[i][j]= 0;
                    int idx = 1;
                    for(int j=0;j< tmp.size();j++)
                    {
                        matrix[i][idx++] = tmp[j].first;
                        matrix[i][idx++] = tmp[j].second;
                    }
                    idx--;
                    v.push_back(idx);
                }
                sort(v.begin(),v.end());
                cal = v.back();
            }
            else
            {
                for(int i=1 ; i<= cal; i++)
                {
                    vector<pair<int,int>> tmp;
                    number.assign(101,0);
                    for(int j=1; j<=row; j++) number[matrix[j][i]]++;
                    for(int j=1; j<101; j++)
                    {
                        if(number[j] == 0) continue;
                        tmp.push_back({j,number[j]});
                    }
                    sort(tmp.begin(),tmp.end(),cmp);
                    for(int j=1; j<= row; j++) matrix[j][i] = 0;
                    int idx = 1;
                    for(int j=0;j<tmp.size();j++)
                    {
                        matrix[idx++][i] = tmp[j].first;
                        matrix[idx++][i] = tmp[j].second;
                    }
                    idx--;
                    v.push_back(idx);
                }
                sort(v.begin(),v.end());
                row = v.back();
            }
            answer++;
        }
        cout << answer;
    }
}