#include <bits/stdc++.h>

using namespace std;

string solution(int r, int s) {


    return "IMPOSSIBLE";
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int r, s;
        cin >> r >> s;
        auto res = solution(r, s);
        cout << "Case #" << i << ": " << res << endl;
    }
    return 0;
}
