#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define all(x) begin(x), end(x)

void solve() {
    string s = next();
    int one = s.find("1");
    s.erase(s.begin()+one, s.begin()+one+1);
    int six = s.find("6");
    s.erase(s.begin()+six, s.begin()+six+1);
    int nine = s.find("9");
    s.erase(s.begin()+nine, s.begin()+nine+1);
    int eight = s.find("8");
    s.erase(s.begin()+eight, s.begin()+eight+1);

    int remainder = 0;
    for(char c : s){
        remainder *= 10;
        remainder += c-'0';
        remainder %= 7;
    }
    remainder *= 10000;
    string perm = "1689";

    do {
        if(!((remainder + stoi(perm)) % 7)){
            cout << s << perm << "\n";
            return;
        }

    } while (next_permutation(all(perm)));

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}