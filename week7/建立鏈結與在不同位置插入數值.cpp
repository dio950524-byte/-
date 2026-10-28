#include <iostream>

using namespace std;

// 1. C++ 的 struct 不需要寫 typedef，且可以直接內建建構子 (Constructor)
struct Node {
    int data;
    Node *link;

    // 建構子：在 new Node(val) 時自動設定好初值與指標
    Node(int val) : data(val), link(nullptr) {}
};

// f: 插入在鏈結的最前方 (注意參數使用了傳參考 Node* &first)
void insertFront(Node* &first, int val) {
    Node *newNode = new Node(val);
    newNode->link = first;
    first = newNode;
}

// a: 插入在鏈結的尾端
void insertAfterEnd(Node* &first, int val) {
    Node *newNode = new Node(val);
    if (first == nullptr) {
        first = newNode;
        return;
    }
    Node *curr = first;
    while (curr->link != nullptr) {
        curr = curr->link;
    }
    curr->link = newNode;
}

// i: 插入在指定節點之後
void insertAtPos(Node* &first, int val, int pos) {
    // 若位置 <= 0 或目前串列為空，效果等同於 f (插在最前面)
    if (pos <= 0 || first == nullptr) {
        insertFront(first, val);
        return;
    }

    Node *curr = first;
    int count = 1;
    // 往後尋找第 pos 個節點，若中途到底則停在最後一個節點
    while (count < pos && curr->link != nullptr) {
        curr = curr->link;
        count++;
    }

    // 將新節點插在 curr 節點之後
    Node *newNode = new Node(val);
    newNode->link = curr->link;
    curr->link = newNode;
}

// 依照題目指定格式輸出串列
void printList(Node *first) {
    cout << "Created Linked list is:";
    for (; first != nullptr; first = first->link) {
        cout << " " << first->data << " "; // 每個數字前後各有一個空白
    }
    cout << "\n";
}

// 釋放記憶體
void freeList(Node* &first) {
    Node *curr = first;
    while (curr != nullptr) {
        Node *temp = curr;
        curr = curr->link;
        delete temp; // C++ 使用 delete 釋放記憶體
    }
    first = nullptr;
}

int main() {
    int t;
    if (!(cin >> t)) return 0;

    for (int tc = 0; tc < t; tc++) {
        // 每個 Test Case 之間以一空行隔開
        if (tc > 0) {
            cout << "\n";
        }

        Node *head = nullptr;
        char cmd;

        // cin >> cmd 會自動跳過所有空白與換行字元
        while (cin >> cmd) {
            if (cmd == 'f') {
                int val;
                cin >> val;
                insertFront(head, val); // 呼叫時不用再寫 &head
                printList(head);
            } else if (cmd == 'a') {
                int val;
                cin >> val;
                insertAfterEnd(head, val);
                printList(head);
            } else if (cmd == 'i') {
                int val, pos;
                cin >> val >> pos;
                insertAtPos(head, val, pos);
                printList(head);
            } else {
                // 輸入 f, a, i 以外的字元 (例如 'q') 結束當下這筆測資
                break;
            }
        }

        // 清空當前測資的串列
        freeList(head);
    }

    return 0;
}
