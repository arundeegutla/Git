#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

void solve(){
    int n = 65;
    int row, col; cin >> col >> row;
    string commands; cin >> commands;

    vvi count(n, vi(n));

    count[row][col]++;
    int colDir = 0;
    int rowDir = 1;

    for(auto c : commands){
        if(c == 'F'){
            row += rowDir;
            col += colDir;
            count[row][col]++;
        }

        if(c == 'R'){
            if(rowDir == 1 && colDir == 0){
                rowDir = 0;
                colDir = 1;
            }
            else if(rowDir == -1 && colDir == 0){
                rowDir = 0;
                colDir = -1;
            }
            else if(rowDir == 0 && colDir == 1){
                rowDir = -1;
                colDir = 0;
            }
            else if(rowDir == 0 && colDir == -1){
                rowDir = 1;
                colDir = 0;
            }
        }

        if(c == 'L'){
            if(rowDir == 1 && colDir == 0){
                rowDir = 0;
                colDir = -1;
            }
            else if(rowDir == -1 && colDir == 0){
                rowDir = 0;
                colDir = 1;
            }
            else if(rowDir == 0 && colDir == 1){
                rowDir = 1;
                colDir = 0;
            }
            else if(rowDir == 0 && colDir == -1){
                rowDir = -1;
                colDir = 0;
            }
        }

    }

    int numNodes = 0;
    for(auto arr : count)
        for(auto node : arr)
            numNodes += node > 1;

    cout << col << " " << row << " " << numNodes << "\n";

}

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}