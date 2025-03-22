#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int n;
	long long temp;
	cin >> n;
	stack<pair<long long,int>> s;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin >>temp;
		while(!s.empty()&&s.top().first<=temp){
			s.pop();
		}
		if(!s.empty()){
			v[i]=s.top().second+1;
		}
		else{
			v[i]=0;
		}
		s.push({temp,i});
	}
	
	for(int i=0;i<n;i++){
		cout << v[i] << " ";
	}
	return 0;
}

/*
입력->나보다 작은 왼쪽은 제거-> 내 인덱스의 -1번째 출력
*/