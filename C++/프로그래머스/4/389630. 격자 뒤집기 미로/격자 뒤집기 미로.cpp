#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
 
int temp = -1;

int cCalc(vector<vector<int>> v, vector<vector<int>> h, int k, int n, int m, vector<int> r){
    int result = 0;
    int loss = 101;
    for(int i =0; i<m; i++){
        int A = 0, B = 0; // A : 안뒤집었을때, B : 뒤집었을때
        int Amin = 101, Bmin = 101;
        for(int j =0; j< n; j++){
            int a = r[j] == 0 ? v[j][i] : h[j][i];
            int b = r[j] == 0 ? h[j][i] : v[j][i];
            A += a;
            B += b;
            if((i+j)%2 == 1){
                Amin = min(Amin, a);
                Bmin = min(Bmin, b);
            }
        }
        int best = max(A,B-k);
        int nomal = max(A-Amin,B-Bmin-k);
        result += best;
        loss = min(loss,best-nomal);
    }
    return n%2+m%2 ==0 ? result - loss : result;
}

void clac(vector<vector<int>> v, vector<vector<int>> h, int k, int n, int m, vector<int> r, int i){
    if(i == n){
        int kC = 0;
        for(int j = 0; j < r.size(); j++) if (r[j] == 1) kC++;
        temp = max(cCalc(v,h,k,n,m,r) - k*kC ,temp);
        return;
    }

    r[i] = 0;
    clac(v,h,k,n,m,r,i+1);
    r[i] = 1;
    clac(v,h,k,n,m,r,i+1);
}


int solution(vector<vector<int>> visible, vector<vector<int>> hidden, int k) {
    int n = visible.size();     //n 세로
    int m = visible[0].size();  //m 가로
    temp = -1;
    vector<int> r(n,0);
    clac(visible,hidden,k,n,m,r,0);
    return temp;
}
