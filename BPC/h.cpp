#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string temp;
    getline(cin, temp);
    unordered_map<string, string> eqs;
    unordered_map<string, vector<string>> edges;
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        stringstream sin1(line);
        string defs;
        string info;
        getline(sin1, defs, '=');
        getline(sin1, info, '=');
        eqs[defs] = line;
        string s;
        for (int i = 0; i < info.size(); i++) {
            if (info[i] == '*' || info[i] == '/' || info[i] == '+' || info[i] == '-') {
                edges[s].push_back(defs);
                s.clear();
            } else {
                s += info[i];
            }
        }
        if (s.size()) {
            edges[s].push_back(defs);
        }
    }

    unordered_map<string, int> incomings;
    for (auto& [def, v] : edges) {
        if (eqs.find(def) == eqs.end()) continue;
        for (auto& x : v) {
            incomings[x]++;
        }
    }

    auto mySort = [](string& a, string& b) -> bool {
        return a > b;
    };

    priority_queue<string, vector<string>, decltype(mySort)> pq(mySort);
    for (auto& [s, _] : eqs)
        if (incomings[s] == 0) {
            pq.push(s);
        }

    int took = 0;
    vector<string> ans;
    while (pq.size()) {
        auto here = pq.top();
        pq.pop();
        if (eqs.find(here) != eqs.end()) {
            ans.push_back(eqs[here]);
            took++;
        }

        for (auto& x : edges[here]) {
            incomings[x]--;
            if (incomings[x] == 0) {
                pq.push(x);
            }
        }
    }

    if (took != n) {
        cout << "impossible\n";
        return 0;
    }

    for (auto x : ans) {
        cout << x << "\n";
    }
}