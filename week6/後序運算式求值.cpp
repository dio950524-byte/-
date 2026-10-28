
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    stack<int> st;
    string token;

    while (cin >> token) {

        if (token == "+" || token == "-" ||
            token == "*" || token == "/" ||
            token == "%") {

            int b = st.top();
            st.pop();

            int a = st.top();
            st.pop();

            int result = 0;

            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else if (token == "/") result = a / b;
            else if (token == "%") result = a % b;

            st.push(result);
        }
        else {
            st.push(stoi(token));
        }
    }

    cout << st.top() << "\n";

    return 0;
}
