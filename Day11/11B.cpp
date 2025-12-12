#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define IN(t,i) t i; cin >> i;
#define REP(i,j,k) for(ll i = j; i < k; i++)
#define N 660

unordered_map<string, vector<string>> reactor;
unordered_map<string, ll> dp;

ll recurse(string step, bool fft, bool dac) {
    if(step=="fft") fft = true;
    if(step=="dac") dac = true;
    string chain = "";
    if(fft) chain = chain + "f";
    else chain = chain + "-";
    if(dac) chain = chain + "d";
    else chain = chain + "-";
    chain += step;
    if(dp.count(chain)!=0) return dp[chain];
    if(reactor[step].at(0)=="out"){dp[chain]=fft&&dac; return fft && dac;}
    else {
        ll sum = 0;
        REP(i,0,reactor[step].size()) sum += recurse(reactor[step].at(i), fft, dac);
        dp[chain]= sum;
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
    cout << recurse("svr", false, false) << endl;
}
