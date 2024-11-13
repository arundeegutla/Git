#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    string s;
    cin >> s;

    vector<vector<string>> memo(s.size(), vector<string>(s.size(), "-1"));
    function<string(int, int)> go = [&](int l, int r) -> string {
        if(l == r) {
            string x;
            x += s[l];
            return x;
        }
        auto& ans = memo[l][r];
        if(ans != "-1") {
            // cout << "memo!\n";
            return ans;
        }
        string bL = s.substr(l, r - l + 1);
        for(int i = l; i < r; i++) {
            string next = s.substr(l, i - l + 1) + go(i + 1, r);
            if(bL.size() > next.size()) {
                bL = next;
            } 
        }
        string bR = s.substr(l, r - l + 1);
        for(int i = r; i > l; i--) {
            string next = go(l, i - 1) + s.substr(i, r - i + 1);
            if(bR.size() > next.size()) {
                bR = next;
            } 
        }
        string divide = s.substr(l, r - l + 1);
        for(int i = l; i < r; i++) {
            string next = go(l, i) + go(i + 1, r);
            if(divide.size() > next.size()) {
                divide = next;
            } 
        }
        
        int n = r - l + 1;
        string bestSplit = s.substr(l, n);
        for(int split = 9; split >= 2; split--) {
            if((n % split) != 0) continue;
            bool works = true;
            for(int i = 0; i < n / split; i++) {
                char check = s[l + i];
                for(int j = l + i; j <= r; j += n / split) {
                    if(s[j] != check) {
                        works = false;
                        break;
                    }
                }
                if(!works) break; 
            }
            if(!works) continue;
            
        
            string next = to_string(split);
            next += "(";
            next += go(l, l + (n / split) - 1);
            next += ")";
        
            if(bestSplit.size() > next.size()) {
                bestSplit = next;
            }
        }

        int minLen = min({bL.size(), bR.size(), divide.size(), bestSplit.size()});

        if(bL.size() == minLen) {
            return ans = bL;
        } else if(bR.size() == minLen) {
            return ans = bR;
        } else if(divide.size() == minLen)
            return ans = divide;
        
        return ans = bestSplit;
    };

    cout << go(0, s.size() - 1) << "\n";
}