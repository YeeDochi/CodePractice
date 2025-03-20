#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	string temp;
	int count;
	cin >> n;
	while(n--){
		count =0;
		cin >> temp;
		for(int i=0;i<temp.size();i++){
			if(temp[i] == '(')count++;
			else count--;
			if(count < 0){
				break;
			}
		}
		if(count == 0)cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	return 0;
}