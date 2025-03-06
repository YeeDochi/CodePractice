#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n;
	scanf("%d", &n);
    priority_queue<int, vector<int>, greater<int>> q; // 최소 힙

    for (int i = 0; i < n * n; i++) {
        int temp;
        scanf("%d", &temp);
        if (q.size() < n) {
            q.push(temp);
        } else if (temp > q.top()) {
            q.pop();
            q.push(temp);
        }
    }

    printf("%d\n", q.top());
    return 0;
}

