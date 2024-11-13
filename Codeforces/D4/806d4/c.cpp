#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt();
    vector<int> finalSequence(n);
    for(auto& x : finalSequence) x = nextInt();

    for(auto x : finalSequence){
        int end = x;
        int nmoves = nextInt();
        string moves = next();
        reverse(moves.begin(), moves.end());
        for(auto c : moves){
            if(c == 'D'){
                end += 1;
                end %= 10;
            } else {
                end -= 1;
                if(end < 0)
                    end += 10;
            }
        }
        cout << end << " ";
    }
    cout << "\n";
    
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}