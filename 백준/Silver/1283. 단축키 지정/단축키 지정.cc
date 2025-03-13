#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void printWithP(string s, int n) {
    for (int i = 0; i < s.size(); i++) {
        if (i == n) cout << '[' << s[i] << ']';
        else cout << s[i];
    }
    cout << '\n';
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // 개행 문자를 무시
    string s;
    vector<char> v;
    bool flag = false;

    for (int i = 0; i < n; i++) {
        flag = false;
        getline(cin, s);
        if (find(v.begin(), v.end(), tolower(s[0])) == v.end()) {
            v.push_back(tolower(s[0]));
            printWithP(s, 0);
        } else {
            for (int j = 0; j < s.size(); j++) {
                if (s[j] == ' ') {
                    if (find(v.begin(), v.end(), tolower(s[j + 1])) == v.end()) {
                        v.push_back(tolower(s[j + 1]));
                        printWithP(s, j + 1);
                        flag = true;
                        break;
                    }
                }
            }
            if (!flag) {
                flag = false;
                for (int j = 0; j < s.size(); j++) {
                    if (s[j] == ' ') continue;
                    if (find(v.begin(), v.end(), tolower(s[j])) == v.end()) {
                        v.push_back(tolower(s[j]));
                        flag = true;
                        printWithP(s, j);
                        break;
                    }
                }
                if (!flag) {
                    cout << s << '\n';
                }
            }
        }
    }
    return 0;
}