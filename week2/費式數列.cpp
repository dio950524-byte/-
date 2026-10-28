#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long a = 0;   // F0
    long long b = 1;   // F1

    for (int i = 0; i < n; i++)
    {
        long long next = a + b;
        a = b;
        b = next;
    }

    cout << a << endl;

    return 0;
}
