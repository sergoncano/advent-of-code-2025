//<>
#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;
#define IN(type,name) type name; cin >> name
#define REP(var,first,last) for(ll var = first; var < last; var++)

int main() {
    ll count = 0;
    set<ll> currentx;
        IN(string,line);
    REP(x,0,line.size()) {if(line[x]=='S') currentx.insert(x); }
    while(cin>> line) {
        set<ll> toerase;
        set<ll> toadd;
        for(auto x : currentx) {
            if(line[x]=='^') {
            cout << x << endl;
                toerase.insert(x);
                toadd.insert(x-1);
                toadd.insert(x+1);
                count++;
            }
        }
        for(auto x: toerase) currentx.erase(x);
        for(auto x: toadd) currentx.insert(x);
        cout << endl;
    }
    cout << count;
}
