#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int Gcount =0;
bool isPrime(int n) {
	    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) { 
        if (n % i == 0) return false;
    }
    return true;

}

void find(int dept,vector<int> nums, int sum, int start) {
	if(dept == 3) {
        if(isPrime(sum))Gcount++;
        return;
	}
	for (int i = start; i < nums.size(); i++) {
		find(dept+1,nums, sum+nums[i], i + 1);
	}
}

int solution(vector<int> nums) {
    int answer = -1;

   
    find(0,nums,0,0);
    answer = Gcount;
    return answer;
}