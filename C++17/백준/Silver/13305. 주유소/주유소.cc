#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int main(void) {
	

	int T;
	int temp, weight,result =0;	
	vector<int> way;
	vector<int> node;
	cin >> T;
	for (int i = 0; i < T-1; i++) {
		cin >> temp;
		way.push_back(temp);
	}
	for (int i = 0; i < T ; i++) {
		cin >> temp;
		node.push_back(temp);
	}
	weight = node[0];

	for (int i = 0; i < T-1; i++) {
		result += (weight * way[i]);
		if (node[i + 1] < weight)weight = node[i + 1];
	}
	cout << result << endl;
	


}
/*

*/