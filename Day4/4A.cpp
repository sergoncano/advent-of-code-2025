//<>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;
#define IN(type,name) type name; cin >> name
#define REP(var,first,last) for(ll var = first; var < last; var++)

vector<vector<char>> rolls;
ll vsize = 0;
ll hsize = 0;
bool hasRoll(ll i, ll j) {
    if(i<0 || j < 0 || i >= vsize || j >= hsize) return false;
    else {
        if(rolls.at(i).at(j)=='@') return true;
        else return false;
    }
}

ll adjacentRolls(ll i, ll j) {
    ll count = 0;
    if(hasRoll(i+1, j)) count++;
    if(hasRoll(i, j+1)) count++;
    if(hasRoll(i-1, j)) count++;
    if(hasRoll(i, j-1)) count++;
    if(hasRoll(i+1, j+1)) count++;
    if(hasRoll(i-1, j-1)) count++;
    if(hasRoll(i+1, j-1)) count++;
    if(hasRoll(i-1, j+1)) count++;
    return count;
}

int main() {
    string s;
    while(cin >> s) {
        rolls.push_back(vector<char>(0));
        REP(i,0,s.length()) rolls.at(vsize).push_back(s[i]);
        hsize = s.length();
        vsize++;
    }
    ll count = 0;
    REP(i, 0, vsize) {
        REP(j,0,hsize) {
            if (rolls.at(i).at(j)=='@' && adjacentRolls(i, j)<4) {
                count++;
                cout << 'X';
            } else 
                cout << rolls.at(i).at(j);
        }
        cout << endl;
    }
    cout << count;
}
