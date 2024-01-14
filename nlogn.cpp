#include "nlogn.h"
#include <iostream>
#include <map>
#include <vector>

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


void process_dna() {
    map <int, string> d;
    int n, a, b;
    int start = clock();
    cin >> n;
    string s;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        d[i] = s;
    }
    for (int i = n; i > 1; i--) {
        cin >> a >> b;
        d[b] += d[a];
        d.erase(a);
    }
    cin >> s;
    cout << d[b] << (s == d[b]? "\nTrue": "\nFalse") << endl;
    cout << "Time: " << (clock() - start) / 1000. << " sec" << endl;
}


void process_dna_arr() {
    int n, a, b;
    int start = clock();
    cin >> n;
    vector <string> d(n + 1);
    string s;
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = n; i > 1; i--) {
        cin >> a >> b;
        d[b] += d[a];
        d[a] = "";
    }
    cin >> s;
    cout << d[b] << (s == d[b]? "\nTrue": "\nFalse") << endl;
    cout << "Time: " << (clock() - start) / 1000. << " sec" << endl;
}


void str_concat() {
    string s;
    int start = clock();
    for (int i = 0; i < 200000; ++i) s += "12345";
    cout << s.length() << endl;
    cout << "Time: " << (clock() - start) / 1000. << " sec" << endl;
}


typedef pair <string, float> pupil;

bool compare(pupil a, pupil b) {
    return a.second < b.second;
}

long long test_vector_pop(int n) {
    long long p = 0, sum = 0, start = clock();

    vector <int> a(n);
    for (int i = 0; i < n; ++i) a[i] = i;
    while (a.size() > 0) {
        a[p++]++;
        sum += a[0];
        a.erase(a.begin());
        if (p >= a.size()) p = 0;
    }
    cout << (clock() - start)/1000. << " sec" << endl;
    return sum;
}
