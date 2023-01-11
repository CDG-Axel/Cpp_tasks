#include <iostream>
#include <cmath>

using namespace std;

void knight_chess() {
    int x = 3, y = 2;

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; ++j) {
            cout << (abs(x - j) * abs(y - i) == 2 ? "* " : ". ");
        }
        cout << endl;
    }
}

void swap_three(int &a, int &b, int &c) {
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
}

void boxes_task() {
    int a1, b1, c1, a2, b2, c2;
    string msg;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    swap_three(a1, b1, c1);
    swap_three(a2, b2, c2);

    if (a1 == a2 && b1 == b2 && c1 == c2)
        msg = "Boxes are equal";
    else if (a1 <= a2 && b1 <= b2 & c1 <= c2)
        msg = "The first box is smaller than the second one";
    else if (a1 >= a2 && b1 >= b2 & c1 >= c2)
        msg = "The first box is larger than the second one";
    else
        msg = "Boxes are incomparable";

    cout << msg << endl;
}

const int MAX_SIZE = 10000000;
long long simples[MAX_SIZE];

long long find_last_simple(long long limit) {
    long long n = 1, size = 0, i;
    while (++n < limit) {
        int found = 1;
        for (i = 0; i < size; ++i) {
            if (n % simples[i] == 0) {
                found = 0;
                break;
            }
            if (i * i > n) break;
        }
        if (found) {
            if (size < MAX_SIZE - 1) {
                simples[size++] = n;
            } else {
                cout << "Max size reached at " << n << endl;
                break;
            }
        }
    }
    cout << "Array size: " << size << endl;
    return simples[size-1];
}

int min_divisor(int n){
    int i = 2;
    while (n % i && i * i <= n) {
        i++;
    }
    return i*i <= n ? i : n;
}


int min_distance() {
    // предыдущий, текущий и следующий элементы, прошлый максимум
    // в минимальное расстояние заносится "огромное" значение, чтобы все найденные расстояния были меньше
    int prev = 0, mid = 0, next, prev_max = 0, min_len = 99999999, idx = 0;
    // считываем и проверяем на 0 в одном флаконе
    while (cin >> next && next) {
        // prev = 0 только в случае, когда мы считали второй элемент, тут не может быть локального максимума
        if (prev > 0 && next < mid && mid > prev) {
            // prev_max = 0 только когда найденный максимум первый, иначе он больше 0
            if (prev_max > 0 && idx - prev_max < min_len) min_len = idx - prev_max;
            prev_max = idx;
        }
        // сдвигаем элементы, увеличиваем индекс текущего элемента
        prev = mid;  mid = next;  idx++;
    }
    // в min_len будет начальное большое значение, если мы не нашли двух локальных максимумов
    return min_len == 99999999 ? 0 : min_len;
}


void square_equation() {
    double a, b, c;
    cin >> a >> b >> c;
    if (!a)
        if (b) cout << "1 " << -c / b << endl;
        else {
            if (c) cout << "0" << endl;
            else cout << "3" << endl;
        }
    else {
        b /= -2 * a;
        a = b * b - c / a;
        if (a >= 0) {
            if (a < 1e-9) cout << "1 " << b;
            else cout << "2 " << b - sqrt(a) << " " << b + sqrt(a);
        } else cout << "0 ";
    }
}