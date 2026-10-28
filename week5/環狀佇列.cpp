
#include <iostream>
using namespace std;

const int MAX_SIZE = 100000;
int arr[MAX_SIZE];

int front = 0;
int rear = 0;
int N;

// 加入元素
void enqueue(int value) {
    if ((rear + 1) % N == front) {
        cout << "FULL\n";
        return;
    }

    rear = (rear + 1) % N;
    arr[rear] = value;
}

// 刪除元素
void dequeue() {
    if (front == rear) {
        cout << "EMPTY\n";
        return;
    }

    front = (front + 1) % N;
    cout << arr[front] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    int operation, value;

    while (cin >> operation && operation != -1) {
        if (operation == 1) {
            cin >> value;
            enqueue(value);
        }
        else if (operation == 0) {
            dequeue();
        }
    }

    return 0;
}
