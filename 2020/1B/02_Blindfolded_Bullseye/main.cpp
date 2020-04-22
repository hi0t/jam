#include <bits/stdc++.h>

using namespace std;

const long M = 1e9;

string ask(long x, long y) {
    cout << x << ' ' << y << endl;
    string s;
    cin >> s;
    if (s == "WRONG") {
        exit(0);
    }
    return s;
}

void solution(int test) {
    long x0, y0;
    bool ok = false;

    for (long x : {-M/2, 0L, M/2}) {
        for (long y : {-M/2, 0L, M/2}) {
            string s = ask(x, y);
            if (s == "CENTER") {
                return;
            } else if (s == "HIT") {
                x0 = x;
                y0 = y;
                ok = true;
                break;
            }
        }
        if (ok) {
            break;
        }
    }

    long l = -M - 1, r = x0;
    while (r - l > 1) {
        long c = (l + r) / 2;
        string s = ask(c, y0);
        if (s == "CENTER") {
            return;
        }
        if (s == "HIT") {
            r = c;
        } else {
            l = c;
        }
    }

    long xl = r;
    l = x0; r = M + 1;
    while (r - l > 1) {
        long c = (l + r) / 2;
        string s = ask(c, y0);
        if (s == "CENTER") {
            return;
        }
        if (s == "HIT") {
            l = c;
        } else {
            r = c;
        }
    }

    long xr = l;
    long xc = (xl + xr) / 2;
    l = -M - 1; r = y0;
    while (r - l > 1) {
        long c = (l + r) / 2;
        string s = ask(xc, c);
        if (s == "CENTER") {
            return;
        }
        if (s == "HIT") {
            r = c;
        } else {
            l = c;
        }
    }

    long yl = r;
    l = y0; r = M + 1;
    while (r - l > 1) {
        long c = (l + r) / 2;
        string s = ask(xc, c);
        if (s == "CENTER") {
            return;
        }
        if (s == "HIT") {
            l = c;
        } else {
            r = c;
        }
    }

    long yr = l;
    long yc = (yl + yr) / 2;
    string s = ask(xc, yc);
    assert(s == "CENTER");
}

int main() {
    int t;
    cin >> t;
    long a, b;
    cin >> a >> b;
    for (int i = 1; i <= t; i++) {
        solution(i);
    }
    return 0;
}
