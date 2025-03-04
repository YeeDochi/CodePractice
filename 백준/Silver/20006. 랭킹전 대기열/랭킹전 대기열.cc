#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<vector<pair<int, string>>> v;
    vector<int> LV;

    for (int i = 0; i < n; i++) {
        int level;
        char name[16];
		cin >> level >> name;
        bool added = false;
        for (int j = 0; j < v.size(); j++) {
            if (level <= LV[j] + 10 && level >= LV[j] - 10 && v[j].size()<m) {
                v[j].push_back(make_pair(level, name));
                added = true;
                break;
            }
        }

        if (!added) {
            vector<pair<int, string>> temp;
            temp.push_back(make_pair(level, name));
            v.push_back(temp);
            LV.push_back(level);
        }
    }
    for (int i = 0; i < v.size(); i++) {
		sort(v[i].begin(), v[i].end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            return a.second < b.second;
        });
		if(v[i].size() == m) {
			cout << "Started!" <<"\n";
		}
		else {
			cout <<"Waiting!" <<"\n";
		}
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j].first << " " << v[i][j].second << "\n";
        }
		;
    }
    return 0;
}