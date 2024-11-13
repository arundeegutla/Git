#include <bits/stdc++.h>
using namespace std;

string s;
set<char> vowels;

int solve() {
    vector<int> v;
    int n = int(s.length());

    // Insert index of each vowel into v (from left to right)
    for (int i = 0; i < n; i++) 
        if (vowels.count(s[i]))
            v.push_back(i);
    
    // If there are no vowels, there are no reversals.
    if (v.empty()) 
        return 1;

    // At least 1 vowel and first letter not vowel is impossible.
    if (!vowels.count(s[0]))
        return 0;

    // Possible to insert the vowel at any point
    if (v.size() == 1)
        return n;

    // Num ways = length of substring btw 2 middle vowels
    // (I picture this as unraveling the string until
    // getting to the first vowel)
    int sz = int(v.size());
    return (v[((sz-1)/2)+1] - v[(sz-1)/2]);
}

int main() {
    // Vowels contains set of all vowels
    vowels.insert('a');
    vowels.insert('e');
    vowels.insert('i');    
    vowels.insert('o');
    vowels.insert('u');
    
    cin >> s;
    cout << solve() << endl;
}