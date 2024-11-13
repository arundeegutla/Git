#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    
    int opens = 0;
    int closes = 0;

    int n = s.size();

    for(int i = 0; i < n; i++){
        opens += s[i] == '(';    
        closes += s[i] == ')';

        if(opens == closes) {
            
            string cur = s.substr(i+1);
            cur += s.substr(0, i+1);

            if(cur != s)
                cout << cur << "\n";
            else 
                cout << "no\n";

            return 0;
        }

    }

}