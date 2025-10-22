#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		cout << str + "DORO ";
	}
	return 0;
}