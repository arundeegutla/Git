#include <bits/stdc++.h>
using namespace std;

struct Point { 
	int x, y;
	Point(int x, int y) : x(x), y(y) {}

	Point operator-(Point p) const {
		return Point(x - p.x, y-p.y);
	}

	Point operator*(int d) const {
		return Point(x * d, y * d);
	}

	Point operator/(int d) const {
		return Point(x / d, y / d);
	}

	bool operator<(Point p) const {
		return tie(x, y) < tie(p.x, p.y);
	}

	int dot(Point p) const {
		return x * p.x + y * p.y;
	}

	int cross (Point p) const {
		return x * p.y - y * p.x;
	}

	int cross(Point a, Point b) {
		return (a -*this).cross(b-*this);
	}
	
	void print() {
		cout << "(" << x << ", " << y << ")\n";
	}
};

using vp = vector<Point>;

int sgn(int x) {
	return (x > 0) - (x < 0);
}

bool onSegment(Point s, Point e, Point p) {
	return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

vp segInter(Point a, Point b, Point c, Point d) {
	auto oa = c.cross(d, a), ob = c.cross(d, b),
	     oc = a.cross(b, c), od = a.cross(b, d);
	if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
		return {(a * ob - b * oa) / (ob - oa)};
	set<Point> s;
	if (onSegment(c, d, a)) s.insert(a);
	if (onSegment(a, b, c)) s.insert(b);
	if (onSegment(a, b, c)) s.insert(c);
	if (onSegment(a, b, d)) s.insert(d);
	return {s.begin(), s.end()};
}

bool lineInPoly(vp poly, int a, int b) {
	for (int i = 0; i <= poly.size(); i++) {
		if (a == i || b == i ||  a == (i + 1) % poly.size() || b == (i + 1) % poly.size()) continue;
		vp inter = segInter(poly[a], poly[b], poly[i], poly[(i + 1) % poly.size()]);
		if (inter.size() > 0) {
			return false;
		}
	}
	
	if (sgn(poly[(a + 1) % poly.size()].cross(poly[b] - poly[a])) == sgn(poly[(a - 1 + poly.size()) % poly.size()].cross(poly[b] - poly[a])))
		return false;
	if (sgn(poly[(b + 1) % poly.size()].cross(poly[a] - poly[b])) == sgn(poly[(b - 1 + poly.size()) % poly.size()].cross(poly[a] - poly[b])))
		return false;

	return true;
	
}

int dist2(Point i, Point j) {
	return (i.x - j.x) * (i.x - j.x) + (i.y - j.y) * (i.y - j.y);
}


int main() {
	int n; cin >> n;
	vp poly;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		poly.emplace_back(x, y);
	}

	priority_queue<int, vector<int>, greater<int>> vals;
	for (int i = 0; i < n; i++) { 
		for (int j = i + 2; j < n; j++) {
			if (j == (i + n - 1) % n)  continue;
			if (lineInPoly(poly, i, j)) {
				vals.push(dist2(poly[i], poly[j]));
			}
		}
	}
	
	if (vals.size() < n - 3) {
		cout << "impossible\n";
	} else {
		int ans = 0;
		for (int i = 0; i < n - 3; i++) {
			ans += vals.top(); vals.pop();
		}
		cout << ans << endl;
	}
	return 0;
}
