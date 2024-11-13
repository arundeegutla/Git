#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int students, brownies;
        cin >> students >> brownies;
        int m;
        cin >> m;

        cout << "Practice #" << i << ": " << students << " " << brownies << "\n";
        while (m--) {
            int numStudents;
            cin >> numStudents;

            while (brownies <= numStudents) {
                brownies *= 2;
            }
            brownies -= numStudents;
            cout << numStudents << " " << brownies << "\n";
        }
        cout << "\n";
    }
}