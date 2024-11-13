#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define all(x) begin(x), end(x)

void solve() {
    int n = nextInt();
    vector<vector<bool>> relation(5, vector<bool>(5));

    while(n--){
        int from = nextInt() - 1;
        int to = nextInt() - 1;
        relation[from][to] = true;
        relation[to][from] = true;
    }

    for(int i = 0; i < 5; i++)
        for(int j = i+1; j < 5; j++)
            for(int k = j+1; k < 5; k++){
                if(relation[i][j] == relation[j][k] && relation[j][k] == relation[i][k]) {
                    cout << "Happy Doggos!\n";
                    return;
                }
            }
    cout << "Sad Doggos...\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}