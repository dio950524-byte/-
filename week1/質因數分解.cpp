#include <iostream>
using namespace std;

int main() {
    int input;
    
    while (cin >> input) {
        bool first = true;

        // 注意：因為 i 是 int，這裡不能寫 i * i <= input，否則 i * i 會溢位變成負數造成無窮迴圈
        for (int i = 2; i <= input / i; i++) {
            if (input % i == 0) {
                int power = 0;
                while (input % i == 0) {
                    power++;
                    input /= i;
                }

                if (!first) {
                    cout << " * ";
                }
                first = false;

                if (power > 1) {
                    cout << i << "^" << power;
                } else {
                    cout << i;
                }
            }
        }

        if (input > 1) {
            if (!first) {
                cout << " * ";
            }
            cout << input;
        }

        cout << endl;
    }

    return 0;
}
