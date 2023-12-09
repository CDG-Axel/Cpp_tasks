#include <iostream>
#include <map>
#include <set>

using namespace std;

string lowercase(string s) {
    string result;
    for (auto c: s) result.push_back(tolower(c));
    return result;
}

int main() {
    map <string, set<string>> dict;
    int n, errors = 0;
    string word;
    cin >> n;

    while (n--) {
        cin >> word;
        dict[lowercase(word)].insert(word);
    }

    while (cin >> word) {
        int capitals = 0;
        for (auto c: word) capitals += c == toupper(c);
        string lower = lowercase(word);
        errors += capitals != 1 || dict.count(lower) && !dict[lower].count(word);
    }

    cout << errors;
}
