#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string findSame(string X, string Y){
    string A ="";
    int temp;
    int Xn[10]={0,};
    int Yn[10]={0,};
    
    for(char C: X){
        Xn[C-'0']++;
    }
     for(char C: Y){
        Yn[C-'0']++;
    }
    
     for(int i = 9; i >= 0; --i){ 
        temp = min(Xn[i], Yn[i]);
        for (int j = 0; j < temp; ++j) {
            A += (char)('0' + i); 
        }
     }
    
    
    return A;
}

string solution(string X, string Y) {
    string answer = "";
    answer = findSame(X,Y);
    if(answer.size() == 0) answer = "-1";
    else if(answer[0] == '0') answer = '0';
   
    return answer;
}