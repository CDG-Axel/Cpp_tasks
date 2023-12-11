#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair <string, float> pupil;

bool compare(pupil a, pupil b) {
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;
    vector <pupil> a(n);
    for (int i = 0; i < n; i++) {
        string ts;
        int m1, m2, m3;
        cin >> a[i].first >> ts >> m1 >> m2 >> m3;
        a[i].first += " " + ts;
        a[i].second = (m1 + m2 + m3) / 3.0;
    }
    stable_sort(a.begin(), a.end(), compare);
    for (auto smb : a) cout << smb.first << endl;
    return 0;
}