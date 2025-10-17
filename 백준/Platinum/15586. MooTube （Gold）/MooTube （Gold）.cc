#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
	int p,q,r;

};
struct query{
	int k;
	int v;
	int index;
};
bool compareEdges(const edge& a, const edge& b) {
    return a.r > b.r;
}

bool compareQueries(const query& a, const query& b) {
    return a.k > b.k;
}

int parent[100001];
int component_size[100001];

int find_root(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find_root(parent[x]);
}

void unite(int a, int b) {
    int root_a = find_root(a);
    int root_b = find_root(b);

    if (component_size[root_a] < component_size[root_b]) {
            parent[root_a] = root_b;
            component_size[root_b] += component_size[root_a];
        } else {
            parent[root_b] = root_a;
            component_size[root_a] += component_size[root_b];
        }
}
vector<edge> edges;
vector<query> queries;

void init(int n,int q){
	for(int i=0;i<n-1;i++){
		int u,v,w;
		cin >> u >> v >> w;
		edges.push_back({u,v,w});
	}
	for(int i=0;i<q;i++){
		int k,v;
		cin >> k >> v;
		queries.push_back({k,v,i});
	}
	for (int i = 1; i <= n; i++) {
        parent[i] = i;
        component_size[i] = 1;
    }
	sort(edges.begin(), edges.end(), compareEdges);
    sort(queries.begin(), queries.end(), compareQueries);
}

vector<int> find(int q){
	int edge_idx = 0; 
    vector<int> results(q);
    for(int i=0; i<q; i++) { 
        int k = queries[i].k;
		int r_index = queries[i].index;
        while (edge_idx < edges.size() && edges[edge_idx].r >= k) {
            unite(edges[edge_idx].p, edges[edge_idx].q);
            edge_idx++; 
        }
        int root_v = find_root(queries[i].v);
        int result = component_size[root_v]-1;
        results[r_index] = result;
    }
    return results;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n,q;
	cin >> n >> q;
	
	init(n,q);
	vector<int> results = find(q);
	for (int i = 0; i < q; i++) {
		cout << results[i] << "\n";
	}
	return 0;
}

