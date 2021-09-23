#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct info {
	int y, x, dir;
};
info tmp;
int arr[14][14], knight, num;
vector<int> chess[14][14];	
vector<info> v[11];
int dx[5] = { 0,1,-1,0,0 };
int dy[5] = { 0,0,0,-1,1 };

void start() {
	int cnt = 1;
	bool finish = false;
	while (1) {
		if (cnt > 1000) {
			cout << -1;
			break;
		}
		for (int i = 1; i <= knight; i++) {
			int cx = v[i][0].x;
			int cy = v[i][0].y;
			int cd = v[i][0].dir;
			vector<int> vv;
			if (chess[cy][cx].size()>0) {				
				bool found = false;				
				for (int j = 0; j < chess[cy][cx].size(); j++) {
					if (!found) {
						if (chess[cy][cx][j] == i) {
							found = true;
							vv.push_back(chess[cy][cx][j]);
						}
					}
					else
						vv.push_back(chess[cy][cx][j]);
				}
			}
			if (vv.size() != chess[cy][cx].size()) continue;
			int nx = cx + dx[cd];
			int ny = cy + dy[cd];
			int val = arr[ny][nx];
			if (val == 2) {
				int nd;
				if (cd == 1)	nd = 2;
				else if (cd == 2) nd = 1;
				else if (cd == 3) nd = 4;
				else if (cd == 4) nd = 3;
				nx = cx + dx[nd];
				ny = cy + dy[nd];
				v[i][0].dir = nd;
				if (arr[ny][nx] == 2)
					continue;
				else
					val = arr[ny][nx];
			}
			for (int k = 0; k < vv.size(); k++) 
				chess[cy][cx].pop_back();
			if (val == 1) 
				reverse(vv.begin(), vv.end());			
			for(int k=0;k<vv.size();k++) {
				int cidx = vv[k];
				chess[ny][nx].push_back(cidx);
				v[cidx][0].x = nx;
				v[cidx][0].y = ny;
			}			
			if (chess[ny][nx].size() > 3) {
				finish = true;
				break;
			}		
		}
		if (finish) break;
		cnt++;
	}
	if (finish) cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> num >> knight;
	for (int i = 0; i < num + 2; i++) 
		for (int j = 0; j < num + 2; j++)
			arr[i][j] = 2;	
	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= num; j++)
			cin >> arr[i][j];
	int x, y, d;
	for (int i = 1; i <= knight; i++) {
		cin >> y >> x >> d;
		tmp.dir = d;
		tmp.x = x;
		tmp.y = y;
		v[i].push_back(tmp);
		chess[y][x].push_back(i);
	}
	start();
	return 0;
}