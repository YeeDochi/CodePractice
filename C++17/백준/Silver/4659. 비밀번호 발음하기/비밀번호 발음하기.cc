#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    char temp[6] = { 'a','e','i','o','u','!'};
    int stack,trigger;
    bool A;
    string get=" ";
    char temp2;
    while (true) {
        stack = 0; trigger = 1;
        temp2 = ' ';
        int chack[3] = { 0,1,1 };
        cin >> get;
        if (get == "end") { trigger = 0; break; }
        for (int i = 0; i < get.length(); i++) {
            if (find(begin(temp), end(temp), get[i]) != end(temp))A = true; // 자음 있음
            else A = false;//현 단어의 자음 모음 확인
            if (chack[0] == 0 && A == true)chack[0] = 1; // 모음 포함 확인
            if (temp2 == get[i] && get[i] != 'e' && get[i] != 'o'  )chack[1] = 0; // 같은글자 연속 확인
            if (A && stack >= 0) stack++;
            else if (!A && stack <= 0) stack--;// 자음,모음 연속 확인
            else {
                if (A)stack = 1;
                else if (!A) stack = -1;
                else stack = 0;
            }
            if (stack > 2 || stack < -2)chack[2] = 0;
            temp2 = get[i];
        }
        for (int i = 0; i < 3; i++) {
          //  cout << chack[i] << " ";
            if (chack[i] == 0) {
              // cout << "\n";
                cout << "<" + get + "> is not acceptable." << endl;
                trigger = 0;
                break;
            }
        }
//cout << "\n";
        if(trigger == 1) cout << "<" + get + "> is acceptable." << endl;
    }

    
}
/*
*/