#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    int cases; cin >> cases;
    for (int c = 0; c < cases; c++)
    {
        int len, ops; cin >> len >> ops;
        string curr; cin >> curr;
        vector<int> big(26,0);
        vector<int> small(26,0);
        for (auto x: curr)
        {
            if (x < 'a')
                big[x-'A']++;
            else
                small[x-'a']++;
        }

        ll sum = 0;
        for (int i = 0; i < 26; i++)
        {
            while (big[i] > 0&& small[i] >0)
            {
                // cout << 1 << endl;
                sum++;
                big[i]--;
                small[i]--;
            }
            while (ops > 0 && big[i] >= 2)
            {
                // cout << 2 << endl;
                ops--;
                sum++;
                big[i]-=2;
            }
            while (ops > 0 && small[i] >= 2)
            {
                // cout << 3 << endl;
                ops--;
                sum++;
                small[i]-=2;
            }
        }
        cout << sum << endl;
    }
    
}
