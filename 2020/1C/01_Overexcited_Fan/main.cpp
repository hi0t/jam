#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string solution(int x, int y, string& m)
{
    int res;
    int len = numeric_limits<int>::max();

    for (int i = 0; i < m.size(); i++) {
        switch (m[i]) {
        case 'N':
            y++;
            break;
        case 'S':
            y--;
            break;
        case 'E':
            x++;
            break;
        case 'W':
            x--;
            break;
        default:
            break;
        }
        int d = abs(x) + abs(y);
        if ((d == i || d == i + 1) && d < len) {
            len = d;
            res = i + 1;
        }
    }

    if (len == numeric_limits<int>::max()) {
        return "IMPOSSIBLE";
    }

    return to_string(res);
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int x, y;
        string m;
        cin >> x >> y >> m;
        auto res = solution(x, y, m);
        cout << "Case #" << i << ": " << res << endl;
    }
    return 0;
}
