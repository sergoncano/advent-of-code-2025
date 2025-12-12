#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define IN(t,i) t i; cin >> i;
#define REP(i,j,k) for(ll i = j; i < k; i++)

#define lines 198
#define max_depth 8

bool found = false;
unordered_map<string, ll> dp;
ll solve(string finalconfig, vector<vector<ll>>& wirings, string config) {
    dp = unordered_map<string,ll>();
    dp[finalconfig] = 0;
    vector<string> prev;
    prev.push_back(finalconfig);
    REP(mem,0,max_depth) {
        vector<string> newprev;
        REP(prev_i,0,prev.size()) {
            REP(i,0,wirings.size()) { // traverse wirings
                string prevcpy = prev.at(prev_i);
                REP(j,0,wirings.at(i).size()) {
                    ll w = wirings.at(i).at(j);
                    if(prevcpy[w]=='#') prevcpy[w] = '.';
                    else prevcpy[w]= '#';
                }
                if(dp.count(prevcpy)==0)
                    dp[prevcpy] = mem+1;
                if(dp.count(config)!=0) goto finished;
                newprev.push_back(prevcpy);
            }
        }
        prev = newprev;
    }

finished:
    if(dp.count(config)!=0) {
        cout << dp[config] << endl;
        cout.flush();
        return dp[config];
    } else  {
        cout << "AMOGERROR" << endl;
        cout.flush();
        return LONG_LONG_MAX;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll sum = 0;
    REP(linei, 0, lines) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string finalconfig;
        getline(ss, finalconfig, ' ');
        string wiring;
        vector<vector<ll>> wirings;
        while(ss >> wiring) {
            if(wiring[0]=='{') break;
            vector<ll> wired_together;
            REP(i,0,wiring.length()) {
                if(i%2==0) continue;
                wired_together.push_back(wiring[i]-'0');
            }
            wirings.push_back(wired_together);
        }
        string neededconfig = "";
        REP(i,0,finalconfig.length()-2) neededconfig = neededconfig + ".";
        found = false;
        ll res = solve(finalconfig.substr(1,finalconfig.length()-2), wirings, neededconfig); 
        cout << res << endl;
        sum += res;
    }
    cout << "Sum: " << sum << endl;
}

