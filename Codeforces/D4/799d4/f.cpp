#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt();
    vector<int> arr(n);
    for(auto& x : arr) x = nextInt();

    map<int, int> freq;
    for(auto x : arr)
        freq[x%10]++;
    
    for(int i = 0; i < 10; i++){
        if(!freq[i]) continue;
        for(int j = 0; j < 10; j++){
            if(!freq[j]) continue;
            for(int k = 0; k < 10; k++){
                if(!freq[k]) continue;
                if(i==j && j==k && freq[i] < 3) continue;
                if(i==j && freq[i] < 2) continue;
                if(k==j && freq[j] < 2) continue;
                if(k==i && freq[i] < 2) continue;
                
                int sum = i + j + k;
                if((sum%10) == 3){
                    cout << "YES\n";
                    return;
                }
            }
        }
    }

    cout << "NO\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}