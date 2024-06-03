#include<iostream>
//#include<algorithm>
//#include<vector>
#include<queue>

using namespace std;


int test2(int temp) {
	queue<int> array;
	for (int i = 0; i < temp; i++)array.push(i + 1);
	while (array.size() > 1) {
		array.pop();
		int a = array.front();
		array.pop();
		array.push(a); 
	}

	return array.front();
}

int main(void) {
	

		int T;
		vector<int> array;
		cin >> T;
		cout << test2(T) << endl;
	

}
/*

*/