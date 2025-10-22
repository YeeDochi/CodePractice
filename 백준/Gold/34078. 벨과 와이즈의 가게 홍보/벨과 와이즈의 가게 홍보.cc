#include <iostream>
#include <vector>	
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<bool> visited(n,false);
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];	
	}

	int count_asc =0;
	for (int i = 0; i < n; i++)
	{	if(visited[i]) continue;
		while(!visited[i]){
			visited[i] = true;
			i = arr[i]-1;
		}
		count_asc++;
	}
	int count_desc = 0;
	fill(visited.begin(), visited.end(), false);
	for (int i = 0; i < n; i++)
	{	if(visited[i]) continue;
		while(!visited[i]){
			visited[i] = true;
			i = n-arr[i];
		}
		count_desc++;
	}
	int count = max(count_asc, count_desc);

	cout << n-2<<" " <<n-count<< "\n";
	return 0;
}