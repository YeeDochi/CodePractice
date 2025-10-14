#include <iostream>
#include <vector>
using namespace std;
bool visited[20] = {false};
vector<vector<int>> nums;
int mymin = 100000000;
void team(int n,int count,int start_index){

	if(count == n/2){
		int start =0;
		int link =0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(visited[i]&&visited[j]) start+=nums[i][j];
				else if(!visited[i]&&!visited[j]) link+=nums[i][j];
			}
		}
		if(abs(start - link) < mymin)
            mymin = abs(start - link);
		return;
	}

	for(int i=start_index;i<n;i++){
		//if(visited[i])
        //    continue;
		visited[i] = true;
		team(n,count+1,i+1);
		visited[i] = false;
	}
}

int main() {
	int n;
	cin >> n;
	nums.resize(n, vector<int>(n));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> nums[i][j];
	// 코드 작성
	team(n, 0,0);
	cout << mymin << "\n";
	return 0;
}