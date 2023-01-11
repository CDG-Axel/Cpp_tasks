#include <iostream>
#include <cmath>
#include <iomanip>
#include "stepik.h"

using namespace std;

int main() {
    int start = clock();
    cout << find_last_simple_static(10000000) << endl;
    cout << "Time: " << (clock() - start)/1000. << " sec" << endl;
    return 0;
}
