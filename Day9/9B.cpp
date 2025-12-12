#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define IN(t,i) t i; cin >> i;
#define REP(i,j,k) for(ll i = j; i < k; i++)

#define N 496
vector<vector<char>> board;
unordered_map<ll, ll> map_x;  // complete to reduced
unordered_map<ll, ll> map_y;
unordered_map<ll, ll> map_x_reverse;// reduced to complete
unordered_map<ll, ll> map_y_reverse;
bool validpos(ll x, ll y) {
    if(x< 0 || y < 0 || y >= board.at(0).size() || x >= board.size())
        return false;
    if(board[x][y]=='#') return false;
    return true;
}

void BFS(ll x, ll y) {
    if(!validpos(x, y)) return;               // WALL USAGE HEREEEEEEEEEEE
    // DO YOUR SHENANIGANS HERE count++ or wtv;
    cout << "Checking x:" << x << "; y:" << y << endl;cout.flush();
    board.at(x).at(y)='#';
    BFS(x+1, y);
    BFS(x-1, y);
    BFS(x, y+1);
    BFS(x, y-1);
}

typedef struct {
    pii a;
    pii b;
    ll area;
} rectangle;

bool sorter(rectangle a, rectangle b) {
    return a.area > b.area;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pii> coords;
    vector<ll> coords_x;
    vector<ll> coords_y;

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
        coords_x.push_back(x);
        coords_y.push_back(y);
    }
    sort(coords_x.begin(), coords_x.end());
    sort(coords_y.begin(), coords_y.end());
    ll xi = 0;
    REP(i,0,coords_x.size()) {
        ll x = coords_x.at(i);
        if(map_x.count(x)==0) {
            map_x[x] = xi;
            map_x_reverse[xi] = x;
            xi++;
        }
    }
    ll yi = 0;
    REP(i,0,coords_y.size()) {
        ll y = coords_y.at(i);
        if(map_y.count(y)==0) {
            map_y[y] = yi;
            map_y_reverse[yi] = y;
            yi++;
        }
    }
    board = vector(xi, vector(yi, '.'));
    REP(i,0,coords.size()) { // corners for the grid
        ll x = map_x[coords.at(i).first];
        ll y = map_y[coords.at(i).second];
        board.at(x).at(y)='#';
    }
    REP(i,1,coords.size()) { // borders for the grid
        ll prev_x = map_x[coords.at(i-1).first];
        ll prev_y = map_y[coords.at(i-1).second];
        ll x = map_x[coords.at(i).first];
        ll y = map_y[coords.at(i).second];
        if(prev_x==x) {
            REP(j,min(y,prev_y), max(y,prev_y)) board.at(x).at(j)='#';
        } else {
            REP(j,min(x,prev_x), max(x,prev_x)) board.at(j).at(y)='#';
        }
    }
    ll prev_x = map_x[coords.at(coords.size()-1).first];
    ll prev_y = map_y[coords.at(coords.size()-1).second];
    ll x = map_x[coords.at(0).first];
    ll y = map_y[coords.at(0).second];
    if(prev_x==x) {
        REP(j,min(y,prev_y), max(y,prev_y)) board.at(x).at(j)='#';
    } else {
        REP(j,min(x,prev_x), max(x,prev_x)) board.at(j).at(y)='#';
    }

    BFS(board.size()/2 + 20, board.at(0).size()/2+20);//fill grid
    vector<rectangle> r;
    REP(i,0,N) {
        REP(j,i+1,N) {
            ll x1 = map_x[coords.at(i).first];
            ll x2 = map_x[coords.at(j).first];
            ll dx = abs(coords.at(i).first-coords.at(j).first) +1;
            ll y1 = map_y[coords.at(i).second];
            ll y2 = map_y[coords.at(j).second];
            ll dy = abs(coords.at(i).second-coords.at(j).second) +1;
            r.push_back({pair(x1,y1), pair(x2,y2) , dx*dy});
        }
    }
    sort(r.begin(),r.end(), sorter);
    bool found = false;
    pii afound, bfound;
    REP(i,0,r.size()) {
        pii a = r.at(i).a;
        pii b = r.at(i).b;
        found = true;
        for(ll j = min(a.first, b.first); j <= max(a.first,b.first)&& found; j++) found = found && board.at(j).at(a.second)=='#';
        for(ll j = min(a.first, b.first); j <= max(a.first,b.first)&& found; j++) found = found && board.at(j).at(b.second)=='#';
        for(ll j = min(a.second , b.second); j <= max(a.second,b.second)&& found; j++) found = found && board.at(a.first).at(j)=='#';
        for(ll j = min(a.second , b.second); j <= max(a.second,b.second)&& found; j++) found = found && board.at(b.first).at(j)=='#';
        if(found) {
            afound = a;
            bfound = b; break;
        }
    }
    pii a = afound, b = bfound;
    ll ax = map_x_reverse[a.first];
    ll ay = map_y_reverse[a.second];
    ll bx = map_x_reverse[b.first];
    ll by = map_y_reverse[b.second];
    ll dx = abs(ax-bx)+1;
    ll dy = abs(ay-by)+1;
    cout << "The result is: " << dx*dy << endl<< "X1: " << ax << ", Y1: " << ay << endl << "X2: " << bx << " Y2: " << by << endl;

    /*
    REP(j,0,board.at(0).size()-1) { //print grid
        REP(i,0,board.size()) 
            if(j>= map_x[min(ax, bx)] && j <= map_x[max(ax,bx)] && i >= map_y[min(ay,by)] && i <= map_y[max(ay,by)]) {
                if(board.at(j).at(i)=='#') cout << "@"; else cout << "!";
            } else 
                cout << board.at(j).at(i);
        cout << endl;
    }
    */
}

