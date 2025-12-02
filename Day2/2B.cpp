//<>
#include <bits/stdc++.h>
#include <cstdio>
#include <string>
using namespace std;
typedef long long ll;
#define IN(type,name) type name; cin >> name

int main() {
    string s;
    ll sum = 0;
    while(getline(cin,s,',')) {
        stringstream ss(s);
        string first_str; getline(ss, first_str, '-');
        ll first = stol(first_str);
        string second_str; getline(ss, second_str, '-');
        ll second = stol(second_str);

        for(ll i = first; i <= second; i++) {
            string num = to_string(i);
            bool matches = false;
            for(ll len =1; len < num.length(); len++) {
                if(num.length()%len!=0) continue;
                string subst = num.substr(0, len);
                bool all_are_equal = true;
                for(ll d = 0; d < num.length(); d+= len) {
                    all_are_equal = all_are_equal && subst == num.substr(d, len);
                }
                matches = matches || all_are_equal;
            }
            if(matches) sum += i;
        }
    }
    cout << sum << endl;
}
 
