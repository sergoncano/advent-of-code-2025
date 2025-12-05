//<>
#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define IN(type,name) type name; cin >> name
#define REP(var,first,last) for(ll var = first; var < last; var++)

vector<ll> ranges_up;
vector<ll> ranges_down;
vector<ll> fresh;

int main() {
    string s;
    int count = 0;
    REP(i, 0, 182){
        cin >> s;
        stringstream ss(s);
        string first_string;
        getline(ss, first_string, '-');
        cout << first_string << endl;
        ll first = stol(first_string);
        ranges_down.push_back(first);
        string second_string;
        getline(ss, second_string, '-');
        ll second = stol(second_string);
        ranges_up.push_back(second);
        cout << second << endl;
    }
    cin.ignore();
    ll i = 0;
    ll n;
     while(cin >> n){fresh.push_back(n);i++;}
    ll freshes = 0;
    REP(k,0,i) {
        bool isfresh = false;
        REP(j,0,182) {
            if(fresh.at(k) > ranges_down.at(j) && fresh.at(k) < ranges_up.at(j)) isfresh = true;
        }
        if(isfresh) freshes++;
    }
    cout << freshes;
}
