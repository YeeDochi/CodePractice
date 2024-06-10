#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

vector<int> energy;
void find(vector<vector<int>> temp, int i,int j, int way,int ful) {
	int size = temp[0].size();
	if (i >= temp.size()) {
		energy.push_back(ful);
		return;
	}
	else {
		if (j - 1 >= 0 && way != 0)
			find(temp, i + 1, j - 1, 0, ful + temp[i][j]);
		if (j + 1 < size && way != 2)
			find(temp, i + 1, j + 1, 2, ful + temp[i][j]);
		if (way != 1)
			find(temp, i + 1, j, 1, ful + temp[i][j]);
	}
}
// 0,1,2 좌 직진 우 -> 저번 노드에 갔던 것
int main(void) {
	int N, M;
	int input;
	int result;
	vector<vector<int>> array;
	vector<int> temp;

	cin >> N >> M;

	for (int i = 0; i < N; i++	){
		temp.clear();
		for (int j = 0; j < M; j++) {
			cin >> input;
			temp.push_back(input);
		}
		array.push_back(temp);
	}
	for(int i=0;i<M;i++)
		find(array, 0, i, -1, 0);
	result = *min_element(energy.begin(), energy.end());
	cout << result << "\n";

}
/*

*/ 