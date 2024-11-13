#include <bits/stdc++.h>
using namespace std;
#define ll long long
int nextInt(){int a; cin >> a; return a;}

class State {
public:
    pair<int, int> here;
    int visited;
    State(pair<int, int> here, int vis){
        this->here = here;
        visited = vis;
    }
    bool operator< (State other) const  {
        return visited < other.visited;
    }
};

void solve() {
    int n = nextInt();
    int r = nextInt() - 1, c = nextInt() - 1;
    // n*n
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            grid[i][j] = nextInt();


    int maxx = 1;
    vector<vector<int>> canVisit(n, vector<int>(n, 0));
    vector<vector<bool>> visited(n, vector<bool>(n));

    priority_queue<State> pq;
    pq.push(*(new State({r, c}, 1)));
    canVisit[r][c] = 1;

    while (pq.size()) {
        auto s = pq.top(); pq.pop();
        int x = s.here.first;
        int y = s.here.second;
        if(visited[x][y]) {
            cout << x << " " << y << " " << s.visited << "\n";
            continue;
        }
        cout << x << " " << y << " " << s.visited << "  visiting" << "\n";

        visited[x][y] = true;

        for(int v = -1; v <= 1; v+=2){
            for(int i = 0; i < n; i++) { 
                int nR = x + v;
                if(nR < 0 || nR >= n) break;
                int nC = i;
                if(abs(nC - y) <= 1 || nC < 0 || nC >= n || grid[nR][nC] <= grid[x][y] || visited[nR][nC]) continue;
                if(canVisit[nR][nC] < canVisit[x][y] + 1){
                    canVisit[nR][nC] = canVisit[x][y] + 1;
                    pq.push(*(new State({nR, nC}, canVisit[nR][nC])));
                    maxx = max(maxx, canVisit[nR][nC]);
                }
            }
        }

        for(int v = -1; v <= 1; v+=2){
            for(int i = 0; i < n; i++) { 
                int nC = y + v;
                if(nC < 0 || nC >= n) break;
                int nR = i;
                if(abs(nR - x) <= 1 || nR < 0 || nR >= n || grid[nR][nC] <= grid[x][y] || visited[nR][nC]) continue;
                if(canVisit[nR][nC] < canVisit[x][y] + 1){
                    canVisit[nR][nC] = canVisit[x][y] + 1;
                    pq.push(*(new State({nR, nC}, canVisit[nR][nC])));
                    maxx = max(maxx, canVisit[nR][nC]);
                }
            }
        }   
    }

    cout << maxx <<  '\n';

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}