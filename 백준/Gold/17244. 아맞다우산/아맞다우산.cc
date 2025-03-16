#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <algorithm>
#include <climits> 
using namespace std;

int n, m;
vector<vector<char>> map;
vector<pair<int, int>> stuffs;
pair<int, int> startP;
pair<int, int> endP;
vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int bfs(pair<int, int> start, pair<int, int> end) { // start->end 최단 거리 반환
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(start.first, start.second, 0));
    visited[start.second][start.first] = true;

    while (!q.empty()) {
        int x, y, dist;
        tie(x, y, dist) = q.front();
        q.pop();
        if (x == end.first && y == end.second) {
            return dist;
        }
        for (const auto& dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[ny][nx] && map[ny][nx] != '#') {
                visited[ny][nx] = true;
                q.push(make_tuple(nx, ny, dist + 1));
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;
    cin.ignore();
    for (int i = 0; i < m; i++) {
        vector<char> c;
        string line;
        getline(cin, line);
        for (int j = 0; j < n; j++) {
            c.push_back(line[j]);
            if (line[j] == 'S') {
                startP = make_pair(j, i);
            }
            if (line[j] == 'X') {
                stuffs.push_back(make_pair(j, i));
            }
            if (line[j] == 'E') {
                endP = make_pair(j, i);
            }
        }
        map.push_back(c);
    }

    int result = INT_MAX;
    int sum;
    int temp;
    sort(stuffs.begin(), stuffs.end());
    do {
        sum = 0;
        pair<int, int> current = startP;
        for (int i = 0; i < stuffs.size(); i++) {
            temp = bfs(current, stuffs[i]);
            if (temp == -1) {
                sum = INT_MAX;
                break;
            }
            sum += temp;
            current = stuffs[i];
        }
        temp = bfs(current, endP);
        if (temp == -1) {
            sum = INT_MAX;
        } else {
            sum += temp;
        }
        result = min(result, sum);
    } while (next_permutation(stuffs.begin(), stuffs.end()));

    cout << result;
    return 0;
}