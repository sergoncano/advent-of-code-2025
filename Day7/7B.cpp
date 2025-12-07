//<>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IN(type,name) type name; cin >> name
#define REP(var,first,last) for(ll var = first; var < last; var++)

int main() {
    ll count = 0;
    map<ll,ll> currentx;
        IN(string,line);
    REP(x,0,line.size()) {if(line[x]=='S') currentx[x] = 1; }
    while(cin>> line) {
        map<ll,ll> newmap;
        bool anything = false;
        for(auto const& [x, dimensions] : currentx) {
            if(line[x]=='^') {
                if(newmap.count(x+1)==0)
                    newmap[x+1]=0;
                if(newmap.count(x-1)==0)
                    newmap[x-1]=0;
                newmap[x+1]+=currentx[x];
                newmap[x-1]+=currentx[x];
                cout << "increment in: " << currentx[x] << endl;
                newmap[x]=0;
                anything = true;
            } else {
                if(newmap.count(x)==0)
                    newmap[x]=0;
                newmap[x]+=dimensions;
            }
        }
       if(anything)
        currentx = newmap;
    }
    for(auto const& [x, dimensions] : currentx) {
        count += dimensions;
    }
    cout << count;
}
