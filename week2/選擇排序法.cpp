#include <iostream>
using namespace std;

#define MAX_SIZE 101

void selectionSort(int list[], int n)
{
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++)
    {
        // 先假設目前位置是最小值
        min = i;

        // 從剩下的數字中尋找更小的數
        for (j = i + 1; j < n; j++)
        {
            if (list[j] < list[min])
            {
                min = j;
            }
        }

        // 把最小值跟目前位置交換
        temp = list[i];
        list[i] = list[min];
        list[min] = temp;
    }
}

int main()
{
    int n;
    int list[MAX_SIZE];

    // 輸入數字個數
    cin >> n;

    // 輸入 n 個數字
    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
    }

    // 選擇排序
    selectionSort(list, n);

    // 輸出結果
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            cout << " ";

        cout << list[i];
    }

    cout << endl;

    return 0;
}
