#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int T, game_num=0;
	string temp;
	char game;
	vector<string> names;
	cin >> T >> game;
	switch (game)
	{
	case 'Y':
		game_num = 1;
		break;
	case 'F':
		game_num = 2;
		break;
	case 'O':
		game_num = 3;
		break;
	default:
		break;
	}
	while (T--) {
		cin >> temp;
		names.push_back(temp);
	}
	sort(names.begin(), names.end());
	names.erase(unique(names.begin(), names.end()), names.end());
	cout << names.size() / game_num << "\n";
		

}
/*
*/