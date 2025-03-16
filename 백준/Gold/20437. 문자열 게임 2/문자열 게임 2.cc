#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string tempS;
        int tempI;
        cin >> tempS >> tempI;

        unordered_map<char, vector<int>> charPositions;
        for (int i = 0; i < tempS.size(); ++i) {
            charPositions[tempS[i]].push_back(i);
        }

        int Min = INT_MAX, Max = 0;
        bool flag = false;

        for (const auto& entry : charPositions) {
            const vector<int>& positions = entry.second;
            if (positions.size() < tempI) continue;

            for (int i = 0; i <= positions.size() - tempI; ++i) {
                int length = positions[i + tempI - 1] - positions[i] + 1;
                Min = min(Min, length);
                Max = max(Max, length);
                flag = true;
            }
        }

        if (!flag) cout << -1 << "\n";
        else cout << Min << " " << Max << "\n";
    }

    return 0;
}

