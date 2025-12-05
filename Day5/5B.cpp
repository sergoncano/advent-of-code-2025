//<>
#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define IN(type,name) type name; cin >> name
#define REP(var,first,last) for(ll var = first; var < last; var++)

vector<pii> markers;

int main() {
    string s;
    ll count = 0;
    REP(i, 0, 182){
        cin >> s;
        stringstream ss(s);
        string first_string;
        getline(ss, first_string, '-');
        ll first = stol(first_string);
        string second_string;
        getline(ss, second_string, '-');
        ll second = stol(second_string);
        pii marker = pair(first, second);
        markers.push_back(marker);
    }
    sort(markers.begin(), markers.end());
    ll lastmarked = 0;
    REP(i, 0, markers.size()) {
        count += max(lastmarked, markers.at(i).second) - (max(markers.at(i).first-1, lastmarked)) ;
        lastmarked = max(markers.at(i).second, lastmarked);
        cout << "lastmarked: "<< lastmarked <<endl;
        cout << "first: "<< markers.at(i).first <<endl;
        cout << "last: "<< markers.at(i).second <<endl;
    }
    cout << count;
}
