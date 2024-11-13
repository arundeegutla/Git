#include <bits/stdc++.h>
using namespace std;

int R, K;
string s;
int N;

char calcCell(int value) {
    return (((1 << value) & R) ? 'X' : '.');
}

string solve() {
    string res = s;

    int value = 0;

    if (s[0] == 'X')
        value += 2;
    if (s[1] == 'X')
        value++;

    res[0] = calcCell(value);

    for (int i = 1; i < N - 1; i++) {
        value = 0;
        for (int j = -1; j <= 1; j++) {
            value += ((s[i + j] == 'X') ? (1 << 1 - j) : 0);
        }
        res[i] = calcCell(value);
    }

    value = 0;

    if (s[N - 2] == 'X')
        value += 4;
    if (s[N - 1] == 'X')
        value += 2;

    res[N - 1] = calcCell(value);

    return res;
}

int main() {
    cin >> R >> K;
    cin >> s;
    N = int(s.length());

    for (int k = 1; k <= K; k++) {
        s = solve();
        cout << s << endl;
    }
}