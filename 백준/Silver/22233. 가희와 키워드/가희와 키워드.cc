#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    unordered_set<string> s;
    vector<string> v2;
    char temp1[110];
	string temp2;

    for (int i = 0; i < n; i++) {
        scanf("%s", temp1);
        s.insert(temp1);
    }

    for (int i = 0; i < m; i++) {
       scanf("%s", temp1);
        istringstream ss(temp1);
        while (getline(ss, temp2, ',')) {
            v2.push_back(temp2);
        }
        for (const auto& str : v2) {
            s.erase(str);
        }
		printf("%d\n", s.size());
        v2.clear();
    }

    return 0;
}