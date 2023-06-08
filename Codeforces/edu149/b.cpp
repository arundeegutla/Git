#include <bits/stdc++.h>
using namespace std;


void solve() {
    int len; cin >> len;
    string s; cin >> s;
    int increasing = 0;
    int decreasing = 0;
    int maxx = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '<') {
            increasing++;
            decreasing = 0;
            maxx = max(maxx, increasing);
        } else {
            decreasing++;
            increasing = 0;
            maxx = max(maxx, decreasing);
        }
    }
    cout << maxx + 1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while(n--)
        solve();
}
