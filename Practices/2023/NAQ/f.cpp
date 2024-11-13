#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    unordered_set<char> vowels;
    vowels.insert('a');
    vowels.insert('e');
    vowels.insert('i');
    vowels.insert('o');
    vowels.insert('u');
    vowels.insert('y');

    int v1 = 0;
    int v2 = 0;
    for (auto c : s) {
        if (vowels.find(c) != vowels.end()) {
            if (c != 'y') {
                v1++;
            }
            v2++;
        }
    }
    cout << v1 << " " << v2 << "\n";
}