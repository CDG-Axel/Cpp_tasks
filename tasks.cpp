#include <iostream>
#include <vector>

using namespace std;

bool different(int y, int m, int d) {
    int digits[10] = {};
    digits[d % 10]++;
    if (d > 9) {
        if (digits[d / 10]++) return false;
    }
    if (digits[m % 10]++) return false;
    if (m > 9) {
        if (digits[m / 10]++) return false;
    }
    while (y > 0) {
        int dig = y % 10;
        y /= 10;
        if (digits[dig]++) return false;
    }

    return digits[0] < 2;
}

bool is_leap(int y) {
    return y % 400 == 0 || y % 100 != 0 && y % 4 == 0;
}

bool different_year(int y) {
    int a[10] = {};
    while (y) {
        if (a[y % 10]++) return false;
        y /= 10;
    }
    return true;
}

void next_year() {
    int y, m, d;
    int month_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cin >> d >> m >> y;
    month_days[1] = 28 + is_leap(y);
    do {
        d += 1;
        if (d > month_days[m]) {
            d = 1;
            m += 1;
            if (m > 12) {
                m = 1;
                while (!different_year(++y));
                month_days[1] = 28 + is_leap(y);
            }
        }
    } while (!different(y, m, d));
    cout << d << "." << m << "." << y;
}