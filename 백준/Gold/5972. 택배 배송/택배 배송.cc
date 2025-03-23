#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;
int main() {
	int n,m;
	cin >>n>>m;
	vector <pair<int,int>> map[50001]; //가중치와 경로
	vector <int> dist(n+1,INT_MAX); // 지금 어디 있는지
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[1] = 0;//시작점에서의 거리
    pq.push(make_pair(0, 1));//거리 , 위치
	while(m--){
		int a,b,c;
		cin >>a>>b>>c;
		map[a].push_back(make_pair(b,c));
		map[b].push_back(make_pair(a,c));
	}
	while(!pq.empty()){
		int where = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if(dist[where]<cost)continue;
		for(int i=0;i<map[where].size();i++){
			int next_place = map[where][i].first;
			int plused_cost = cost + map[where][i].second;
			if(dist[next_place]>plused_cost){
				dist[next_place] = plused_cost;
				pq.push(make_pair(plused_cost,next_place));
			}
		}
	}

	cout << dist[n];
	return 0;
}