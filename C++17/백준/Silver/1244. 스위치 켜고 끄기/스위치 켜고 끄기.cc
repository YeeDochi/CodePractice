#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct student {
	int gender;
	int number;
};
int change(int i) {
	if (i == 1)return 0;
	return 1;
}
vector<int> light_control(vector<int> light, student temp) {
	int countL, countR;
	if (temp.gender == 1) {
		for (int i = temp.number-1; i < light.size(); i+=temp.number) {
			light[i] = change(light[i]);
		}
	}
	else {
		countL = temp.number-1;
		countR = temp.number-1;
		while (true) {
			if (countL-1 >= 0 && countR+1 < light.size()&& light[countL-1] == light[countR+1]) {
				countL--;
				countR++;
			}
			else break;
		}
		for (int i = countL; i <= countR; i++) {
			light[i] = change(light[i]);
		}
	}

	return light;
}
int main(void) {
	int T,temp;
	student Stemp;
	vector<int> lights;
	vector<student> students;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> temp;
		lights.push_back(temp);
	}
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> Stemp.gender >> Stemp.number;
		lights = light_control(lights, Stemp);
	}

	for (int i = 0; i < lights.size(); i++) {
		cout << lights[i] << " ";
		if((i+1)%20 ==0)
		cout << "\n";
	}
}
/*

*/