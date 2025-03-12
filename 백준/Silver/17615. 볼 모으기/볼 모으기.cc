#include <iostream>
#include <string>
using namespace std;
int main() {
	int n;
	string s;
	cin >> n >> s;
	bool find_anoter;
	int result;
	int min = 0;
	find_anoter = false;
	result = 0;
	for(int i=0;i<n;i++) {
		if(s[i] =='B') 
			find_anoter = true;
		if(s[i] == 'R'&&find_anoter)result++;
	}
	min = result;

	find_anoter = false;
	result = 0;
	for(int i=0;i<n;i++) {
		if(s[i] =='R') 
			find_anoter = true;
		if(s[i] == 'B'&&find_anoter)result++;
	}
	if(min>result)min = result;
	find_anoter = false;
	result = 0;
	for(int i=n-1;i>=0;i--) {
		if(s[i] =='R') 
			find_anoter = true;
		if(s[i] == 'B'&&find_anoter)result++;
	}
	if(min>result)min = result;
	find_anoter = false;
	result = 0;
	for(int i=n-1;i>=0;i--) {
		if(s[i] =='B') 
			find_anoter = true;
		if(s[i] == 'R'&&find_anoter)result++;
	}
	if(min>result)min = result;

	cout << min;
	return 0;
}