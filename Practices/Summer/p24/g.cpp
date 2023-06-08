#include <bits/stdc++.h>
using namespace std;
#define ll long long
int nextInt(){int a; cin >> a; return a;}

class Meeting {
public:
    int start;
    int end;
    Meeting(int start, int end){
        this->start = start;
        this->end = end;
    }
    bool operator< (Meeting other) const {
        if(this->start == other.start)
            return this->end > other.end;
        return this->start > other.start;
    }
};

void solve(){
    priority_queue<Meeting> pq;
    while(true){
        int s = nextInt(), e = nextInt();
        if(s==0 && e == 0) break;
        pq.push(*(new Meeting(s, e)));
    }

    int count = 0;
    while(pq.size()){
        Meeting cur = pq.top(); pq.pop();
        bool add = true;
        while(pq.size()) {
            Meeting other = pq.top();
            if(other.start >= cur.end) break;

            if(other.end <= cur.end) {
                add = false; 
                break;
            }
            else pq.pop();
        }
        if(add) count++;
    }
    
    cout << count << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}