#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, s;
    cin >> a >> s;

    unordered_map<char, int> ord;
    for (auto c : a) {
        ord[c] = ord.size();
    }

    set<string> hset;
    for (int i = 0; i < s.size(); i++) {
        string temp = s;
        temp.erase(temp.begin() + i);
        hset.insert(temp);

        for (auto c : a) {
            temp = s;
            temp.insert(temp.begin() + i, c);
            hset.insert(temp);

            temp = s;
            temp[i] = c;
            hset.insert(temp);
        }
        for (auto c : a) {
            string temp = s;
            temp.push_back(c);
            hset.insert(temp);
        }
    }

    hset.erase(s);
    vector<string> ans(hset.begin(), hset.end());

    auto mySort = [&](string& a, string& b) -> bool {
        int minn = min(a.size(), b.size());
        for (int i = 0; i < minn; i++) {
            if (ord[a[i]] < ord[b[i]]) {
                return true;
            } else if (ord[a[i]] > ord[b[i]]) {
                return false;
            }
        }
        return a.size() < b.size();
    };

    sort(ans.begin(), ans.end(), mySort);

    for (auto s : ans) {
        cout << s << "\n";
    }
}