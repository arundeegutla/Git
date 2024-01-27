#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    int a;
    cin >> a;

    using Person = pair<ll, string>;
    auto comp = [](Person& a, Person& b) -> bool {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    };
    unordered_set<string> fired;
    unordered_map<string, ll> salary;
    priority_queue<Person, vector<Person>, decltype(comp)> pq(comp);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ll sal;
        cin >> sal;
        salary[s] = sal;
        pq.push({sal, s});
    }

    while (a--) {
        int type;
        cin >> type;
        if (type == 1) {
            string s;
            cin >> s;
            ll r;
            cin >> r;
            salary[s] += r;
            pq.push({salary[s], s});
        } else {
            while (fired.find(pq.top().second) != fired.end()) {
                pq.pop();
            }
            auto f = pq.top();
            pq.pop();
            fired.insert(f.second);
            cout << f.second << " " << f.first << "\n";
        }
    }
}