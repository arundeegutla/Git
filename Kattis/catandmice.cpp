#include <bits/stdc++.h>
using namespace std;
#define ll long long
int nextInt() {int a;cin >> a;return a;}
ll nextLong(){ll a; cin >> a;return a;}
double nextDouble(){double a; cin >> a;return a;}
string next(){string a; cin >> a;return a;}

class Mouse {
public:
    int x, y, s;
    Mouse(int x, int y, int s){
        this->x = x;
        this->y = y;
        this->s = s;
    }
    double distance(Mouse pt) {
        double px = pt.x - x;
        double py = pt.y - y;
        return sqrt(px * px + py * py);
    }
};


void solve() {
    int n = nextInt();
    vector<Mouse> mouses;
    for(int i = 0; i < n; i++)
        mouses.push_back(*(new Mouse(nextInt(), nextInt(), nextInt())));
    double m = nextDouble();

    auto tspHelper = [&](int current, int visited, double initial, vector<vector<double>>& memo, auto && tspHelper) -> double {
        if (memo[current][visited] != -1)
            return memo[current][visited];

        if (visited == ((1<<n) - 1)) {
            double dist = mouses[current].distance(*(new Mouse(0, 0, 0)));
            double time = dist/initial;
            return time <= mouses[current].s ? time : 1e9;
        }
    
        int numtovisited = n - bitset<32>(visited).count();
        double neg = pow(m, numtovisited);
        double curVel = initial * neg;

        double minTime = 1e9;
        for (int i = 0; i < n; i++) {
            if ((visited & (1<<i)) == 0) {
                double dist = mouses[current].distance(mouses[i]);
                double time = dist/curVel;
                double curtime = tspHelper(i, visited | (1<<i), initial, memo, tspHelper) + time;
                minTime = min(minTime, curtime<=mouses[current].s ? curtime : 1e9);
            }
        }

        return memo[current][visited] = minTime;
    };

    auto tsp = [&](double initial) -> bool {
        vector<vector<double>> memo(n, vector<double>(1<<n, -1));
        for (int i = 0; i < n; i++) 
            if (tspHelper(i, 1<<i, initial, memo, tspHelper) <= mouses[i].s)
                return true;
        return false;
    };

    double lo = 0;
    double high = 100000000;

    while (high-lo > 0.00001) {
        double mid = (lo+high)/2;
        if (tsp(mid)) high = mid;
        else lo = mid;
    }

    cout << high << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}