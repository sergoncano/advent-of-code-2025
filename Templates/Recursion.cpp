#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IN(t,i) t i; cin >> i;
#define REP(i,j,k) for(ll i = j; i < k; i++)

bool recurse(ll current, vector<ll> vec, ll objective){
    if(vec.size()==1) {
        //base case, check either
        return current * vec.at(0) == objective || current + vec.at(0) == objective;
    } else {
        //take first element and recurse with it
        ll op = vec.at(0);
        vec.erase(vec.begin());
        return recurse(current*op, vec, objective) || recurse(current+op, vec, objective);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll totalsum = 0;
    string line;
    while(getline(cin, line)) {
        stringstream ss(line);
        string n;
        getline(ss, n, ':');
        ll sum = stol(n);
        ll op;
        vector<ll> operators;
        while(ss >> op) {
            operators.push_back(op);
        }
        op = operators.at(0);
        operators.erase(operators.begin());
        if(recurse(op, operators, sum)) totalsum += sum;
    }
    cout << totalsum;
}
