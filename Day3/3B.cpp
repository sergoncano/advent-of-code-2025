
//<>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IN(type,name) type name; cin >> name

int main() {
    string s;
    ll sum = 0;
    while(cin >> s) {

        ll digits[12];
        ll mxi[12];
        for(int k = 0; k < 12; k++) {
            ll mx = -1;
            int i;
            if(k==0) i = 0;
            else i = mxi[k-1]+1;
            for(; i < s.length()-(11-k); i++) {
                int num = s[i] - '0';
                if(num > mx){mx = num; mxi[k] = i;}
            }
            digits[k] = mx;
        }
        for(int i = 0; i < 12;  i++) cout << digits[i];
        cout << endl;
        ll currsum = 0;
        for(int i = 0; i < 12;  i++) {
            currsum *=10;
            currsum += digits[i];
        }
        sum += currsum;
    }
    cout << sum;
}
 
