#include<iostream>
#include<stdio.h>
#include<deque>
#include<cstring>

using namespace std;

#define MAX 100001
int find(int N,int K) { 
	int Visited[MAX] = { 0 };
	deque<int> q;
	q.push_back(N);
	Visited[N] = 1;
	while (!q.empty()) {
		int temp = q.front();
		q.pop_front();
		if (temp == K) return Visited[temp] - 1;

		if (temp * 2 < MAX && !Visited[temp * 2]) {
			q.push_front(temp * 2);
			Visited[temp * 2] = Visited[temp];
		}
		if (temp - 1 >= 0 && !Visited[temp - 1]) {
			q.push_back(temp - 1);
			Visited[temp - 1] = Visited[temp] + 1;
		}
		if (temp +1< MAX && !Visited[temp+1]) {
			q.push_back(temp + 1);
			Visited[temp + 1] = Visited[temp] + 1;
		}

	}
	return -1;

}

int main(void) {
	int N, K;

	cin >> N >> K;
	cout << find(N, K) << "\n";
	return 0;
}
/*

*/ 