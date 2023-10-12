#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    ll x;
    cin >> x;

    vector<string> tens = {"", "thousand", "million", "billion", "trillion", "quadrillion", "quintillion"};

    vector<string> s;
    int at = 0;
    while(x > 0) {
        ll cur = x % 1000;
        x /= 1000;

        if(cur != 0) s.insert(s.begin(), tens[at]);
        
        int count = 0;
        while(cur > 0){
            int num = cur%10;
            cur /= 10;
            if(num == 0){
                count++;
                continue;
            } 

            if(count == 0) {
                if(num == 1) {
                    s.insert(s.begin(),"one");
                }
                if(num == 2) {
                    s.insert(s.begin(),"two");
                }
                if(num == 3) {
                    s.insert(s.begin(),"three");
                }
                if(num == 4) {
                    s.insert(s.begin(),"four");
                }
                if(num == 5) {
                    s.insert(s.begin(),"five");
                }
                if(num == 6) {
                    s.insert(s.begin(),"six");
                }
                if(num == 7) {
                    s.insert(s.begin(),"seven");
                }
                if(num == 8) {
                    s.insert(s.begin(),"eight");
                }
                if(num == 9) {
                    s.insert(s.begin(),"nine");
                }
            }

            if(count == 1) {
                if(num == 2) {
                    s.insert(s.begin(),"twenty");
                }
                if(num == 3) {
                    s.insert(s.begin(),"thirty");
                }
                if(num == 4) {
                    s.insert(s.begin(),"forty");
                }
                if(num == 5) {
                    s.insert(s.begin(),"fifty");
                }
                if(num == 6) {
                    s.insert(s.begin(),"sixty");
                }
                if(num == 7) {
                    s.insert(s.begin(),"seventy");
                }
                if(num == 8) {
                    s.insert(s.begin(),"eighty");
                }
                if(num == 9) {
                    s.insert(s.begin(),"ninety");
                }
            }

            if(count == 2) {
                if(num == 1) {
                    s.insert(s.begin(),"one hundred");
                }
                if(num == 2) {
                    s.insert(s.begin(),"two hundred");
                }
                if(num == 3) {
                    s.insert(s.begin(),"three hundred");
                }
                if(num == 4) {
                    s.insert(s.begin(),"four hundred");
                }
                if(num == 5) {
                    s.insert(s.begin(),"five hundred");
                }
                if(num == 6) {
                    s.insert(s.begin(),"six hundred");
                }
                if(num == 7) {
                    s.insert(s.begin(),"seven hundred");
                }
                if(num == 8) {
                    s.insert(s.begin(),"eight hundred");
                }
                if(num == 9) {
                    s.insert(s.begin(),"nine hundred");
                }
            }

            count++;
        }
        at++;
    }

    for(auto x : s) {
        cout << x << " ";
    }
    cout << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    while(n--){
        solve();
    }
}