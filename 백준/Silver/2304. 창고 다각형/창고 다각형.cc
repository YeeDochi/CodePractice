#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare1(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

bool compare2(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    int n;
    int l, h;
    int maxH, maxI,max =0;
	int sum=0;
    vector<pair<int, int>> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l >> h;
        v.push_back(make_pair(l, h));
    }
    sort(v.begin(), v.end(), compare1);
    auto maxIt = max_element(v.begin(), v.end(), compare2);
    maxH = maxIt->second;
    maxI = distance(v.begin(), maxIt); // 인덱스 계산
    

	for(int i=0;i<maxI;i++){
		if(max < v[i].second){
			max = v[i].second;
		}
		sum+=abs(max * (v[i+1].first - v[i].first));
	}
	max =0;
	for(int i = v.size()-1;i>maxI;i--){
		if(max < v[i].second){
			max = v[i].second;
		}
		sum+=abs(max * (v[i].first - v[i-1].first));
	}
	cout << sum + maxH << "\n";
    return 0;
}