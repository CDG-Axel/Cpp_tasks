#include <iostream>
#include <vector>
#include <set>

using namespace std;

void heap_add(int *heap, int &size, int value) {
    int idx = size;
    heap[size++] = value;
    while (idx) {
        int temp = (idx - 1) / 2;
        if (heap[temp] < heap[idx]) swap(heap[temp], heap[idx]);
        idx = temp;
    }
}

int heap_pop(int *heap, int &size) {
    int value = heap[0], best = 0, idx = 1;
    heap[0] = heap[--size];
    while (best != idx) {
        idx = best;
        int left = 2 * idx + 1, right = 2 * idx + 2;
        if (left < size && heap[left] > heap[best]) best = left;
        if (right < size && heap[right] > heap[best]) best = right;
        if (best != idx) swap(heap[idx], heap[best]);
    }
    return value;
}


void task_a() {
    int *heap = new int[200000], size = 0, val;

    string cmd;
    while (cin >> cmd) {
        if (cmd == "CLEAR") size = 0;
        else if (cmd == "ADD") {
            cin >> val;
            heap_add(heap, size, val);
        } else {    // EXTRACT
            if (size) cout << heap_pop(heap, size) << endl;
            else cout << "CANNOT\n";
        }
    }
    delete[] heap;
}

void dfs() {
    int n, s, f, route = 0;
    cin >> n >> s >> f;
    vector <vector <int>> m(n, vector<int> (n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) cin >> m[i][j];

    vector <bool> visited(n, false);
    set <int> points{s - 1};

    visited[s - 1] = true;
    while (points.size() > 0 && points.find(f - 1) == points.end()) {
        route++;
        set <int> dest;
        for (auto e : points)
            for (int i = 0; i < n; ++i)
                if (m[e][i] && !visited[i]) {
                    dest.insert(i);
                    visited[i] = true;
                }
        points = dest;
    }
    cout << (points.size() ? route : 0)<< endl;
}