#include<iostream>
#include<algorithm>
#include<string>
#include <vector>
using namespace std;
vector<int> result;

int f_max(int temp) {
	int max_index = -1;
	for (int i = result.size() - 1; i >= 0; i--) {
		if (result[i] > temp)max_index = i;
	}
	return max_index;
}
int main(void) {
	int T, count,n, temp;
	int index;
	cin >> T;
	while (T--) {
		result.clear();
		count = 0;
		cin >> n;
		cin >> temp;
		result.push_back(temp);
		for (int i = 1; i < 20; i++) {
			cin >> temp;
			index = f_max(temp);
			if (-1 == index)result.push_back(temp);
			else {
				count += result.size() - index;
				result.insert(result.begin() + index, temp);
			}	
		}
		cout << n << " " << count << endl;
	}

}
