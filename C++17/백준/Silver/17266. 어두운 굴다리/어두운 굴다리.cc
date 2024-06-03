#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int big(int a, int b) {
    return (a > b) ? a : b;
}

int main(void) {
    int T, N, temp;
    vector<int> point;
    int start, end, result;
    vector<int> centers;

    cin >> T >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        point.push_back(temp);
    }

    if (!point.empty()) {
        start = point[0];
        end = T - point[point.size() - 1];
        result = big(start, end);

        if (N > 1) {
            for (int i = 0; i < point.size() - 1; i++) {
                centers.push_back((int)ceil((double)(point[i + 1] - point[i]) / 2));
            }
            sort(centers.begin(), centers.end());
            if (!centers.empty() && centers.back() > result) {
                result = centers.back();
            }
        }
    } else {
        result = T;  
    }

    cout << result << endl;
    return 0;
}
