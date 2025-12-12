#include <bits/stdc++.h>
#include <functional>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define IN(t,i) t i; cin >> i;
#define REP(i,j,k) for(ll i = j; i < k; i++)
#define N 1000

vector<vector<ll>> boxes;
typedef struct {
    ll u;
    ll v;
    long double distance;
} edge;

ll parent[N];

void make_set(ll v) {parent[v] = v;}
ll find_set(ll v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}

string point_to_string(ll p) {
    string res = "";
    res += to_string(boxes.at(p).at(0)) + ", ";
    res += to_string(boxes.at(p).at(1)) + ", ";
    res += to_string(boxes.at(p).at(2));
    return res;
}

bool sorter(edge a, edge b) {
    return a.distance < b.distance;
}

long double dist(vector<ll> a, vector<ll> b) {
    ll dx = a.at(0) - b.at(0);
    ll dy = a.at(1) - b.at(1);
    ll dz = a.at(2) - b.at(2);
    long double sum = dx*dx + dy*dy + dz*dz;
    return sqrtl(sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    REP(i,0,N) {
        getline(cin, line);
        string xs, ys, zs;
        stringstream ss(line);
        getline(ss, xs, ',');
        getline(ss, ys, ',');
        getline(ss, zs, ',');
        ll x,y,z;
        x = stol(xs);
        y = stol(ys);
        z = stol(zs);
        vector<ll> v;
        v.push_back(x);
        v.push_back(y);
        v.push_back(z);
        boxes.push_back(v);
    }
    vector<edge> edges;
    REP(i,0,N) {
        REP(j,i+1,N) {
            edge e = { i, j, dist(boxes.at(i), boxes.at(j)) };
            edges.push_back(e);
        }
    }
    sort(edges.begin(),edges.end(), sorter);
    REP(i,0,N) {make_set(i);} 
    vector<ll> sizes;
    REP(i,0,N) sizes.push_back(1);
    ll prod;
    REP(i,0,1000*1000) {
        ll j = edges.at(i).v;
        ll k = edges.at(i).u;
        if(find_set(j)==find_set(k)){continue;}
        ll a = sizes.at(find_set(j)); // error here
        ll b = sizes.at(find_set(k));
        sizes.at(find_set(j)) = 0;
        sizes.at(find_set(k)) = 0;
        union_sets(j, k);
        sizes.at(find_set(j)) = a+b;
        cout << "First: " << point_to_string(edges.at(i).u) << endl;
        cout << "Second: " << point_to_string(edges.at(i).v) << endl;
        cout << "Sub size: " << sizes.at(find_set(j)) << endl;
        prod = boxes.at(j).at(0) * boxes.at(k).at(0);
        if(a+b==1000) break;
    }
    sort(sizes.begin(),sizes.end(), greater<ll>());
    cout << sizes.at(0) << "*" << sizes.at(1) << "*"<< sizes.at(2) << "=";
    cout << sizes.at(0) * sizes.at(1) * sizes.at(2) << endl;
    cout << "Prod: " << prod << endl;
}
