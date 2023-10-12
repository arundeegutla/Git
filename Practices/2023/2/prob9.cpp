#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    string allMoves;
    getline(cin, allMoves);

    vector<vector<int>> grid(9, vector<int>(9, -1));
    vector<vector<int>> MAIN(3, vector<int>(3, -1));
    

    auto who = [&](int r, int c) -> int {

        // diag
        if(grid[r][c] == grid[r+1][c+1] && grid[r][c] == grid[r+2][c+2] && grid[r][c] != -1) return grid[r][c];
        if(grid[r+2][c] == grid[r+1][c+1] && grid[r+2][c] == grid[r][c+2] && grid[r][c+2] != -1) return grid[r][c+2];

        // horizontals
        if(grid[r][c] == grid[r][c+1] && grid[r][c] == grid[r][c+2] && grid[r][c] != -1) return grid[r][c];
        if(grid[r+1][c] == grid[r+1][c+1] && grid[r+1][c] == grid[r+1][c+2] && grid[r+1][c] != -1) return grid[r+1][c];
        if(grid[r+2][c] == grid[r+2][c+1] && grid[r+2][c] == grid[r+2][c+2] && grid[r+2][c] != -1) return grid[r+2][c];

        // verticals
        if(grid[r][c] == grid[r+1][c] && grid[r][c] == grid[r+2][c] && grid[r][c] != -1) return grid[r][c];
        if(grid[r][c+1] == grid[r+1][c+1] && grid[r][c+1] == grid[r+2][c+1] && grid[r][c+1] != -1) return grid[r][c+1];
        if(grid[r][c+2] == grid[r+1][c+2] && grid[r][c+2] == grid[r+2][c+2] && grid[r][c+2] != -1) return grid[r][c+2];


        bool neg = false;
        for(int i = r; i <= r+2; i++){
            for(int j = c; j <= c+2; j++){
                neg |= grid[i][j] == -1;
            }
        }

        return neg ? -1 : 3;
    };


    auto check = [&]() -> bool {
        int r = 0;
        int c = 0;

        auto here = MAIN;
        for(auto& arr : here) for(auto& c : arr) if(c == 3) c = 1;



        bool won = false;
        won |= (here[r][c] == here[r+1][c+1] && here[r][c] == here[r+2][c+2] && here[r][c] != -1);
        won |= (here[r+2][c] == here[r+1][c+1] && here[r+2][c] == here[r][c+2] && here[r][c+2] != -1);

        // horizontals
        won |= (here[r][c] == here[r][c+1] && here[r][c] == here[r][c+2] && here[r][c] != -1);
        won |= (here[r+1][c] == here[r+1][c+1] && here[r+1][c] == here[r+1][c+2] && here[r+1][c] != -1);
        won |= (here[r+2][c] == here[r+2][c+1] && here[r+2][c] == here[r+2][c+2] && here[r+2][c] != -1);

        // verticals
        won |= (here[r][c] == here[r+1][c] && here[r][c] == here[r+2][c] && here[r][c] != -1);
        won |= (here[r][c+1] == here[r+1][c+1] && here[r][c+1] == here[r+2][c+1] && here[r][c+1] != -1);
        won |= (here[r][c+2] == here[r+1][c+2] && here[r][c+2] == here[r+2][c+2] && here[r][c+2] != -1);

        here = MAIN;
        for(auto& arr : here) for(auto& c : arr) if(c == 3) c = 0;


        won |= (here[r][c] == here[r+1][c+1] && here[r][c] == here[r+2][c+2] && here[r][c] != -1);
        won |= (here[r+2][c] == here[r+1][c+1] && here[r+2][c] == here[r][c+2] && here[r][c+2] != -1);

        // horizontals
        won |= (here[r][c] == here[r][c+1] && here[r][c] == here[r][c+2] && here[r][c] != -1);
        won |= (here[r+1][c] == here[r+1][c+1] && here[r+1][c] == here[r+1][c+2] && here[r+1][c] != -1);
        won |= (here[r+2][c] == here[r+2][c+1] && here[r+2][c] == here[r+2][c+2] && here[r+2][c] != -1);

        // verticals
        won |= (here[r][c] == here[r+1][c] && here[r][c] == here[r+2][c] && here[r][c] != -1);
        won |= (here[r][c+1] == here[r+1][c+1] && here[r][c+1] == here[r+2][c+1] && here[r][c+1] != -1);
        won |= (here[r][c+2] == here[r+1][c+2] && here[r][c+2] == here[r+2][c+2] && here[r][c+2] != -1);


        return won;
    };


    stringstream s(allMoves);
    int count = 0;
    int nextR = -1;
    int nextC = -1;

    while(s.good()) {
        string m;
        s >> m;

        // cout << m << "\n";
        int row = m[0]-'0';
        int col = m[1]-'0';

        int boxR = (row / 3) * 3;
        int boxC = (col / 3) * 3;

        if(check() || (nextR != -1 && (boxR != nextR || boxC != nextC) && who(nextR, nextC) == -1)) {
            cout << "Player " << (count%2 ? "two " : "one ") << "made an invalid move on turn " << count << ".\n";
            return;
        }

        int won = who(boxR, boxC);
        if(grid[row][col] != -1 || won != -1){
            cout << "Player " << (count%2 ? "two " : "one ") << "made an invalid move on turn " << count << ".\n";
            return;
        }


        nextR = (row % 3) * 3;
        nextC = (col % 3) * 3;
        grid[row][col] = count%2;
        MAIN[boxR/3][boxC/3] = who(boxR, boxC);
        count++;
    }

    cout << "All moves were valid." << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    while(n--) solve();
}