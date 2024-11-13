#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
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

    queue<pair<int, string>> q;
    unordered_map<string, int> dist;
    unordered_map<string, pair<int, string>> distString;
    q.push({0, start});
    q.push({1, start});
    dist[start] = 0;
    distString[start] = {0, ""};

    while (q.size()) {
        auto [t, w] = q.front();
        q.pop();
        if (t == 0) {
            auto dHere = dist[w];
            for (int i = 0; i < w.size(); i++) {
                string w2 = w;
                for (char c = 'A'; c <= 'Z'; c++) {
                    char t = w2[i];
                    w2[i] = c;
                    if (words.count(w2)) {
                        if (!dist.count(w2) || dist[w2] > dHere + 1) {
                            dist[w2] = dHere + 1;
                            q.push({0, w2});
                        }
                    } else if (!distString.count(w2) || distString[w2].first > dHere + 1 || (distString[w2].first == dHere + 1 && distString[w2].second > w2)) {
                        distString[w2] = {dHere + 1, w2};
                        q.push({1, w2});
                    }
                    w2[i] = t;
                }
            }
        } else {
            auto [dHere, stringTook] = distString[w];
            for (int i = 0; i < w.size(); i++) {
                string w2 = w;
                for (char c = 'A'; c <= 'Z'; c++) {
                    char t = w2[i];
                    w2[i] = c;
                    if (words.count(w2)) {
                        if (!distString.count(w2) || distString[w2].first > dHere + 1 || (distString[w2].first == dHere + 1 && distString[w2].second > stringTook)) {
                            distString[w2] = {dHere + 1, stringTook};
                            q.push({1, w2});
                        }
                    }
                    w2[i] = t;
                }
            }
        }
    }

    if (!dist.count(end) && !distString.count(end)) {
        cout << 0 << "\n";
        cout << -1 << "\n";
        return 0;
    }

    if (!distString.count(end) && dist.count(end)) {
        cout << 0 << "\n";
        cout << dist[end] << "\n";
        return 0;
    }

    if (distString.count(end) && !dist.count(end)) {
        cout << distString[end].second << "\n";
        cout << distString[end].first << "\n";
        return 0;
    }

    if (distString.count(end) && dist.count(end)) {
        if (dist[end] <= distString[end].first) {
            cout << 0 << "\n";
            cout << dist[end] << "\n";
        } else {
            cout << distString[end].second << "\n";
            cout << distString[end].first << "\n";
        }
        return 0;
    }
}