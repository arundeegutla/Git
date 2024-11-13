#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define TREE '+'
#define HOME 'J'
#define START 'V'
#define oo (int)1e9
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt();
    int m = nextInt();

    vector<string> grid(n);
    int D[][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vector<vector<int>> closestTree(n, vector<int>(m, oo));
    queue<pair<int, int>> treesQ;
    pair<int, int> st;
    pair<int, int> e;
    for(int i = 0; i < n; i++){
        string s = next();
        grid[i] = s;
        for(int j = 0; j < m; j++){
            if(s[j] == TREE){
                treesQ.push({i, j});
                closestTree[i][j] = 0;
            }
            if(s[j] == HOME) e = {i, j};
            if(s[j] == START) st = {i, j};
        }
    }

    while(treesQ.size()){
        auto p = treesQ.front(); treesQ.pop();
        int closest = closestTree[p.first][p.second];
        for(auto d : D){
            int r = p.first + d[0];
            int c = p.second + d[1];
            if(r<0||c<0||r>=n||c>=m) continue;
            int dist = abs(p.first-r) + abs(p.second-c) + closest;
            if(dist < closestTree[r][c]){
                closestTree[r][c] = dist;
                treesQ.push({r, c});
            }
        }
    }

    vector<vector<int>> ans(n, vector<int>(m, -oo));
    queue<pair<int, int>> q;
    q.push(st);
    ans[st.first][st.second] = closestTree[st.first][st.second];

    while(q.size()){
        auto p = q.front(); q.pop();
        int here = ans[p.first][p.second];
        if(p == e) continue;
        for(auto d : D){
            int r = p.first+d[0];
            int c = p.second+d[1];
            if(r<0||c<0||r>=n||c>=m) continue;
            int minnHere = min(here, closestTree[r][c]);
            if(minnHere > ans[r][c]){
                ans[r][c] = minnHere;
                q.push({r, c});
            }
        }
    }

    cout << ans[e.first][e.second] << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}