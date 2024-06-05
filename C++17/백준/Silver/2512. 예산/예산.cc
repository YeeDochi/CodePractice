#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(void) {
	int T, temp, V;
	int max=0,max_i=0;
	int result;
	vector<int> needs;
	
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> temp;
		needs.push_back(temp);
	}
	cin >> V;
	sort(needs.begin(), needs.end());
	if (V/T < needs[0]){
		result = V / T;
	}
	else {
		for (int i = 0; i < T; i++) {
			temp = 0;
			for (int j = 0; j < T; j++) {
				if (j <= i) {
					temp += needs[j];
				}
				else {
					temp += needs[i];
				}

			}
			if (temp < 0) break;
			if (V - temp >= 0) { max_i = i; max = V - temp; }
		}
		if ((T - (max_i + 1)) != 0)
			result = needs[max_i] + (max / (T - (max_i + 1)));
		else result = needs[T - 1];
	}

	cout << result << "\n";
	return 0;
}
/*

*/ 