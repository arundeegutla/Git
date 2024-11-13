#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int d;
    cin >> d;

    for(int a = 1; a <= 100; a++){
        for(int b = 1; b <= 100; b++){
            for(int c = 1; c <= 100; c++){
                if(a == b || b == c || a == c) continue;

                if(a + b == d) continue; 
                if(a + c == d) continue; 
                if(b + c == d) continue; 

                if(a * b == d) continue; 
                if(a * c == d) continue; 
                if(b * c == d) continue; 

                if(a - b == d) continue; 
                if(a - b == d) continue; 
                if(a - c == d) continue; 
                if(b - c == d) continue; 

                

            }
        }
    }
}