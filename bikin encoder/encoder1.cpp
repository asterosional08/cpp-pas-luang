#include <iostream>
#include <vector>
using namespace std;

int wrap(int x) {
    if (x > 126) return 32 + (x - 127);
    if (x < 32) return 127 - (32 - x);
    return x;
}

int main() {
    vector<char> text, bansk;
    char c, big = '?', small = '?';
    bool first = true;

    while (cin.get(c)) {
        if (c == '\n') break;
        text.push_back(c);
        if (first) {
            big = c;
            small = c;
            first = false;
        } else {
            if (c < small) small = c;
            if (c > big) big = c;
        }
    }

    if (text.empty()) return 0;

    int verage = ((small + big) / 2) % 95;

    for (int i = 0; i < text.size(); i++) {
        if (i % 2 == 0) {
            bansk.push_back(wrap(text[i] + verage));
            bansk.push_back(wrap(text[i] - verage));
        } else {
            bansk.push_back(wrap(text[i] - verage));
            bansk.push_back(wrap(text[i] + verage));
        }
    }

    for (char b : bansk) cout << b;
}
