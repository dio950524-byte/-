#include <iostream>
using namespace std;

int binsearch(int list[], int searchnum, int left, int right)
{
    while (left <= right)
    {
        int middle = (left + right) / 2;

        if (searchnum < list[middle])
        {
            right = middle - 1;
        }
        else if (searchnum > list[middle])
        {
            left = middle + 1;
        }
        else
        {
            return middle;
        }
    }

    return -1;
}

int main()
{
    int searchnum;
    int n;
    int list[101];

    cin >> searchnum;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
    }

    int result = binsearch(list, searchnum, 0, n - 1);

    cout << result << endl;

    return 0;
}
