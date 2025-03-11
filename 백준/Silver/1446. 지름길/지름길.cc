#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    int start, end, length;
    vector<int> leng(d + 1, 100000); // 충분히 큰 값으로 초기화
    vector<vector<pair<int, int>>> shortcuts(d + 1); // 지름길 정보를 저장할 벡터

    for (int i = 0; i < n; i++) {
        cin >> start >> end >> length;
        if (end <= d) {
            shortcuts[end].push_back({start, length});
        }
    }

    leng[0] = 0;
    for (int i = 1; i <= d; i++) {
        if (shortcuts[i].size() == 0) {
            leng[i] = leng[i - 1] + 1;
        }
		else{
			for (auto& shortcut : shortcuts[i]) {
				int temp =min(leng[i - 1] + 1, leng[shortcut.first] + shortcut.second);
				if(temp < leng[i]){
					leng[i] = temp;
				}	
			}
		}
        
    }

    cout << leng[d] << endl;
    return 0;
}

/*

*/