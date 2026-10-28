#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Term {
    int row;
    int col;
    long long value;
};

bool cmp(Term a, Term b) {
    if (a.row != b.row)
        return a.row < b.row;

    return a.col < b.col;
}

int main() {

    int n;
    cin >> n;

    vector<Term> A;

    for (int i = 0; i < n; i++) {

        char ch;
        Term temp;

        cin >> ch;          // (
        cin >> temp.row;
        cin >> ch;          // :
        cin >> temp.col;
        cin >> ch;          // )
        cin >> ch;          // =
        cin >> temp.value;

        A.push_back(temp);
    }

    vector<Term> result;

    // A × A^T
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            // column 相同才會產生乘積
            if (A[i].col == A[j].col) {

                Term temp;

                temp.row = A[i].row;
                temp.col = A[j].row;
                temp.value = A[i].value * A[j].value;

                result.push_back(temp);
            }
        }
    }

    // 按 row，再按 col 排序
    sort(result.begin(), result.end(), cmp);

    // 合併相同位置
    for (int i = 0; i < result.size(); ) {

        int row = result[i].row;
        int col = result[i].col;

        long long sum = 0;

        int j = i;

        while (j < result.size() &&
               result[j].row == row &&
               result[j].col == col) {

            sum += result[j].value;
            j++;
        }

        if (sum != 0) {
            cout << row << " "
                 << col << " "
                 << sum << '\n';
        }

        i = j;
    }

    return 0;
}
