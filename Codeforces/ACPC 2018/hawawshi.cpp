#include <iostream>
#include <fstream>
using namespace std;

int gcd(int a, int b)
{
    while (b != 0) {
        int temp = a;
        a = b;
        b = temp%b;
    }
    return a;
}

int dp[100005];

int generateSequence(int a, int b, int p, int x, int n) {
    int rn = x;
    int count = 0;

    for (int j = 1; j <= n % p; j++) {
        if (rn == x) count++;
        rn = (a*rn + b) % p;
    }
    if(n >= p) return (n/p)*dp[p-1] + count;
    else return count;
}

int main() {
    ifstream in("hawawshi.in");

    int numCases;
    in >> numCases;

    while (numCases-- > 0) {
        int n, x, A, B, a, b, p;
        in >> n >> x >> A >> B >> a >> b >> p;

        for (int i = 0; i < p; i++) {
            if (generateSequence(a, b, p, x, i) == i) dp[i] = 1;
            else dp[i] = 0;
        }

        for (int i = 1; i < p; i++)
            dp[i] += dp[i-1];

        for (int i = 0; i < n; i++) {
            int bottom = (B-A+1);
            int count = 0;
            for (int j = A; j <= B; j++)
                count += generateSequence(a, b, p, j, n);

            int gcd_ab = gcd(count, bottom);

            cout << count/gcd_ab << "/" << bottom/gcd_ab << endl;
        }
    }

    return 0;
}

