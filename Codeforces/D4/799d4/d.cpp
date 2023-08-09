#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    string time; cin >> time;
    int next; cin >> next;

    pair<int, int> start = {stoi(time.substr(0, 2)), stoi(time.substr(3, 2))};

    set<pair<int, int>> hset;

    int count = 0;
    while(true){

        hset.insert(start);
        string f = to_string(start.first);
        string s = to_string(start.second);
        reverse(f.begin(), f.end());
        reverse(s.begin(), s.end());
        f.resize(2, '0');
        s.resize(2, '0');
        reverse(s.begin(), s.end());

        count += f == s;

        int h = start.first;
        int m = start.second;

        m += next;
        h += m/60;
        h %= 24;
        m = m%60;

        start = {h, m};
        if(hset.find(start) != hset.end())
            break;
    }

    cout << count << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}