#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll conc(ll first, ll second) {
    int digits = 0;
    string firstcpy = to_string(first);
    string secondcpy = to_string(second);
    return stol(firstcpy+secondcpy+"");
}
