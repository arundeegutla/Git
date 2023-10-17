#include <bits/stdc++.h>
using namespace std;
#define long long long
int nextInt(){int a; cin >> a; return a;}
long nextLong(){long a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve(){
    while(true){    
        int n = nextInt();
        if(n == 0) return;
        vector<vector<double>> grid(26, vector<double>(26));
        
        while (n--) {
            int from = next()[0]-'A';
            int to = next()[0]-'A';
            double r = nextInt();
            if(!grid[from][to])
                grid[from][to] = grid[to][from] = r;
            else
                grid[from][to] = grid[to][from] = 1/((1/grid[from][to]) + (1/r));
        }

        while(true) {
            bool removed = false;
            for(int i = 0; i < 26; i++){
                for(int j = 1; j < 25; j++) {
                    if(!grid[i][j]) continue;

                    int other = -1;
                    for(int k = 0; k < 26; k++){
                        if(grid[j][k] && k != i) {
                            if(other == -1)other = k;
                            else {
                                other = -1;
                                break;
                            }
                        }
                    }

                    if(other == -1) continue;

                    double r = grid[i][j] + grid[j][other];

                    grid[i][j] = grid[j][i] = 0;
                    grid[j][other] = grid[other][j] = 0;

                    if(!grid[i][other])
                        grid[i][other] = grid[other][i] = r;
                    else
                        grid[i][other] = grid[other][i] = 1/((1/grid[i][other]) + (1/r)); 

                    removed = true;

                }
            }
            if(!removed) break;
        } 

        int count = 0;
        for(int i = 0; i < 26; i++)
            for(int j = i+1; j < 26; j++)
                if(grid[i][j])
                    count++;

        if(grid[0][25] && count == 1){
            cout << fixed << setprecision(3) << grid[0][25] << "\n";
        } else {
            cout << "-1.000" << "\n";
        }
        
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}
