#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>

using namespace std;

bool frequency(const pair<string, int>&a, const pair<string, int>& b ) {
	if (a.second == b.second) {
		if (a.first.length() == b.first.length())
			return a.first < b.first;
		else
		return a.first.length() > b.first.length(); 
	}
	else return a.second > b.second;
}

int main(void) {
	
	vector<string> words;
	string temp;
	int N, M;
	map<string, int> freq;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp.length() >= M)words.push_back(temp);
	}
	
	for (int i = 0; i < words.size(); i++)
		freq[words[i]]++;

	vector<pair<string, int>> freq_vec(freq.begin(), freq.end());

	sort(freq_vec.begin(), freq_vec.end(), frequency);

	for (int i = 0; i < freq_vec.size(); i++) {
		cout << freq_vec[i].first << "\n";
	}


}
/*

*/