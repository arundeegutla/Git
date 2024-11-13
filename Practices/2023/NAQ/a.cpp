#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, c;
    cin >> n >> k >> c;

    vector<pair<int, pair<int, int>>> teams(n);
    for (int i = 0; i < n; i++) {
        int rank = i;
        int id, s;
        cin >> id >> s;
        teams[i].first = rank;
        teams[i].second.first = id;
        teams[i].second.second = s;
    }

    unordered_map<int, int> school;

    int took = 0;
    queue<pair<int, pair<int, int>>> reached;
    vector<int> rank;

    vector<pair<int, int>> qual;
    for (auto& team : teams) {
        if (took == k) break;
        int rank = team.first;
        int id = team.second.first;
        int s = team.second.second;
        if (school[s] == c) {
            reached.push({rank, {id, s}});
        } else {
            school[s]++;
            took++;
            qual.push_back({rank, id});
        }
    }

    while (took < k) {
        took++;
        qual.push_back({reached.front().first, reached.front().second.first});
        reached.pop();
    }

    sort(qual.begin(), qual.end());

    for (auto& x : qual) {
        cout << x.second << "\n";
    }
}