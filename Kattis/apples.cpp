#include <bits/stdc++.h>
using namespace std;
#define long long long
int nextInt() {int a;cin>>a;return a;}
string next(){string a;cin>>a;return a;}
long nextLong(){long a;cin>>a;return a;}

void solve() {
    int r = nextInt(), c = nextInt();
    vector<string> grid(r);
    for(auto& x : grid)
        x = next();
    
    auto drop = [&](int column) {
        int dropRow = r-1;
        for(int row = r-1; row >= 0; row--){
            if(grid[row][column] == 'a'){
                grid[row][column] = '.';
                grid[dropRow][column] = 'a';
                dropRow--;
            }
            if(grid[row][column] == '#')
                dropRow = row-1;
        }
    };

    for(int i = 0; i < c; i++)
        drop(i);
    
    for(auto x : grid)
        cout << x << "\n";
}

int main(){
    solve();
}