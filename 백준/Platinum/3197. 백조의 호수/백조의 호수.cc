#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#include <string>
int R, C;
vector<string> board;
vector<vector<bool>> visited;
pair<int, int> swans[2];

queue<pair<int, int>> swan_q;
queue<pair<int, int>> water_q;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
bool move_swans() {
    queue<pair<int, int>> next_swan_q;
    while (!swan_q.empty()) {
        pair<int, int> curr = swan_q.front();
        swan_q.pop();

        if (curr.first == swans[1].first && curr.second == swans[1].second) {
            return true; 
        }

        for (int i = 0; i < 4; ++i) {
            int nr = curr.first + dr[i];
            int nc = curr.second + dc[i];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc]) {
                continue;
            }
            visited[nr][nc] = true;
            if (board[nr][nc] == 'X') { 
                next_swan_q.push({nr, nc});
            } else { 
                swan_q.push({nr, nc});
            }
        }
    }
    swan_q = next_swan_q;
    return false;
}

void melt_ice() {
    int q_size = water_q.size();
    for (int i = 0; i < q_size; ++i) {
        pair<int, int> curr = water_q.front();
        water_q.pop();

        for (int j = 0; j < 4; ++j) {
            int nr = curr.first + dr[j];
            int nc = curr.second + dc[j];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
                continue;
            }
            if (board[nr][nc] == 'X') {
                board[nr][nc] = '.';
                water_q.push({nr, nc});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;
    board.resize(R);
    visited.assign(R, vector<bool>(C, false));

    int swan_idx = 0;
    for (int i = 0; i < R; ++i) {
        cin >> board[i];
        for (int j = 0; j < C; ++j) {
            if (board[i][j] == 'L') {
                swans[swan_idx++] = {i, j};
                board[i][j] = '.';
            }
            if (board[i][j] == '.') {
                water_q.push({i, j});
            }
        }
    }

    swan_q.push(swans[0]);
    visited[swans[0].first][swans[0].second] = true;

    int days = 0;
    while (true) {
        if (move_swans()) {
            cout << days << "\n";
            break;
        }
        melt_ice();
        days++;
    }

    return 0;
}