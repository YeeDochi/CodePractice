#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    vector<long long> way(T - 1);
    vector<long long> node(T);

    for (int i = 0; i < T - 1; i++) {
        cin >> way[i];
    }
    for (int i = 0; i < T; i++) {
        cin >> node[i];
    }

    long long weight = node[0];
    long long result = 0;

    for (int i = 0; i < T - 1; i++) {
        result += weight * way[i];
        if (node[i + 1] < weight) {
            weight = node[i + 1];
        }
    }

    cout << result << endl;

    return 0;
}
