#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	long long temp,max;
	cin >> n;
	vector<int> v;
	for(int i=0;i<n;i++){
		max =0;
		cin >> m;
		for(int j=0;j<m;j++){
			cin >> temp;
			v.push_back(temp);
		}
		temp =0;
		for(int j =m-1;j>=0;j--){
			if(v[j] >temp) temp = v[j];
			max += temp - v[j];
		}
		cout << max <<"\n";
		v.clear();
	}
	return 0;
}

// 각 주식의 최대이익
// 앞에 있는 가장 큰 주식 - 본인
// 파는 날의 주식은 최대이익 계산 X, 나머지 최대이익을 더한다. 
// 만약 최대 이익이 음수라면 더하지 않는다다