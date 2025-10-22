#include <iostream>
#include <vector>
#include <queue> 
#include <functional> 

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

    priority_queue<int> max_heap; 
    priority_queue<int, vector<int>, greater<int>> min_heap; 

	for(int i=0; i<n; i++){
		int temp;
		cin >> temp;

        if (max_heap.size() == min_heap.size()) {
            max_heap.push(temp);
        } else {
            min_heap.push(temp);
        }

        if (!min_heap.empty() && max_heap.top() > min_heap.top()) {
            int max_val = max_heap.top();
            int min_val = min_heap.top();
            max_heap.pop();
            min_heap.pop();
            max_heap.push(min_val);
            min_heap.push(max_val);
        }

		cout << max_heap.top() << "\n";
	}
	return 0;
}