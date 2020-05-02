#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int>& slices, int l)
{
    return 0;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n, d;
        cin >> n >> d;
        vector<int> slices(n);
        for (int i = 0; i < n; i++) {
            cin >> slices[i];
        }
        auto res = solution(slices, d);
        cout << "Case #" << i << ": " << res << endl;
    }
    return 0;
}
