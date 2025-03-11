#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n,m,temp;
	int start=0,end=0,count=0;
	cin >> n >> m;
	vector<int> v;
	int nums[100001]={0,};
	for(int i=0;i<n;i++){
		cin >> temp;
		v.push_back(temp);
	}
	while(1){
		if(nums[v[start]]<m){
			nums[v[start]]++;
			start++;
		}
		else{
			nums[v[end]]--;
			end++;
		}
		if(start > n){start--;break;}
		if(count < start-end){
			count = start-end;
		}
		
	}
	if(count == 0)count = start-end;
	cout << count;
	return 0;
}
