#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void find_head(char** cokie, int T,int temp[2]) {

	for (int i = 0; i < T; i++) {
		for (int j = 0; j < T; j++) {
			if (cokie[i][j] == '*') {
				temp[0] = i;
				temp[1] = j;
				return;
			}
		}
	}
}
int find_center(char** cokie, int T, int heart) {
	int temp = 0;
	for (int i = 0; i < T; i++) {
			if (cokie[i][heart] == '*') {
				temp++;
			}
	}
	return temp;
}

int main()
{
	int T;
	int temp[2];
	int heart[2];
	int L_center;

	int L_arm = 0, R_arm = 0, L_leg = 0, R_leg = 0, center = 0;
	cin >> T;
	char** cokie = new char*[T];
	for (int i = 0; i < T; i++) { // 배열 할당
		cokie[i] = new char[T];
	}

	for (int i = 0; i < T; i++) { //그림 읽어오기
		cin >> cokie[i];
	}

	find_head(cokie,T,heart);
	heart[0]++;
	
	for (int i = 0; i < T; i++) {
		if (cokie[heart[0]][i] == '*') {
			if (i < heart[1]) L_arm++;
			else if(i > heart[1])R_arm++;
		}
	}
	center = find_center(cokie, T, heart[1]) - 2;
	L_center = heart[0] + center; // 몸통의 길이를 머리와 심장의 길이를 빼고 심장의 좌표에 더하면 몸통 끝단의 좌표 

	for (int i = L_center; i < T; i++) {
		if (cokie[i][heart[1] - 1] == '*') L_leg++;
		if (cokie[i][heart[1] + 1] == '*') R_leg++;
	}

	cout << heart[0]+1 << " " << heart[1]+1 << "\n";
	cout << L_arm << " " << R_arm << " " << center << " " << L_leg << " " << R_leg << endl;
}
/*
*/