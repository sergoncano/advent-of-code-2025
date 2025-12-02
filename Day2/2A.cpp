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
            cout << i << endl;
            if(num.size()%2==0 && num.substr(0, num.size()/2) == num.substr(num.size()/2, num.size()/2)){
                sum += i;
                //cout << i << endl;
            }
        }
    }
    cout << sum << endl;
}
 
