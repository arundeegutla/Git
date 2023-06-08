#include <bits/stdc++.h>
using namespace std;
#define long long long 

class Alien {
public:
    int startTime;
    int shootingTime;
    int dist;
};

class Compare {
    public:
       bool operator()(Alien& a, Alien& b){
           if(a.shootingTime == b.shootingTime)
                return a.startTime > b.startTime;
            return a.shootingTime > b.shootingTime;
      }
};

long solve(){
    int n; cin>>n;


    priority_queue<Alien, vector<Alien>, Compare> aliens;
    for(int i = 0; i < n; i++){
        Alien newAlien;
        cin >> newAlien.startTime >> newAlien.shootingTime >> newAlien.dist;
        aliens.push(newAlien);
    }

    int curTime = 0;
    long cells = 0;

    

    while(!aliens.empty()){
        Alien cur = aliens.top(); aliens.pop();
        if(curTime >= cur.startTime) continue;
        curTime = cur.shootingTime;
        cells += cur.dist;
    }

    return cells;
}

int main(){
    int n;
    cin>>n;
    while(n--)
        cout << solve() << "\n";
}