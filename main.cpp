#include <iostream>
#include <cmath>
#include <iomanip>
#include "stepik.h"

using namespace std;

int main() {
    int start = clock();
    square_equation();
    cout << "Time: " << (clock() - start)/1000. << " sec" << endl;
    return 0;
}
