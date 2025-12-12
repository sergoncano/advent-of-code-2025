#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define IN(t,i) t i; cin >> i;
#define REP(i,j,k) for(ll i = j; i < k; i++)
#define N 660

unordered_map<string, vector<string>> reactor;

ll recurse(string where) {
    vector<string> paths = reactor[where];
    if(paths.at(0)=="out")
        return 1;
    else {
        ll sum = 0;
        REP(i,0,paths.size()) sum += recurse(paths.at(i));
        return sum;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    REP(i,0,N) {
        getline(cin, line);
        stringstream ll(line);
        string first_element, element;
        ll >> first_element;
        first_element = first_element.substr(0, first_element.size()-1);
        vector<string> v;

        while(ll >> element) {
            v.push_back(element);
        } 
        reactor[first_element] = v;
    }
    cout << recurse("you") << endl;
}
