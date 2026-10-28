
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while (true) {
        int first;
        cin >> first;

        if (!cin || first == -1) break;

        vector<int> target(n);
        target[0] = first;

        for (int i = 1; i < n; i++) {
            cin >> target[i];
        }

        stack<int> st;
        int nextTrain = 1;
        bool possible = true;

        for (int want : target) {

            while (nextTrain <= n &&
                   (st.empty() || st.top() != want)) {
                st.push(nextTrain);
                nextTrain++;
            }

            if (!st.empty() && st.top() == want) {
                st.pop();
            }
            else {
                possible = false;
                break;
            }
        }

        cout << (possible ? "YES" : "NO") << "\n";
    }

    return 0;
}
