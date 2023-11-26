#include "nlogn.h"
#include <iostream>
using namespace std;

void multiple_fact_old() {
    int a[100], n;
    long long res = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= a[i]; ++j) {
            res *= j;
            res %= 1000000000000;
        }
    }
    cout << res;
}


void multiple_fact() {
    long long res = 1, e, n;
    cin >> n;
    while (n-- && res) {
        cin >> e;
        for (int j = 1; j <= e && res; ++j) res = res * j % 1000000000000;
    }
    cout << res;
}
