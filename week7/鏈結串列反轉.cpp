void reverse(Node **head) {
    Node *prev = NULL;
    Node *curr = *head;
    Node *next = NULL;

    while (curr != NULL) {
        next = curr->nxt; // 1. 先把下一個節點記下來，避免斷鏈
        curr->nxt = prev; // 2. 將目前節點的指標反轉，指向前一個節點
        prev = curr;      // 3. prev 往前推進到目前節點
        curr = next;      // 4. curr 往前推進到下一個節點
    }

    *head = prev; // 5. 最後將原本的 head 更新為新的頭節點（即原本的最後一個節點）
}
