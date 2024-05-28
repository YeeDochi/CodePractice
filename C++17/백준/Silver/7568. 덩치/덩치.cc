#include <iostream>

using namespace std;

int main() {
    int n;
    int x[50]={0, };
    int y[50]={0, };
    scanf("%d",&n);
    for(int i =0;i<n;i++){
        scanf("%d %d",&x[i],&y[i]);
    }
    // A보다 덩치가 큰 사람만큼 등수를 더한다.
    for(int i=0;i<n;i++){
        int k=1;
        for(int j=0; j<n;j++){
            if(x[i]<x[j]&&y[i]<y[j]){
                k++;
            }
        }
        printf("%d ",k);
    }
    
}