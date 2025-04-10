#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    
    stack<char> S;
    bool answer = true;
    for(char c : s){
        if(c == '('){
            S.push(c);
        }
        if(c ==')'){
            if(S.empty()){
            answer = false;
            break;
            }
            S.pop();
        }
    }
    if(!S.empty()) answer = false;
    return answer;
}