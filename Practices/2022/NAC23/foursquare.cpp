#include <bits/stdc++.h>
using namespace std;
#define long long long
int nextInt() {int a;cin >> a;return a;}
string next(){string a; cin >> a;return a;}
long nextLong(){long a; cin >> a;return a;}

class Rectangle {
public:
    int h;
    int w;
    Rectangle(int h, int w){
        this->h = h;
        this->w = w;
    }
};

void solve() {

    vector<Rectangle> boxes;
    for(int i = 0; i < 4; i++)
        boxes.push_back(*(new Rectangle(nextInt(), nextInt())));

    

    vector<int> perm(4);
    vector<bool> used(4);


    cout << (int)go(0, 0, 0, go) << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}