#include <iostream>
#include <vector>
#include "float.h"
#include <iomanip>

using namespace std;

int main() {
    int cnt = 0;
    float b, mn = FLT_MAX, mx = 0, avg = 0;
    cin >> b;
    while (b > 0) {
        avg += b;
        cnt++;
        mx = b > mx ? b : mx;
        mn = b < mn ? b : mn;
        cin >> b;
    }
    float diff = mx - mn - avg / cnt;
    if (diff > 0) cout << "Difference of max and min is greater than average";
    else
        if (diff < 0) cout << "Difference of max and min is smaller than average";
        else cout << "Difference of max and min equals to average";
}
