#include <algorithm>
#include <iostream>

using namespace std;

string solution(int x, int y)
{
    return "";
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
