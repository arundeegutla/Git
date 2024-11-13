#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> arr;
    for (int i = 1; i <= 5e8; i++) {
        string s = to_string(i);
        string rev = s;
        reverse(rev.begin(), rev.end());
        if (s == rev) {
            arr.push_back(i);
        }
    }

    vector<vector<int>> base(10);

    for (auto x : arr) {
        for (int b = 2; b <= 9; b++) {
            if (base[b].size() == 30) continue;
            int num = x;
            string s;
            while (num > 0) {
                s = to_string(num % b) + s;
                num /= b;
            }
            string rev = s;
            reverse(rev.begin(), rev.end());
            if (rev == s) {
                base[b].push_back(x);
            }
        }
    }

    for (auto arr : base) {
        cout << arr.size() << ":\n";
        for (auto x : arr) {
            cout << x << " ";
        }
        cout << "\n";
    }
}