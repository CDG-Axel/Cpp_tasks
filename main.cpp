#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#include "stepik.h"

using namespace std;

int main() {
    int n, k, i, e;
    long long cnt = 0;
    cin >> n >> k;
    vector<int> days(n);
    vector<int> complexity(k);
    map <int, vector<int>> trials;

    for (i = 0; i < n; i++) cin >> days[i];
    for (i = 0; i < k; i++) cin >> complexity[i];
    for (i = 0; i < k; i++) {
        cin >> e;
        trials[complexity[i]].push_back(e);
    }
    sort(days.begin(), days.end());
    for (auto t: trials) sort(trials[t.first].begin(), trials[t.first].end());


    for (auto max_comp: days) {
        int max_glory = -1, max_ind = -1;
        for (auto trial: trials) {
            if (trial.first > max_comp) break;
            e = trial.second[trial.second.size() - 1];
            if (e > max_glory) {
                max_ind = trial.first;
                max_glory = e;
            }
        }
        if (max_glory >= 0) {
            cnt += max_glory;
            trials[max_ind].pop_back();
            if (trials[max_ind].empty())
            trials.erase(max_ind);
        }
    }

    cout << cnt << endl;
}

