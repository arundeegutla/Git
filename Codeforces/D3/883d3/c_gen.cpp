#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << "1\n";
    cout << "2 100000 1000000\n";
    for(int i = 0; i < 100000; i++)
        cout << "4" << (i==(100000-1) ? "\n" : " ");

    for(int i = 0; i < 100000; i++)
        cout << "1" << (i==(100000-1) ? "\n" : " ");
}