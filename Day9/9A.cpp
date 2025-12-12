#include <bits/stdc++.h>
#include <sstream>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define IN(t,i) t i; cin >> i;
#define REP(i,j,k) for(ll i = j; i < k; i++)

#define N 8 //496
vector<vector<char>> board = vector(100000, vector(100000, '.'));

bool tileinxrange(ll x1, ll x2, ll y) {
    bool found = false;
    REP(i,min(x1,x2), max(x1,x2)) {
        if(board.at(i).at(y)=='#') {
            found = true;
            break;
        } 
    }
    return found;
}

bool tileinyrange(ll y1, ll y2, ll x) {
    bool found = false;
    REP(i,min(y1,y2), max(y1,y2)) {
        if(board.at(x).at(i)=='#') {
            found = true;
            break;
        } 
    }
    return found;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pii> coords;

    REP(i,0,N) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string xs, ys;
        getline(ss, xs, ',');
        getline(ss, ys, ',');
        ll x, y;
        x = stol(xs);
        y = stol(ys);
        coords.push_back(pair(x,y));
        board.at(x).at(y) = '#';
    }
    ll mx= 0 ;
    REP(i,0,N) {
        REP(j,i+1,N) {
            ll x1 = coords.at(i).first;
            ll x2 = coords.at(j).first;
            ll dx = x1-x2 +1;
            ll y1 = coords.at(i).second;
            ll y2 = coords.at(j).second;
            ll dy = y1-y2 +1;
            cout << "Coords(1): " << x1 << ", " << y1 << endl;
            cout << "Coords(2): " << x2 << ", " << y2 << endl;
            bool condx, condy;
            if(x1>x2) {
                condx = tileinxrange(x1+1, 100000-1, y1) || tileinxrange(x2-1, 0, y2);
            } else {
                condx = tileinxrange(x2+1, 100000-1, y2) || tileinxrange(x1-1, 0, y1);
            }
            condx = condx || board[x1][y2] == '#' || board[x2][y1] == '#'; 
            cout << "Is there a row of #? " << condx << endl;
            if(y1>y2) {
                condy = tileinyrange(y1+1, 100000-1, x1) || tileinxrange(y2-1, 0, x2);
            } else {
                condy = tileinyrange(y2+1, 100000-1, x2) || tileinxrange(y1-1, 0, x1);
            }
            condy = condy || board[y1][x2] == '#' || board[x2][y1] == '#'; 
            cout << "Is there a column of #? " << condy << endl;
            if(condx && condy)
                mx = max(mx, abs(dx)*abs(dy));
        }
    }
    cout << mx;
}
