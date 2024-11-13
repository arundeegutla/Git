#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <class T>
int sgn(T x) { return (x > 0) - (x < 0); }
template <class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
    bool operator<(P p) const {
        return tie(x, y) < tie(p.x, p.y);
    }
    bool operator==(P p) const {
        return tie(x, y) == tie(p.x, p.y);
    }
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(T d) const { return P(x * d, y * d); }
    P operator/(T d) const { return P(x / d, y / d); }
    T dot(P p) const { return x * p.x + y * p.y; }
    T cross(P p) const { return x * p.y - y * p.x; }
    T cross(P a, P b) const {
        return (a - *this).cross(b - *this);
    }
    T dist2() const { return x * x + y * y; }
    double dist() const { return sqrt((double)dist2()); }
    // angle to x-axis in interval [-pi, pi]
    double angle() const { return atan2(y, x); }
    P unit() const { return *this / dist(); }  // makes dist()=1
    P perp() const { return P(-y, x); }        // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated 'a' radians ccw around the origin
    P rotate(double a) const {
        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")";
    }
};

typedef Point<ll> P;
vector<P> convexHull(vector<P> pts) {
    if (pts.size() <= 1) return pts;
    sort(begin(pts), end(pts));
    vector<P> h(pts.size() + 1);
    int s = 0, t = 0;
    for (int it = 2; it--; s = --t, reverse(begin(pts), end(pts)))
        for (P p : pts) {
            while (t >= s + 2 && h[t - 2].cross(h[t - 1], p) <= 0)
                t--;
            h[t++] = p;
        }
    return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

int main() {
    int p;
    cin >> p;

    for (int tc = 1; tc <= p; tc++) {
        int t;
        cin >> t;

        int n;
        cin >> n;

        vector<Point<ll>> pts;
        while (n--) {
            int x, y;
            cin >> x >> y;
            Point<ll> p;
            p.x = x;
            p.y = y;
            pts.push_back(p);
        }

        auto hull = convexHull(pts);

        int ind = -1;
        ll lowX = LLONG_MAX;
        ll maxxY = LLONG_MIN;
        for (int i = 0; i < hull.size(); i++) {
            if (hull[i].y == maxxY) {
                if (lowX > hull[i].x) {
                    ind = i;
                    lowX = hull[i].x;
                }
            }
            if (hull[i].y > maxxY) {
                maxxY = max(maxxY, hull[i].y);
                ind = i;
                lowX = hull[i].x;
            }
        }

        // cout << "FDFSDF " << hull[ind].x << " " << hull[ind].y << "\n";

        rotate(hull.begin(), hull.end() - (hull.size() - 1 - ind), hull.end());
        reverse(hull.begin(), hull.end());

        cout << t << " " << hull.size() << "\n";
        for (auto [x, y] : hull) {
            cout << x << " " << y << "\n";
        }
    }
}