#include <iostream>
#include <vector>
#include <algorithm>
#include "nlogn.h"

using namespace std;

typedef pair <string, float> pupil;

bool compare(pupil a, pupil b) {
    return a.second < b.second;
}

int main() {
    int start = clock();
    long long sum = 0;
    for (int i = 0; i < 200000; ++i) {
        sum = sum % 123456;
        sum = sum % 1324;
        sum = sum % 12;
        sum = sum % 12356;
        for (int j = 0; j < 1000; ++j) {
            sum += j;
        }
    }
    cout << (clock() - start)/1000. << " sec";
}