#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    unordered_set<string> words;
    string start, end;
    cin >> start >> end;
    words.insert(start);
    words.insert(end);
    for (int i = 0; i + 2 < n; i++) {
        string s;
        cin >> s;
        words.insert(s);
    }

    queue<string> q;
    unordered_map<string, pair<int, string>> dist;
    q.push(start);
    dist[start] = {0, ""};

    while (q.size()) {
        auto w = q.front();
        q.pop();
        auto [dHere, stringTook] = dist[w];

        for (int i = 0; i < w.size(); i++) {
            for (char c = 'A'; c <= 'Z'; c++) {
                string w2 = w;
                w2[i] = c;
                // the newWord exists.
                if (words.count(w2)) {
                    if (!dist.count(w2) || dist[w2].first > dHere + 1 || (dist[w2].first == dHere + 1 && dist[w2].second > stringTook)) {
                        dist[w2] = {dHere + 1, stringTook};
                        q.push(w2);
                    }
                } else if (stringTook == "") {
                    if (!dist.count(w2) || dist[w2].first > dHere + 1 || (dist[w2].first == dHere + 1 && dist[w2].second > w2)) {
                        dist[w2] = {dHere + 1, w2};
                        q.push(w2);
                    }
                }
            }
        }
    }

    if (!dist.count(end)) {
        cout << 0 << "\n";
        cout << -1 << "\n";
        return 0;
    }

    if (dist[end].second == "") {
        cout << 0 << "\n";
    } else {
        cout << dist[end].second << "\n";
    }

    cout << dist[end].first << "\n";
}