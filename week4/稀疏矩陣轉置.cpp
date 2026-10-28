#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Term {
    int row;
    int col;
    int value;
};


// 輸入稀疏矩陣
void inputMatrix(vector<Term>& A, int n) {

    for (int i = 0; i < n; i++) {

        Term temp;

        cin >> temp.row
            >> temp.col
            >> temp.value;

        A.push_back(temp);
    }
}


// 轉置矩陣
vector<Term> transposeMatrix(const vector<Term>& A) {

    vector<Term> B;

    for (int i = 0; i < A.size(); i++) {

        Term temp;

        temp.row = A[i].col;
        temp.col = A[i].row;
        temp.value = A[i].value;

        B.push_back(temp);
    }

    return B;
}


// 排序規則
bool compareTerm(Term a, Term b) {

    if (a.row != b.row)
        return a.row < b.row;

    return a.col < b.col;
}


// 排序矩陣
void sortMatrix(vector<Term>& A) {

    sort(A.begin(), A.end(), compareTerm);
}


// 輸出矩陣
void printMatrix(const vector<Term>& A,
                 int row,
                 int col,
                 int n) {

    cout << row << " "
         << col << " "
         << n << '\n';

    for (int i = 0; i < A.size(); i++) {

        cout << A[i].row << " "
             << A[i].col << " "
             << A[i].value << '\n';
    }
}


int main() {

    int row, col, n;

    cin >> row >> col >> n;

    vector<Term> A;

    inputMatrix(A, n);

    vector<Term> B = transposeMatrix(A);

    sortMatrix(B);

    printMatrix(B, col, row, n);

    return 0;
}
