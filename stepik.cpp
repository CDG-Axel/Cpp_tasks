#include <iostream>
#include <cmath>
#include <vector>

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
    if (a == 0)
        if (b != 0) cout << "1 " << -c / b << endl;
        else {
            if (c != 0) cout << "0" << endl;
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


void equation_system() {
    /*
    ax + by = e  |  e b << dx  |  a e << dy
    cx + dy = f  |  f d        |  c f
    case when a == b == e == 0 simplified with first equation replaced with second
    */
    double a, b, c, d, e, f, dt, dx, dy;
    cin >> a >> b >> c >> d >> e >> f;
    dt = a * d - b * c;
    dx = e * d - b * f;
    dy = a * f - e * c;

    if (a == 0 && b == 0 && e == 0) { a = c; b = d; e = f; }    // helps to simplify part 1, 3, 4

    if (dt != 0)
        cout << "2 " << dx / dt << " " << dy / dt << endl;      // prev task case
    else if (dx != 0 || dy != 0 || a == 0 && b == 0 && e != 0)
        cout << "0" << endl;                                    // non-zero dx, dy or 0*x+0*y = e (e != 0)
    else if (a != 0 && b != 0)
        cout << "1 " << - a / b << " " << e / b << endl;        // unlimited with y = k * x + n
    else if (b != 0)
        cout << "4 " << e / b << endl;
    else if (a != 0)
        cout << "3 " << e / a << endl;
    else
        cout << "5" << endl;
 }


const int MAX_SZ = 10000000;
int st_simples[MAX_SZ];


int find_last_simple_static(int limit) {
    int size = 1, n = 3;
    st_simples[0] = 2;
    while (n <= limit) {
        bool found = true;
        int square = 1 + (int)sqrt(n);
        for (int i = 0; i < size; i++) {
            int tmp = st_simples[i];
            if (n % tmp == 0) {
                found = false;
                break;
            }
            if (tmp > square) break;
        }
        if (found) {
            if (size < MAX_SZ)
                st_simples[size++] = n;
            else {
                cout << "Max size reached at " << n << endl;
                break;
            }
        }
        n += 2;
    }
    cout << "Array size: " << size << endl;
    return st_simples[size - 1];
}

int find_last_simple(int limit) {
    const int MAX_SIZE = 10000000;
    vector <int> simples(1, 2);
    for (int n = 3; n <= limit; n += 2) {
        bool found = true;
        int square = 1 + (int) sqrt(n);
        for (auto i : simples) {
            if (n % i == 0) {
                found = false;
                break;
            }
            if (i > square) break;
        }
        if (found) simples.push_back(n);
    }
    cout << "Array size: " << simples.size() << endl;
    return simples.back();
}

