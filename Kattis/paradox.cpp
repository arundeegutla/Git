#include <bits/stdc++.h>
using namespace std;

void solve(){
    int numcs, numeconomic; cin >> numcs >> numeconomic;
    vector<int> comps(numcs);
    vector<int> econs(numeconomic);
    for(auto& x : comps) cin >> x;
    for(auto& x : econs) cin >> x;

    double avgCS = 0;
    double avgEcon = 0;
    for(auto x : comps) avgCS += x;
    for(auto x : econs) avgEcon += x;
    avgCS /= numcs;
    avgEcon /= numeconomic;
    
    auto remove = [&](int num) -> double {
        double avg = avgCS*numcs;
        avg -= num;
        avg /= (numcs - 1);
        return avg;
    };

    auto add = [&](int num) -> double {
        double avg = avgEcon * numeconomic;
        avg += num;
        avg /= (numeconomic + 1);
        return avg;
    };

    int count = 0;
    for(auto x : comps)
        count += remove(x) > avgCS && add(x) > avgEcon;
    cout << count << "\n";
}

int main(){
    int n; cin >> n;
    while(n--) solve();
}
