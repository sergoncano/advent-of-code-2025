#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define IN(t,i) t i; cin >> i;
#define REP(i,j,k) for(ll i = j; i < k; i++)
#define P 6
#define T 1000

typedef struct {
    ll size_x;
    ll size_y;
    vector<ll> wanted_presents;
} request;

vector<vector<vector<bool>>> presents;
vector<ll> present_sizes;
vector<request> requests;

bool solve(ll n) {
    request req = requests.at(n);
    ll totalsize = req.size_y * req.size_x;
    vector<ll> wanted_presents = req.wanted_presents;
    REP(i,0,wanted_presents.size()) {
        totalsize -= present_sizes.at(i) * wanted_presents.at(i);
    }
    return totalsize > 4;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    REP(i,0,P) {
        string s; cin >> s;
        vector<vector<bool>> present(3, vector(3, false));
        ll size= 0;
        REP(j,0,3) {
            cin >> s;    
            REP(k,0,3) {
                if(s[k]=='#')  { present.at(j).at(k) = true; size++; }
            }
        }
        present_sizes.push_back(size);
        presents.push_back(present);
    }
    REP(i,0,P) {
        REP(j,0,3) {
            REP(k,0,3)
            { if(presents.at(i).at(j).at(k)) cout << '#'; else cout << '.'; }
            cout << endl;
        }
        cout << endl;
    }


    REP(t,0,T) {
        string size; cin >> size;
        stringstream s(size);
        string xs, ys;
        getline(s, xs, 'x');
        getline(s, ys, ':');
        vector<ll> wanted_presents;
        REP(p,0,P) { string x; cin >> x; wanted_presents.push_back(stol(x)); }
        requests.push_back({stol(xs), stol(ys), wanted_presents});
    }
    ll solved = 0;
    REP(t,0,T) { if(solve(t)) solved++; }
    cout << solved << endl;
}
