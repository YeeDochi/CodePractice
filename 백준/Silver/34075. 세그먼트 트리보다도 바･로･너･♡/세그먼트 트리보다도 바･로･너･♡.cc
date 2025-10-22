#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

map<string, int> alg; // 이미 받을때 문자열기준 자동 정렬
map<string, int> idol;

void find_near(string name){
	int tier = idol[name];

	vector<pair<int, string>> preferences;

    for (auto const& [alg_name, alg_difficulty] : alg) {
        int diff = abs(alg_difficulty - tier);
        preferences.push_back({diff, alg_name});
    }
	sort(preferences.begin(), preferences.end()); // 선호도, 알고리즘 형태의 백터쌍
    cout << preferences[1].second << " yori mo " << preferences[0].second << "\n";
}


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		string str;
		cin >> str >> temp;
		alg[str] = temp;
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		string str;
		cin >> str >> temp;
		idol[str] = temp;

	}
	cin >> n;
	cin.ignore(); // 버퍼 비우기
	string name;
	for (int i = 0; i < n; i++)
	{
		string str;
		getline(cin, str);
		if(str.find(" - chan!") != string::npos){
			name = str.substr(0, str.find(" - chan!"));
			cout << "hai!" <<"\n";
		}
		else if(str == "nani ga suki?"){
			find_near(name);
		}

	
	}
	return 0;
}