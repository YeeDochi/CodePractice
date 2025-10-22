#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n,k;
	cin >> n >> k;
	vector<int> dp(k + 1,0); // 무개당 최댓값이 저장될 배열
	for(int i=0;i<n;i++){ // i번째 물건을 고려
		int weight, value;
        cin >> weight >> value;
		for(int j=k;j>=weight;j--){ // j 무게를 뒤에서부터 입력된 무개까지 고려
			dp[j] = max(dp[j], dp[j - weight] + value);
		}
	}
	cout << dp[k] << "\n";
	return 0;
}
