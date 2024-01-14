#include <iostream>

using namespace std;

bool different(int d, int m, int y) {
    int a[10] = {};
    while (y) {
        if (a[y % 10]++) return false;
        y /= 10;
    }
    while (m) {
        if (a[m % 10]++) return false;
        m /= 10;
    }
    while (d) {
        if (a[d % 10]++) return false;
        d /= 10;
    }
    return true;
}

bool different_year(int y) {
    int a[10] = {};
    while (y) {
        if (a[y % 10]++) return false;
        y /= 10;
    }
    return true;
}

bool leap(int y) {
    return y % 400 == 0 || y % 4 == 0 && y % 100;
}

int main() {
    int y, m, d;
    int month_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cin >> d >> m >> y;
    month_days[2] = 28 + leap(y);
    do {
        if (++d > month_days[m]) {
            d = 1;
            if (++m > 12) {
                m = 1;
                while (!different_year(++y));
                month_days[2] = 28 + leap(y);
            }
        }
    }
    while (!different(d, m, y));

    cout << d << "." << m << "." << y;
}