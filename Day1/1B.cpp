//<>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
#define IN(type,name) type name; cin >> name

int main() {
    string s;
    ll pos = 50;
    ll count = 0;
    while(cin>>s) {
        if(s[0]=='L') {
            ll dist = stoi(s.substr(1, s.size()-1));
            for(int i = 0; i < dist; i++) {
                pos--;
                if(pos==0) count++;
                if(pos<0){ pos += 100;}
            }
        } 
        else {
            ll dist = stoi(s.substr(1, s.size()-1));
            for(int i = 0; i < dist; i++) {
                pos++;
                if(pos>=100){ pos -= 100;}
                if(pos==0) count++;
            }
        }
        cout << pos << endl;
    }
    cout << count;
}
 
