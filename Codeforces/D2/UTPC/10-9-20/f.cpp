#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define all(x) begin(x), end(x)

void solve() {
    int n = nextInt();
    vector<string> arr(3);
    for(auto& x : arr) x = next();

    vector<vector<bool>> seen(3, vector<bool>(n));
    queue<pair<int, int>> q;
    for(int i = 0; i < 3; i++)
        if(arr[i][0] != '1')
            q.push({i, 0});

    int D[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while(q.size()){
        auto here = q.front(); q.pop();
        if(here.second == n-1) {
            cout << "Solvable!" << "\n";
            return;
        }
        if(seen[here.first][here.second]) continue;

        seen[here.first][here.second] = true;
        for(auto d : D){
            int nR = here.first + d[0];
            int nC = here.second + d[1];
            if(nR < 0 || nR >= 3 || nC < 0 || nC >= n || arr[nR][nC] == '1') continue;
            q.push({nR, nC});
        }
    }

    cout << "Unsolvable!" << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}