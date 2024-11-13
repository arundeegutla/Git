#include <bits/stdc++.h>
using namespace std;

const int MAXL = 1e3;
const int MAXN = 1e3;

int n;
string s;
bool dp[MAXL][MAXN] = {false};

vector<char> v; // Current string being tested

// go(index, remainder)
bool go(int i, int r) {
    // Number which satisfies 's' has been generated
    if (i == s.length()) {
        // Solution has been found
        if (r == 0) {
            cout << string(v.begin(), v.end()) << endl;
            exit(0); // Terminate program immediately
        }

        // Continue searching other numbers
        else
            return true;
    }

    // Already visited and leads to dead end
    if (dp[i][r])
        return true;

    // Current digit is not fixed
    if (s[i] == '?') {
        // Try all digits in order
        for (int x = 0; x < 10; x++) {
            int rr = (10*r + x) % n; // Calc new remainder
            if (!dp[i+1][rr]) { // Unvisited state
                v.push_back(char('0'+x)); // Add new digit to possible soln string
                go(i+1, rr); // Search
                v.pop_back(); // Remove same digit from soln string
            }
        }
    }

    // Current digit is fixed (similar logic as above)
    else {
        int rr = (10*r+(s[i]-'0'))%n;
        v.push_back(s[i]);
        go(i+1, rr);
        v.pop_back();
    }

    // Mark as visited
    return (dp[i][r] = true);
}

void solve() {
    // Leading digit isn't fixed
    if (s[0] == '?') {
        for (int i = 1; i < 10; i++) {
            v.push_back(char('0'+i));
            go(1, i%n);
            v.pop_back();
        }
    }

    // Fixed
    else {
        v.push_back(s[0]);
        go(1, (s[0]-'0')%n);
        v.pop_back();
    }

    // No solution
    cout << "*" << endl;
}

int main() {
    cin >> s >> n;
    solve();
}