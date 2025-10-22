#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string expression;
    cin >> expression;

    bool has_minus = false;
	bool its_possible = true;
    for (int i = 1; i < expression.length(); i += 2) {
		if(has_minus && expression[i+1] != '0'){
			its_possible = false;
			break;
		}
        if (expression[i] == '-') {
            has_minus = true;
        }
		
    }

    if (its_possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
	// 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

	return 0;
}