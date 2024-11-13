#include <bits/stdc++.h>
using namespace std;

int main() {
    char last;
    int n;
    cin >> last >> n;

    vector<string> arr(n);
    for (auto& x : arr) cin >> x;

    int lastNum = last - 'a' + 1;
    vector<vector<int>> next(lastNum);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            if (arr[i - 1].size() <= j) break;
            string prev = arr[i - 1].substr(0, j);
            string cur = arr[i].substr(0, j);
            if (prev == cur && arr[i - 1][j] != arr[i][j])
                next[arr[i - 1][j] - 'a'].push_back(arr[i][j] - 'a');
        }

        // prev is big
        if (arr[i - 1].size() > arr[i].size()) {
            int x = arr[i].size();
            string prev = arr[i - 1].substr(0, x);
            if (prev == arr[i]) {
                cout << 1 << "\n";
                return 0;
            }
        }
    }

    vector<int> incoming(lastNum);
    for (auto& x : next)
        for (auto& y : x)
            incoming[y]++;

    queue<int> q;
    for (int i = 0; i < lastNum; i++) {
        if (incoming[i] == 0) {
            if (q.size()) {
                cout << 0 << "\n";
                return 0;
            }
            q.push(i);
        }
    }

    if (!q.size()) {
        cout << 1 << "\n";
        return 0;
    }

    string s;
    bool inconsistent = false;
    while (q.size()) {
        int here = q.front();
        q.pop();
        s += here + 'a';
        for (auto& x : next[here]) {
            incoming[x]--;
            if (incoming[x] == 0)
                q.push(x);
            assert(incoming[here] >= 0);
        }
        if (q.size() > 1) {
            cout << 0 << "\n";
            return 0;
        }
    }

    for (auto x : incoming)
        inconsistent |= x != 0;

    if (inconsistent) {
        cout << 1 << "\n";
        return 0;
    }

    cout << s << "\n";
}