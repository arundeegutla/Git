#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define all(x) begin(x), end(x)

void solve() {
    int n = nextInt();
    string s = next();
    int i = 0;
    string ans;
    while(i<n){
        if(s[i] == '0'){
            bool del = false;
            while(ans.size() && ans.back()=='1') ans.pop_back(), del = true;
            i++;
            if(del) {
                ans += '1'; 
                while(s[i] == '0') i++;
            } 
            ans += '0';
        } else {
            ans += '1';
            i++;
        }
    }

    int one = ans.find('1');
    int zero = ans.find_last_of('0');
    if(one != ans.npos && zero != ans.npos && one < zero)
        ans.erase(ans.begin()+one, ans.begin()+zero);

    cout << ans << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}