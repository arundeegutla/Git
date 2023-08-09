#include <bits/stdc++.h>
using namespace std;
#define long long long
#define ArrayList vector
#define Boolean bool
#define Integer int
#define add insert
#define HashSet unordered_set
#define contains unordered_set

int nextInt(){int a; cin >> a; return a;}
long nextLong(){long a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

int main(){
    int n = nextInt();
    int maxx = 10000;
    ArrayList<Boolean> primes(maxx+1, true);
    primes[1] = false;
    for(int i = 2; i*i <= maxx; i++)
        if(primes[i])
            for(int j = i*i; j <= maxx; j+=i)
                primes[j] = false;

    auto solve = [&](int num) -> bool{
        if(!primes[num]) return false;

        HashSet<Integer> hset;
        while(num != 1 && hset.find(num) == hset.end()){
            hset.add(num);
            int newNum = 0;
            while(num > 0){
                newNum += (num%10) * (num%10);
                num /= 10;
            }
            num = newNum;
        }
        
        return num == 1;
    };

    while(n--) {
        int k = nextInt();
        int num = nextInt();
        cout << k << " " << num << (solve(num) ? " YES" : " NO") << "\n";
    }
}
