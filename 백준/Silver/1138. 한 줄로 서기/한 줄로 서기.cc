#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, temp;
    cin >> n;
    vector<int> v(n);
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> temp;
        v[i] = temp;
    }
	
    for (int i = n - 1; i >= 0; i--) {
        if (v[i] == 0) {
            a.insert(a.begin(), i + 1);
        } else {
            a.insert(a.begin() + v[i], i + 1);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}

