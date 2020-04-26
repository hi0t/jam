#include <algorithm>
#include <iostream>

using namespace std;

string solution(int x0, int y0)
{
    for (int steps = 0; steps < 40; steps++) {
        string res;
        long x = x0;
        long y = y0;
        for (int i = steps; i >= 0; i--) {
            long step = 1 << i;
            if (abs(x) > abs(y)) {
                if (x > 0) {
                    x -= step;
                    res.push_back('E');
                } else {
                    x += step;
                    res.push_back('W');
                }
            } else {
                if (y > 0) {
                    y -= step;
                    res.push_back('N');
                } else {
                    y += step;
                    res.push_back('S');
                }
            }
        }
        reverse(res.begin(), res.end());
        if (x == 0 && y == 0) {
            return res;
        }
    }

    return "IMPOSSIBLE";
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int x, y;
        cin >> x >> y;
        auto res = solution(x, y);
        cout << "Case #" << i << ": " << res << endl;
    }
    return 0;
}
