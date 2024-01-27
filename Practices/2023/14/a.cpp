#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> val(n);
    for (auto& x : val) {
        char c;
        cin >> c;
        x = c == 'T';
    }
    cin.ignore();
    vector<int> stack;
    string s;
    getline(cin, s);
    stringstream sin(s);

    char type;
    while (sin >> type) {
        if (type == '*') {
            int x = stack.back();
            stack.pop_back();
            int y = stack.back();
            stack.pop_back();
            stack.push_back(x & y);
        } else if (type == '+') {
            int x = stack.back();
            stack.pop_back();
            int y = stack.back();
            stack.pop_back();
            stack.push_back(x | y);
        } else if (type == '-') {
            int x = stack.back();
            stack.pop_back();
            stack.push_back(!x);
        } else {
            stack.push_back(val[type - 'A']);
        }
    }

    assert(stack.size() == 1);
    cout << (stack.back() == 1 ? 'T' : 'F') << "\n";
}