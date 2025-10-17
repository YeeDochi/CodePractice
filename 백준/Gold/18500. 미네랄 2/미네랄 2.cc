#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int dir_r[4] = {0,0,1,-1};
int dir_c[4] = {1,-1,0,0};

void show(vector<vector<char>> map,int r,int c){
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cout << map[i][j];
		}
		cout << "\n";
	}
}

void drop(vector<vector<char>> &map, vector<pair<int,int>> coords){
	
	return;
}
void check_grounded(vector<vector<char>>& map, vector<vector<bool>>& visited,int R,int C) {
    queue<pair<int, int>> q;

    for (int j = 0; j < C; j++) {
        if (map[R - 1][j] == 'x' && !visited[R - 1][j]) {
            q.push({R - 1, j});
            visited[R - 1][j] = true;
        }
    }

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = curr.first + dir_r[i];
            int nc = curr.second + dir_c[i];

            if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                if (map[nr][nc] == 'x' && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
}
void gravity(vector<vector<char>>& map_1, vector<pair<int, int>>& cluster,int R){
	if (cluster.empty()) return;

	for(auto p : cluster){
		map_1[p.first][p.second] = '.';
	}
	int min_dist = R;
	for (auto const& p : cluster) {
        int row = p.first;
        int col = p.second;
        int target_r = R - 1; 
        for (int r = row + 1; r < R; r++) {
          
            if (map_1[r][col] == 'x') { 
                target_r = r - 1; 
                break;
            }
        }
        
        int dist = target_r - row;
        min_dist = min(min_dist, dist);
    }
    for (auto p : cluster) {
        map_1[p.first + min_dist][p.second] = 'x';
    }

}
void find_floating_clusters(vector<vector<char>>& map,int R,int C) {
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    check_grounded(map, visited,R,C);
    vector<pair<int, int>> floating_cluster;
    
    for (int i = R - 2; i >= 0; i--) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] == 'x' && !visited[i][j]) {
                floating_cluster.push_back({i, j});
            }
        }
    }

    gravity(map, floating_cluster,R);
}

int main() {
	
	int r,c;
	cin >> r >> c;
	vector<vector<char>> map(r, vector<char>(c));
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cin >> map[i][j];
		}
	}

	int n;
	cin >> n;
	bool broken = false;
	for(int i=0; i<n; i++){
		broken = false;
		int height;
		cin >> height;
		int row = r - height;
		if(i%2==0){
			for(int j=0; j<c; j++){
				if(map[row][j]=='x'){
					map[row][j]='.';
					broken = true;
					break;
				}
			}
		}
		else{
			for(int j=c-1; j>=0; j--){
				if(map[row][j]=='x'){
					map[row][j]='.';
					broken = true;
					break;
				}
			}
		}
		if(broken) find_floating_clusters(map,r,c);
	}
	show(map,r,c);
	return 0;
}