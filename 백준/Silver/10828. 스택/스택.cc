#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    int trun;
    string cmend;
    int inPut;

    stack<int> st;
    cin >> trun;

    while (trun--) {
        cin >> cmend;
        if (cmend == "push") {
            cin >> inPut;
            st.push(inPut);
        }
        else if (cmend == "pop") {
            if (!st.empty()) {
                cout << st.top() << endl;
                st.pop();
            }
            else {
                cout << -1 << endl;
            }
        }
        else if (cmend == "size") {
            cout << st.size() << endl;
        }
        else if (cmend == "empty") {
            cout << (st.empty() ? 1 : 0) << endl;
        }
        else if (cmend == "top") {
            if (!st.empty()) {
                cout << st.top() << endl;
            }
            else {
                cout << -1 << endl;
            }
        }
    }
}
