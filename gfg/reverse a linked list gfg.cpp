struct Node *reverseList(struct Node *head) {
  Node *prev = NULL;
  Node *next = NULL;

  while (head) {
    next = head->next;
    head->next = prev;
    prev = head;
    head = next;
  }
  return prev;
}