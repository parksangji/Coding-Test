#include<iostream>
#include<cmath>
#include<queue>
 
using namespace std;
 
 
int N, Q;
int firestorm[64][64] = {0, };
 
 
void ROTATE(int l)
{
    if(l==0) return;
 
    int p2 = pow(2, N);
    int rtt = pow(2, l);
 
    int matrix[64][64] = {0, };
 
    for(int r=0;r<p2;r+=rtt){
        for(int c=0;c<p2;c+=rtt){
            for(int y=0;y<rtt;y++){
                for(int x=0;x<rtt;x++){
                    matrix[r+y][c+x] = firestorm[r+(rtt-1-x)][c+y];
                }
            }
        }
    }
    for(int r=0;r<p2;r++){
        for(int c=0;c<p2;c++){
            firestorm[r][c] = matrix[r][c];
        }
    }
}
 
int max_blob()
{
    int group[64][64] = {0, };
    int neighbors[4][2] = { 
        {0, 1}, 
        {1, 0}, 
        {0, -1}, 
        {-1, 0}, 
    };
    int area[5000] = {0, };
 
    int group_id = 1;
    int p2 = pow(2, N);
    for(int r=0;r<p2;r++){
        for(int c=0;c<p2;c++){
            if(firestorm[r][c] == 0){
                continue;
            }
 
            if(group[r][c] == 0){  
                queue<pair<int, int>> q;
                group[r][c] = group_id;
                q.push(pair<int, int>(r, c));
                while(q.empty() == false){
                    area[group_id] += 1;
                    auto cur = q.front(); q.pop();
                    auto cr = cur.first;
                    auto cc = cur.second;
 
                    for(int i=0;i<4;i++){
                        auto nr = cr + neighbors[i][0];
                        auto nc = cc + neighbors[i][1];
                        if(0<=nr and nr < p2 and 0<=nc and nc<p2){
                            if(firestorm[nr][nc] > 0){ 
                                if(group[nr][nc] == 0){ 
                                    group[nr][nc] = group_id;
                                    q.push(pair<int, int>(nr, nc));
                                }
                            }
                        }
                    }
                }
                group_id ++;
            }
        }
    }
 
    int max_area = 0;
    for(int g=1;g<group_id;g++){
        if(max_area < area[g]){
            max_area = area[g];
        }
    }
    return max_area;
}
 
inline bool ICE(int r, int c){
    int p2 = pow(2, N);
    if(0<=r and r< p2 and 0<=c and c<p2){
        if(firestorm[r][c] > 0){
            return true;
        }
    }
    return false;
}
 
void Freeze()
{
    int neighbors[4][2] = { // y, x
        {0, 1}, // 우
        {1, 0}, // 상
        {0, -1}, // 좌
        {-1, 0}, // 하
    };
    int matrix[64][64] = {0, };
 
    int p2 = pow(2, N);
    for(int r=0;r<p2;r++){
        for(int c=0;c<p2;c++){
            if(firestorm[r][c] == 0) continue;
 
            int ice_count = 0;
            for(int i=0;i<4;i++){
                auto nr = r + neighbors[i][0];
                auto nc = c + neighbors[i][1];
                if(ICE(nr, nc)){
                    ice_count++;
                    if(ice_count >= 3){
                        break;
                    }
                }
            }
            if(ice_count <= 2){
                matrix[r][c] += 1;
            }
        }
    }
 
    for(int r=0;r<p2;r++){
        for(int c=0;c<p2;c++){
            firestorm[r][c] -= matrix[r][c];
            firestorm[r][c] = max(0, firestorm[r][c]);
        }
    }
}
 
 
int main()
{
    cin >> N >> Q;
    int p2 = pow(2, N);
    for(int r=0;r<p2;r++)
        for(int c=0;c<p2;c++)
            cin >> firestorm[r][c];
    for(int i=0,l=0;i<Q;i++){
        cin >> l;
        ROTATE(l),Freeze();
    }
 
    int sum_ice = 0;
    for(int r=0;r<p2;r++){
        for(int c=0;c<p2;c++){
            sum_ice += firestorm[r][c];
        }
    }
 
    auto max_area = max_blob();
 
    cout << sum_ice << "\n" << max_area;
}