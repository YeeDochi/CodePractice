#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string temp;
    cin >> temp;
    int n = temp.size();
    int a_count = count(temp.begin(), temp.end(), 'a');
    int min_n = n; 
	
    for (int i = 0; i < n; i++) {
        int moves = 0;
        for (int j = 0; j < a_count; j++) {
            if (temp[(i + j) % n] == 'b') {
                moves++;
            }
        }
        min_n = min(min_n, moves);
    }
    cout << min_n;
    return 0;
}