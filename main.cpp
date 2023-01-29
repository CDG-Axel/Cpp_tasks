#include <iostream>
#include <vector>
#include "stepik.h"

using namespace std;

int main() {
    int n, m, i, j, k, cnt, found = 0;
    cin >> n >> m;
    vector <vector <int>> a(n, vector<int> (m));

    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j) cin >> a[i][j];
    cin >> k;

    for (i = 0; i < n && !found; ++i)
        for (j = cnt = 0; j < m && !found; ++j)
            if (a[i][j]) cnt = 0;
            else if (++cnt >= k) found = i + 1;

    cout << found << endl;
    return 0;
}

