#include <bits/stdc++.h>
using namespace std;


void solve() {
    int len;
    cin >> len;
    string line; cin>>line;

    vector<int> colors(len, 0);
    stack<int> opens;
    stack<int> closes;

    for(int i = 0; i<len; i++) {
        char x = line[i];
        if(x == '(') {
            if(closes.size()){
                colors[closes.top()] = 1; closes.pop();
                colors[i] = 1;
            } else 
                opens.push(i);
        } else {
            if(opens.size()){
                colors[opens.top()] = 2; opens.pop();
                colors[i] = 2;
            } else 
                closes.push(i);
        }
    }

    bool hasZero = false;
    map<int, int> map;
    for(auto x:colors) {
        if(map.find(x)==map.end())
            map[x] = map.size()+1;
        hasZero |= x==0;
    }

    if(hasZero) {
        cout << -1;
    } else {
        cout << map.size() << "\n";
        for(auto x : colors)
            cout << map[x] << " ";
    }
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