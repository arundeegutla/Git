#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, m; cin >> n >> m;

    int myMax = 0;
    vector<vector<int>> grid(n+2, vector<int>(m+2, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> grid[i][j];
            myMax = max(grid[i][j], myMax);
        }
    }
    
    if(n == 1 || m == 1) {
        cout << myMax << "\n";
        return;
    }

    map<int, int> pos;
    map<int, int> neg;

    vector<vector<int>> grid1(n+2, vector<int>(m+2, 0));
    vector<vector<int>> grid2(n+2, vector<int>(m+2, 0));

    for (int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            grid1[i][j] = grid[i][j] + grid1[i-1][j+1];

    for (int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            grid2[i][j] = grid[i][j] + grid2[i-1][j-1];

    for(int i = 1; i <= m; i++)
        pos[n+i] = grid1[n][i];
    for(int i = 1; i <= n; i++)
        pos[i+m] = grid1[i][m];

    for(int i = 1; i <= m; i++)
        neg[n-i] = grid2[n][i];
    for(int i = 1; i <= n; i++)
        neg[i-1] = grid2[i][1];
    
    int maxx = 0;
    for (int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            maxx = max(maxx, (pos[i+j] + neg[i-j]) - (pos[i+j] && neg[i-j] ? grid[i][j] : 0));

        

    cout << maxx << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while(n--)
        solve();
}