#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string ans = s;

    int add = 0;
    for (int i = 0; i + 1 < n; i++) {
        if (s[i] == '(' && s[i + 1] == ')') {
            ans.insert(ans.begin() + i + add + 1, '1');
            add++;
        }
        if (s[i] == ')' && s[i + 1] == ')') {
            ans.insert(ans.begin() + i + add + 1, '1');
            ans.insert(ans.begin() + i + add + 1, '+');
            add++;
            add++;
        }
        if (s[i] == ')' && s[i + 1] == '(') {
            ans.insert(ans.begin() + i + add + 1, '*');
            add++;
        }
    }

    // cout << ans << "\n";

    vector<string> stk;
    for (auto c : ans) {
        // cout << c << "\n";

        if (c == ')') {
            int num = stoi(stk.back());
            stk.pop_back();
            bool mult = false;
            while (stk.size() && stk.back() != "(") {
                if (stk.back() == "*")
                    mult = true;
                else if (stk.back() == "+")
                    mult = false;
                else {
                    int x = stoi(stk.back());
                    if (mult)
                        num *= x;
                    else
                        num += x;
                }
                // cout << num << "\n";
                stk.pop_back();
            }
            if (stk.size() && stk.back() == "(") stk.pop_back();
            if (stk.size() && stk.back() == "*") {
                stk.pop_back();
                int x = stoi(stk.back());
                num *= x;
                stk.pop_back();
            }
            stk.push_back(to_string(num));
        } else {
            string x;
            x += c;
            stk.push_back(x);
        }
    }

    // cout << "here\n";

    int num = stoi(stk.back());
    stk.pop_back();
    bool mult = false;
    while (stk.size()) {
        if (stk.back() == "*")
            mult = true;
        else if (stk.back() == "+")
            mult = false;
        else {
            int x = stoi(stk.back());
            if (mult)
                num *= x;
            else
                num += x;
        }
    }
    cout << num << "\n";
}