#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;;

int main() {


	vector<vector<int>> v;
	vector<int> v1;
	int T,grade;
	cin >> T;
	int n, k, t, m;
	// 팀 수, 문제 수, 내팀, 반복회수
	int a, b, c;
	while (T--) {
		grade = 0;
		v.erase(v.begin(), v.end());
		v1.erase(v1.begin(), v1.end());
		cin >> n >> k >> t >> m;
		for (int j = 0; j < k + 3; j++)
			v1.push_back(0);

		for (int i = 0; i < n; i++) {
			v1[0]++;
			v.push_back(v1);
		}


		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			if (v[a - 1][b] < c) v[a - 1][b] = c;
			v[a - 1][k + 1]--;
			v[a - 1][k + 2] = -i;
		}

		for (int i = 0; i < n; i++) {
			int temp = 0;
			for (int j = 1; j <= k; j++) {
				temp += v[i][j];
			}
			v[i].insert(v[i].begin(), temp);
		}
		for (int i = 0; i < n; i++) {
			v[i].erase(v[i].begin() + 2, v[i].end() - 2);
		}
		for (int i = 0; i < n; i++) {
			int val = v[i][1];
			v[i].erase(v[i].begin() + 1);
			v[i].push_back(val);
		}

		sort(v.begin(), v.end());

		for (int i = 0; i < n; i++) {
			if (v[i][3] == t)break;
			grade++;
		}

		cout << n-grade << "\n";
	}
}