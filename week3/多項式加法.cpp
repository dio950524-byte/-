
#include<bits/stdc++.h>
using namespace std;

typedef struct {
    float coef;
    unsigned int expon;
} polynomial;

// 輸出多項式
void printPoly(vector<polynomial>& a) {

    bool first = true;

    for(int i = 0; i < a.size(); i++) {

        if(a[i].coef == 0) continue;

        if(a[i].coef > 0 && first == false) {
            cout << "+";
        }

        cout << fixed << setprecision(2) << a[i].coef;

        if(a[i].expon > 1) {
            cout << "x^" << a[i].expon;
        }
        else if(a[i].expon == 1) {
            cout << "x";
        }

        first = false;
    }

    if(first == true) cout << "0.00";

    cout << endl;
}

int main() {

    int n, m;
    cin >> n;

    vector<polynomial> A(n);

    for(int i = 0; i < n; i++) {
        cin >> A[i].coef >> A[i].expon;
    }

    cin >> m;

    vector<polynomial> B(m);

    for(int i = 0; i < m; i++) {
        cin >> B[i].coef >> B[i].expon;
    }

    vector<polynomial> C;

    int i = 0;
    int j = 0;

    while(i < n && j < m) {

        if(A[i].expon > B[j].expon) {
            C.push_back(A[i]);
            i++;
        }
        else if(A[i].expon < B[j].expon) {
            C.push_back(B[j]);
            j++;
        }
        else {
            float sum = A[i].coef + B[j].coef;

            if(sum != 0) {
                polynomial temp;
                temp.coef = sum;
                temp.expon = A[i].expon;

                C.push_back(temp);
            }

            i++;
            j++;
        }
    }

    while(i < n) {
        C.push_back(A[i]);
        i++;
    }

    while(j < m) {
        C.push_back(B[j]);
        j++;
    }

    printPoly(A);
    printPoly(B);
    printPoly(C);

    return 0;
}
