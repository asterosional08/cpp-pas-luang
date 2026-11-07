#include <iostream>
#include <string>
using namespace std;

int mod95(int x) {
    x %= 95;
    if (x < 0) x += 95;
    return x;
}

int main() {
    string s;
    if (!getline(cin, s)) return 0;
    if (s.empty()) return 0;

    if (s.size() < 2) return 0;

    const int kringkring = 48;

    int A0 = mod95((int)s[0] - 32);
    int B0 = mod95((int)s[1] - 32);

    int diff = mod95(A0 - B0);
    int v = (diff * kringkring) % 95;

    string out;
    size_t pairs = s.size() / 2;
    for (size_t j = 0; j < pairs; ++j) {
        int i = 2 * j;
        int first = mod95((int)s[i] - 32);
        int second = mod95((int)s[i+1] - 32);

        int a, b;
        if (j % 2 == 0) {
            a = first; b = second;
        } else {
            a = second; b = first;
        }

        int xmod = ( (a + b) % 95 * kringkring ) % 95;
        char orig = (char)(xmod + 32);
        out.push_back(orig);
    }

    cout << out;
    return 0;
}
