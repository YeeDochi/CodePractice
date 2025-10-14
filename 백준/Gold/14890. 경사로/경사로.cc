#include <iostream>
#include <vector>
#include <cmath> // abs() 함수 사용을 위해 포함

using namespace std;

int n, l;
vector<vector<int>> map;

// 하나의 경로(행 또는 열)가 유효한지 검사하는 함수
bool check_path(const vector<int>& path) {
    vector<bool> ramp_placed(n, false); // 경사로가 설치된 위치를 기록하는 배열

    for (int i = 0; i < n - 1; ++i) {
        int diff = path[i] - path[i + 1];

        // 높이 차이가 1을 초과하면 즉시 실패
        if (abs(diff) > 1) {
            return false;
        }

        // 높이가 같으면 통과
        if (diff == 0) {
            continue;
        }

        // 내리막길 
        if (diff == 1) {
            for (int j = 1; j <= l; ++j) {
                if (i + j >= n || path[i + 1] != path[i + j] || ramp_placed[i + j]) {
                    return false;
                }
            }
            // 경사로 설치 성공-> 위치 기록
            for (int j = 1; j <= l; ++j) {
                ramp_placed[i + j] = true;
            }
        }
        // 오르막길 
        else if (diff == -1) {
            // 이전 L개의 칸을 검사하여 경사로를 놓을 수 있는지 확인
            for (int j = 0; j < l; ++j) {
                if (i - j < 0 || path[i] != path[i - j] || ramp_placed[i - j]) {
                    return false;
                }
            }
            // 경사로 설치 성공-> 위치 기록
            for (int j = 0; j < l; ++j) {
                ramp_placed[i - j] = true;
            }
        }
    }

    return true; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> l;
    map.resize(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> map[i][j];
        }
    }

    int possible_paths = 0;

    // 모든 가로(행) 경로 검사
    for (int i = 0; i < n; ++i) {
        if (check_path(map[i])) {
            possible_paths++;
        }
    }

    // 모든 세로(열) 경로 검사
    for (int j = 0; j < n; ++j) {
        vector<int> col_path; 
        for (int i = 0; i < n; ++i) {
            col_path.push_back(map[i][j]);
        }
        if (check_path(col_path)) {
            possible_paths++;
        }
    }

    cout << possible_paths << "\n";

    return 0;
}