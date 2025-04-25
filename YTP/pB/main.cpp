#include <bits/stdc++.h> 

using namespace std;

struct stu {
    string nm;
    double p;
};

int main() {

    int n;
    cin >> n;

    vector<stu> s(n);

    for (int i = 0; i < n; ++i) {
        cin >> s[i].nm >> s[i].p;
    }

    int mx = s[0].p;
    string mxs = s[0].nm;

    for (auto& stu : s) {
        if (stu.p > mx) {
            mx = stu.p;
            mxs = stu.nm;
        }
    }

    cout << mxs << '\n';

    return 0;
}