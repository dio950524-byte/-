
#include <bits/stdc++.h>
using namespace std;

int priority(string op) {
    if (op == "*" || op == "/") return 2;
    if (op == "+" || op == "-") return 1;
    return 0;
}

bool isOperator(string s) {
    return s == "+" || s == "-" ||
           s == "*" || s == "/";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();

    while (n--) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string token;

        stack<string> st;
        vector<string> ans;

        while (ss >> token) {

            if (token == "(") {
                st.push(token);
            }

            else if (token == ")") {
                while (!st.empty() && st.top() != "(") {
                    ans.push_back(st.top());
                    st.pop();
                }
                st.pop(); // 移除左括號
            }

            else if (isOperator(token)) {
                while (!st.empty() &&
                       st.top() != "(" &&
                       priority(st.top()) >= priority(token)) {
                    ans.push_back(st.top());
                    st.pop();
                }
                st.push(token);
            }

            else {
                ans.push_back(token);
            }
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        for (int i = 0; i < ans.size(); i++) {
            if (i > 0) cout << " ";
            cout << ans[i];
        }
        cout << "\n";
    }

    return 0;
}
