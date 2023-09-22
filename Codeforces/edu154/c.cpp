#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    string seq; cin >> seq;
    vector<pair<int, int>> stk;
    // first is size.
    // second 1: sorted, 0:not sorted.
    stk.push_back({0, 1});

    int size = 0;
    for(auto c : seq){

        size += c == '+';
        size -= c == '-';

        // cur size is smaller than prev check.
        while(stk.back().first > size){
            auto [s, sorted] = stk.back();
            stk.pop_back();
            if(s > 1 && sorted)
                stk.push_back({s-1, sorted});
        } 

        if(size == 1 && stk.size() == 1)
            stk.push_back({1, 1});


        if(c=='1'){
            // if last check was sorted. this can also be sorted.
            if(stk.back().second == 1)
                stk.push_back({size, 1});
            else {
                cout << "NO\n";
                return;
            }
        }

        if(c=='0'){
            // if last check was less than cur size. this can be not sorted.
            // or last check was cur size and it was also not sorted.
            if(stk.back().first < size){
                stk.push_back({size, 0});
            }
            else if(stk.back().second){
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";


}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}