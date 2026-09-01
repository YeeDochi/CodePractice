#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int INF = 100000000;
void display(vector<vector<pair<int,int>>> graph){
    for(int i = 1;i<graph.size();i++){
        for(int j = 0; j<graph[i].size();j++){
            cout << graph[i][j].first << "," << graph[i][j].second << ", ";
        }
        cout << "\n";
    }
}

vector<int> dijkstra(int src, int n, const vector<vector<pair<int,int>>>& graph){
    vector<int> dist(n+1,INF);
    dist[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,src});

    while (!pq.empty()){
        pair temp = pq.top();
        int cost = temp.first;
        int node = temp.second;
        pq.pop();
        if (cost > dist[node]) continue;
        for (auto& e : graph[node]) {
            int n_node = e.first;
            int n_cost = e.second;
            if (cost + n_cost < dist[n_node])
                dist[n_node] = cost+n_cost;
            pq.push({cost+n_cost,n_node});
        }

    }
    return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;

    vector<vector<pair<int,int>>> graph(n+1);

    for(int i =0; i<fares.size();i++){
        graph[fares[i][0]].push_back(pair(fares[i][1],fares[i][2]));
        graph[fares[i][1]].push_back(pair(fares[i][0],fares[i][2]));
    }
    //display(graph);

    vector<int> da = dijkstra(a,n,graph);
    vector<int> db = dijkstra(b,n,graph);
    vector<int> ds = dijkstra(s,n,graph);

    for (int k =1; k<n+1;k++){
        answer = min (answer, da[k]+db[k]+ds[k]);
    }

    return answer;
}
