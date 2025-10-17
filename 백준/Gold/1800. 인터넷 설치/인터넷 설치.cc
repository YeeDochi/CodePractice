#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1e9; 
int N, P, K;
vector<pair<int, int>> adj[1001]; 
int dist[1001];

struct Node {
    int cost;
    int to;
    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

bool check(int x) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    fill(dist, dist + N + 1, INF);

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        int cost = pq.top().cost;
        int curr = pq.top().to;
        pq.pop();

        if (cost > dist[curr]) continue;

        for (auto& edge : adj[curr]) {
            int next = edge.first;
            int original_price = edge.second;
            
            int new_cost = (original_price > x) ? 1 : 0; 
            
            if (dist[curr] + new_cost < dist[next]) {
                dist[next] = dist[curr] + new_cost;
                pq.push({dist[next], next});
            }
        }
    }
    return dist[N] <= K;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> P >> K;
    for (int i = 0; i < P; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }

    int low = 0;
    int high = 1000001; 
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (check(mid)) { 
            ans = mid;      
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << "\n";
    
    return 0;
}