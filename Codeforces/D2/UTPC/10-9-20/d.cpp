#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define all(x) begin(x), end(x)

void solve() {
    int n = nextInt();
    vector<string> month = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    double maxx = -1;
    string ans;
    getline(cin, ans);
    string t;
    while(n--){
        string name;
        getline(cin, name);
        string m = next();
        int mm = 0;
        for(int i = 0; i < month.size(); i++)
            if(month[i] == m)
                mm = i;
        string date = next();
        int year = nextInt();
        double rate; cin >> rate;
        getline(cin, t);

        if(year > 1928 || (year == 1928 && mm > 6) || (year == 1928 && mm == 6 && stoi(date) >= 7)){
            if(maxx < rate) {
                maxx = rate;
                ans = name;
            }
        }
    }

    cout << ans << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}