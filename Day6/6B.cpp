#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IN(t,i) t i; cin >> i;
#define REP(i,j,k) for(ll i = j; i < k; i++)

string to_str(char c) {
    string s = "";
    return s + c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll totalsum = 0;
    string l1;
    getline(cin, l1);
    string l2;
    getline(cin, l2);
    string l3;
    getline(cin, l3);
    string l4;
    getline(cin, l4);
    vector<char> operators;
    char o;
    while(cin >> o) operators.push_back(o);

    vector<vector<ll>> equations;
    ll character = 0;
    REP(column, 0, 1000) {
        bool allspaces = false;
        vector<ll> equation; while(!allspaces) {
            string res = "";
            string c1 = to_str(l1[character]);
            string c2 = to_str(l2[character]);
            string c3 = to_str(l3[character]);
            string c4 = to_str(l4[character]);
            character++;
            if(c1!=" ") {
                res = res + c1;
            } if(c2!=" ") {
                res = res + c2;
            } if(c3!=" ") {
                res = res + c3;
            } if(c4!=" ") {
                res = res + c4;
            }
            allspaces = c1==" " && c2==" " && c3==" " && c4==" ";
            if(!allspaces) {
                ll result = stol(res);
                equation.push_back(result);
                if(column!=0) continue;
                cout.flush();
            }
        }
        equations.push_back(equation);
    }
    REP(i,0,equations.size()){
        ll sum = 0;
        ll prod = 1;
        REP(j,0,equations.at(i).size()) {
            if(operators.at(i)=='+') {
                sum += equations.at(i).at(j);
                cout << equations.at(i).at(j) << " + ";
            } else {
                prod *= equations.at(i).at(j);
                cout << equations.at(i).at(j) << " * ";
            }
        }
        cout << "= " << sum << endl;
        if(operators.at(i)=='+')
        totalsum += sum;
        else totalsum += prod;
    }
    cout << totalsum;
}
