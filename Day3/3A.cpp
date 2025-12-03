//<>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IN(type,name) type name; cin >> name

int main() {
    string s;
    ll sum = 0;
    while(cin >> s) {
        int mx = 0, mxi = -1;
        for(int i = 0; i < s.length()-1; i++) {
            int num = s[i] - '0';
            if(num > mx) { mx = num; mxi = i; }
        }
        int smx = 0;
        for(int i = mxi+1; i < s.length(); i++) {
            int num = s[i] - '0';
            if(num > smx) {smx = num;}
        }
        sum += 10*mx + smx;
    }
    cout << sum;
}
 
