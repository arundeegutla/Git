#include <iostream>
#include <vector>
using namespace std;

int main(){
    int numCase;
    cin >> numCase;
    
    while (numCase-- > 0)
    {
        cin.ignore();
        int numTeams;
        cin >> numTeams;

        vector<int> teams(numTeams);
        for(int i = 0; i < numTeams; i++) {
            string name;
            cin >> name >> teams[i];
        }

        sort(teams.begin(), teams.end());

        int diff = 0;
        for(int i = 0; i < teams.size(); i++)
            diff += abs((i+1) - teams[i]);
        
        cout << diff << endl;
    }
    
    
}