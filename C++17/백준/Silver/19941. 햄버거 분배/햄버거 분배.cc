#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(void) {
	int N, K;
	int count = 0;
	string temp;
	vector<string> hp;
	cin >> N >> K;
	cin >> temp;
	
		for (int i = 0; i < temp.length(); i++) {
			if (temp[i] == 'P') {
				for (int j = i + 1; j <= i + K; j++) {
					if (temp[j] == 'H') {
						temp[j] = 'X';
						count++;
						break;
					}
				}
			}
			else if (temp[i] == 'H') {
				for (int j = i + 1; j <= i + K; j++) {
					if (temp[j] == 'P') {
						temp[j] = 'X';
						count++;
						break;
					}
				}
			}
		}
	

	cout << count << "\n";
}
/*

*/ 