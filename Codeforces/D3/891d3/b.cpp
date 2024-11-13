#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define all(x) begin(x), end(x)

void solve() {
    string num = next();

    if(num.size() == 1) {
        cout << ((num[0]-'0' >= 5 ) ? 10 : num[0]-'0') << "\n";
        return;
    }

    int ind = num.size()-1;
    int prev = 0;
    for(int i = num.size()-1; i >= 0; i--){
        if(num[i]-'0' == 9) {
            prev = 9;
            ind = i;
        } else if(prev >= 5){
            num[i]++;
            prev = num[i]-'0';
            ind = i;
        } else {
            prev = num[i]-'0';
        }
    }

    if(prev >= 5) {
        string ret;
        ret.resize(num.size()+1, '0');
        ret[0] = '1';
        cout << ret << "\n";
        return;
    }

    for(int i = 0; i <= ind; i++){
        cout << num[i] << "";
    }
    for(int i = ind+1; i < num.size(); i++){
        cout << '0' << "";
    }
    cout << "\n";


}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}