#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
const double eps = 1e-6;

int x, y, r;
int sign;

const int MAXD = 1<<16;

int numQ = 0;
bool inBounds(int x) {
    return (0 <= x && x <= MAXN);
} 

int main() {
    double res = 0;

    // Find X coordinate
    x = 199;

    for (; x < MAXN; x+=199) {
        cout << "query " << x << " 0 " << x+1 << " " << MAXN << endl;
        numQ++;
        assert(numQ <= 1024);
        cin >> res;

        if (res > eps) {
            cout << "query " << x << " 0 " << x << " " << MAXN << endl;
            numQ++;
            assert(numQ <= 1024);
            double x1; cin >> x1;
            cout << "query " << x+1 << " 0 " << x+1 << " " << MAXN << endl;
            numQ++;
            assert(numQ <= 1024);
            double x2; cin >> x2;

            if (x1 < x2) {
                x = x+1;
                res = x2;
                sign = 1;
            }

            else {
                res = x1;
                sign = -1;
            }

            break;
        }
    }

    int delta = MAXD;

    while (delta) {
        int newx = x + sign*delta;

        if (inBounds(newx)) {
            cout << "query " << newx << " 0 " << newx << " " << MAXN << endl;
            numQ++;
            assert(numQ <= 1024);
            double newr; cin >> newr;

            if (abs(newr - res) <= eps) {
                x = (x + newx)/2;
                delta = 0;
            }

            else if (newr > res) {
                sign *= -1;
                x = newx;
            }
        }

        delta /= 2;
    }

    r = int(res + eps);

    // Find Y coordinate
    int x0 = x-(r/2);
    int x1 = x+(r/2);
    int y0 = 0;
    int lo = 0;
    int hi = MAXN;

    res = 0;

    while (hi-lo > 2) {
        int d = (hi-lo)/3;
        int m1 = lo+d;
        int m2 = hi-d;

        cout << "query " << x0 << " " << y0 << " " << x1 << " " << m1 << endl;
        numQ++;
        assert(numQ <= 1024);
        double r1; cin >> r1;
        cout << "query " << x0 << " " << y0 << " " << x1 << " " << m2 << endl;
        numQ++;
        assert(numQ <= 1024);
        double r2; cin >> r2;

        if (r1 >= r2) {
            hi = m2;
        }

        else {
            lo = m1;
        }
    }

    for (int i = lo; i <= hi; i++) {
        cout << "query " << x0 << " " << y0 << " " << x1 << " " << i << endl;
        numQ++;
        assert(numQ <= 1024);
        double seglen; cin >> seglen;
        if (seglen + eps >= res) {
            y = i/2;
            res = seglen;
        }
    }

    if (abs(r - res) <= eps) {
        cout << "answer " << x << " " << y << " " << (r/2) << endl;
        return 0;
    }

    y0 = MAXN;
    lo = 0;
    hi = MAXN;

    while (hi-lo > 2) {
        int d = (hi-lo)/3;
        int m1 = lo+d;
        int m2 = hi-d;

        cout << "query " << x0 << " " << y0 << " " << x1 << " " << m1 << endl;
        numQ++;
        assert(numQ <= 1024);
        double r1; cin >> r1;
        cout << "query " << x0 << " " << y0 << " " << x1 << " " << m2 << endl;
        numQ++;
        assert(numQ <= 1024);   
        double r2; cin >> r2;

        if (r1 > r2) {
            hi = m2;
        }

        else {
            lo = m1;
        }
    }

    for (int i = lo; i <= hi; i++) {
        cout << "query " << x0 << " " << y0 << " " << x1 << " " << i << endl;
        numQ++;
        assert(numQ <= 1024);
        double seglen; cin >> seglen;
        if (seglen + eps >= res) {
            y = y0-(i/2);
            res = seglen;
        }
    }

    cout << "answer " << x << " " << y << " " << (r/2) << endl;
}