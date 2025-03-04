#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	int n,m,a;
	scanf("%d %d", &n, &m);

	vector<string> Sv(n);
    vector<int> Iv(n);
	char buffer[100];
    for (int i = 0; i < n; i++) {
       scanf("%s %d", buffer, &Iv[i]);
	   Sv[i] = buffer;
    }


	for(int i=0; i<m; i++) {
		scanf("%d", &a);
		auto it = lower_bound(Iv.begin(), Iv.end(), a);
		if (it != Iv.end()) {
            int index = it - Iv.begin();
           printf("%s\n", Sv[index].c_str());
        }
    }
	return 0;
}