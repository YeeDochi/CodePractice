#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(void) {
	int X, N, temp;
	int temp_num,count;
    int  current_sum = 0;
	int max = -1;
	vector<int> nums;
	cin >> X >> N;
	for (int i = 0; i < X; i++) {
		cin >> temp;
		nums.push_back(temp);
	}

    for (int i = 0; i < N; i++) {
        current_sum += nums[i];
    }
    max = current_sum;
    count = 1;
    for (int i = N; i < X; i++) {
        current_sum = current_sum - nums[i - N] + nums[i];
        if (current_sum > max) {
            max = current_sum;
            count = 1;
        }
        else if (current_sum == max) {
            count++;
        }
    }

    if (max <= 0)cout << "SAD";
    else cout << max << "\n" << count;
	return 0;
}
/*

*/ 