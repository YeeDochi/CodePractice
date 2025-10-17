#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int,int>> adj[5001];



void init(int n){
	for(int i=0;i<n-1;i++){
		int u,v,w;
		cin >> u >> v >> w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
}

int find(int k, int v){
	int result =0;
	queue<int> q;
	vector<bool> visited(5001,false);
	
	q.push(v);
	visited[v]=true;

	while(!q.empty()){
		int curr = q.front();
		q.pop();
		for(auto next : adj[curr]){
			if(!visited[next.first]&& next.second >=k){
				visited[next.first]=true;
				result++;
				q.push(next.first);
			}
		}

	}
	return result;
}

int main() {
	int n,q;
	cin >> n >> q;
	init(n);
	for(int i=0;i<q;i++){
		int k,v;
		cin >> k >> v;
		cout << find(k,v) << "\n";
	}
	return 0;
}

