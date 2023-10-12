#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    for(int firstBreak = 0; firstBreak <= 7; firstBreak++){

        bool can = true;
        set<char> firstHave;
        for(int i = 0; i < firstBreak; i++){
            if(firstHave.find(s[i]) != firstHave.end()){
                can = false;
                break;
            }
            firstHave.insert(s[i]);
        }

        for(int i = firstBreak; i < s.size(); i += 7){
            set<char> have;
            for(int j = i, c = 0; j < s.size() && c < 7; c++, j++){
                if(have.find(s[j]) != have.end()){
                    can = false;
                    break;
                }
                have.insert(s[j]);
            }
        }

        if(can) {
            cout << 1 << "\n";
            return;
        }

    }

    cout << 0 << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}