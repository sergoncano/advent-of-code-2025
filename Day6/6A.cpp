#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IN(t,i) t i; cin >> i;
#define REP(i,j,k) for(ll i = j; i < k; i++)

ll conc(ll first, ll second) {
    int digits = 0;
    string firstcpy = to_string(first);
    string secondcpy = to_string(second);
    return stol(firstcpy+secondcpy+"");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll totalsum = 0;
    string line;
    vector<vector<ll>> problems;
    REP(i,0,3) {
        getline(cin, line);
        stringstream ss(line);
        string n;
        vector<ll> problem;
        while(ss >> n) {
            ll num = stol(n);
            problem.push_back(num);
        }
            cout << endl;
        problems.push_back(problem);
    }
    vector<char> operators;
    getline(cin, line);
    stringstream ss(line);
    char n;
    while(ss >> n) {
        operators.push_back(n);
    }
    vector<vector<ll>> realproblems;
    REP(i,0,4) {
        ll mostdig = 0;
        vector<ll> realproblem;
        REP(j,0,problems.size()) mostdig = max(mostdig, problems.at(j).at(i));
        mostdig = log10(mostdig);
        REP(k,1,mostdig) {
            ll div = 1;
            REP(f,0,k) {div*=10;}
            ll realnum = 0;
            REP(j,0,problems.size()) {
                ll num = problems.at(j).at(i);
                num /= div;
                cout.flush();
                if(num!=0) realnum = conc(realnum, num);
            } 
            realproblem.push_back(realnum);
        }
        realproblems.push_back(realproblem);
    }


    REP(i,0,4) {
        ll sum = 0;
        if(operators.at(i)=='+') {
            REP(j,0,realproblems.at(i).size()){
                cout << "op: " << realproblems.at(i).at(j) << endl;
                sum += realproblems.at(i).at(j);
            }
        } else {
            sum++;
            REP(j,0,realproblems.at(i).size()) {
                 cout << "op: " << realproblems.at(i).at(j) << endl;
                 sum *= realproblems.at(i).at(j);
            }
        }
        totalsum += sum;
    }
    cout << totalsum;
}
