#include <iostream>
#include <queue>
using namespace std;
int map[101]={0,};
bool visited[101]={0,};

void dfs(int s,int c){
	queue<pair<int, int>> q;
    q.push(make_pair(s, c));
	while(!q.empty()){
		int p = q.front().first;
		int count = q.front().second;
		q.pop();
		for(int i=0;i<6;i++){
			int np = p+i+1;
			if(np >= 100){
				cout << count+1 << endl;
				return;
			}
			else if(np<100){
				while(map[np] != 0){//이동한 장소가 또 사다리,뱀 일 수 있다.
					np = map[np];
				}
				if(!visited[np]){
					visited[np] = true;
					q.push(make_pair(np, count+1));
				}
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	int x, y;
	while(n--){
		cin >> x >> y;
		map[x] = y;
	}
	while(m--){
		cin >> x >> y;
		map[x] = y;
	}
	dfs(1, 0);
	return 0;
}