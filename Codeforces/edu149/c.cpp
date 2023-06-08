#include <bits/stdc++.h>
using namespace std;


void solve() {
    string line;
    cin >> line;
    char num = '1';
    for(int i = line.size()-1; i >= 0; i--){
        if(line[i] == '?') line[i] = num;
        else num = line[i];
    }
    for(char x:line)
        cout << x;
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while(n--)
        solve();
}