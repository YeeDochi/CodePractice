#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string str;
	
	bool flag = true;
	int i;
	while(true){
		getline(cin,str);
		if(str == ".")break;
		stack<char> s;
		i=0;
		flag = true;
		while(str[i] != '.'){
			if(str[i] == '(' || str[i] == '[')s.push(str[i]);

			if(str[i] == ')'&&(s.empty()||s.top() !='(')){flag = false;break;}
			if(str[i] == ')'&&s.top() == '(')s.pop();

			if(str[i] == ']'&&(s.empty()||s.top() !='[')){flag = false;break;}
			if(str[i] == ']'&&s.top() == '[')s.pop();

			i++;
		}
		if(s.size() != 0)flag = false;	

		if(flag)cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}