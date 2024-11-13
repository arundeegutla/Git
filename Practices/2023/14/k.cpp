#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;

    map<char, set<int>> ind;
    map<char, vector<int>> psums;
    for (auto& c : s)
        psums[c].resize(s.size());

    for (int i = 0; i < s.size(); i++) {
        ind[s[i]].insert(i);
        psums[s[i]][i]++;
    }

    for (auto& [k, arr] : psums)
        for (int i = 1; i < s.size(); i++)
            arr[i] += arr[i - 1];

    ll tot = 0;
    for (int i = 0; i < s.size(); i++) {
        auto itr = ind[s[i]].upper_bound(i);

        int nextInd = -1;
        if (itr == ind[s[i]].end())
            nextInd = s.size();
        else
            nextInd = *(itr);

        for (auto& [k, psum] : psums)
            tot += psum[nextInd - 1] - psum[i] > 0;
    }

    cout << tot << "\n";
}