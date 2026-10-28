#include <bits/stdc++.h>
using namespace std;

struct Term{
    int row;
    int col;
    int value;
};

void inputMatrix(vector<Term>& A, int n){

    for(int i = 0; i < n; i++){

        Term temp;

        cin >> temp.row
            >> temp.col
            >> temp.value;

        A.push_back(temp);
    }
}

bool cmp(Term a, Term b){

    if(a.row != b.row)
        return a.row < b.row;

    return a.col < b.col;
}

vector<Term> transposeMatrix(const vector<Term>& A){

    vector<Term> B;

    for(int i = 0; i < A.size(); i++){

        Term temp;

        temp.row = A[i].col;
        temp.col = A[i].row;
        temp.value = A[i].value;

        B.push_back(temp);
    }

    sort(B.begin(), B.end(), cmp);

    return B;
}

void printMatrix(const vector<Term>& B, int row, int col, int n){

    cout << row << " " << col << " " << n << '\n';

    for(int i = 0; i < B.size(); i++){

        cout << B[i].row << " "
             << B[i].col << " "
             << B[i].value << '\n';
    }
}

int main(){

    int row, col, n;

    cin >> row >> col >> n;

    vector<Term> A;

    inputMatrix(A, n);

    vector<Term> B = transposeMatrix(A);

    printMatrix(B, col, row, n);

    return 0;
}
