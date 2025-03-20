#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n,temp;
	stack<int> s;

	cin >> n;

	while(n--){
		cin >> temp;
		if(temp == 0){
			s.pop();
		}
		else{
			s.push(temp);
		}
	}

	int sum = 0;
	while(!s.empty()){
		sum += s.top();
		s.pop();
	}
	cout << sum ;
	return 0;
}