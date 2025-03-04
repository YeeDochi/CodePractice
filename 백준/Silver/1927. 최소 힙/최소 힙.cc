#include <iostream>
#include <queue>	
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	priority_queue<int,vector<int>, greater<int>> pq;
	for(int i=0;i<n;i++) {
		int temp;
		scanf("%d", &temp);
		if(temp != 0) {
			pq.push(temp);
		}
		else {
			if(pq.empty()) {
				printf("0\n");
			}
			else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
	}
	return 0;
}