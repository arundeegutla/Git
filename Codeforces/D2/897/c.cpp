#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int n; 
    cin >> n;
    set<int> s;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        s.insert(x);
    }

    auto mex = [&](set<int>& s) -> int {
        for(int i = 0; i <= n; i++)
            if(s.find(i) == s.end())
                return i;
        return n+1;
    };


    int curMex = mex(s);
    while(true){

        s.insert(curMex);
        cout << curMex << "\n";
        cout.flush();

        int removed;
        cin >> removed;

        if(removed == -1) {
            return;
        }
        if(removed == -2){
            exit(0);
            return;
        }

        s.erase(removed);
        curMex = removed;
    }


}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}