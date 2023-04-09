#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

long getMin(int* sodaPrices, int at, int numLiters){
    for (int j = 0; j <= numLiters; j++)
            map.put(new Point(sodaPrices.length, j), Long.MAX_VALUE);

        for (int i = sodaPrices.length - 1; i >= 0 ; i--) {
            for (int j = 1; j <= numLiters; j++)
                map.put(new Point(i, j), Math.min(sodaPrices[i] + (j - (1<<i) <= 0 ? 0 : map.get(new Point(i, j - (1<<i)))), map.get(new Point(i+1, j))));
        }

        return map.get(new Point(at, numLiters));
}

int main(){
    

    int numSodas;
    int numLiters;

    cin >> numSodas >> numLiters;
    int sodaPrices[numSodas];

    long arr[1000000];

    for (int i = 0; i < numSodas; i++)
        cin >> sodaPrices[i];

    cout << getMin(sodaPrices, 0, numLiters);
}