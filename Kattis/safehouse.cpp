#include <bits/stdc++.h>
using namespace std;

int main(){
    int oo = 1e9;
    int n; cin >> n;
    vector<string> grid(n);
    for(int i = 0; i < n; i++)
        cin >> grid[i];
    

    vector<pair<int, int>> spys;
    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(n, oo));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j]=='H'){
                q.push({i, j});
                dist[i][j] = 0;
            }
            if(grid[i][j]=='S')
                spys.push_back({i, j});
        }
    }
    
    int D[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while(q.size()){
        auto here = q.front(); q.pop();
        int r = here.first;
        int c = here.second;
        int myD = dist[r][c];
        for(auto d : D){
            int nR = r+d[0], nC = c+d[1];
            if(nR < 0 || nR >= n || nC < 0 || nC >= n) continue;
            if(dist[nR][nC] > myD + 1){
                dist[nR][nC] = myD+1;
                q.push({nR, nC});
            }
        }
    }
    
    int maxx = -1;
    for(auto x : spys){
        maxx = max(maxx, dist[x.first][x.second]);
    }

    cout << maxx << "\n";
}