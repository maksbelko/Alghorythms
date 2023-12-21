#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *swapPairs(ListNode *head);
ListNode *reverseKGroup(ListNode *head, int k);
void showList(ListNode *head);
int main() {
  ListNode *myList =
      new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
  showList(myList);
  // ListNode *newHead = swapPairs(myList);
  ListNode *reveresedHead = reverseKGroup(myList, 4);
  showList(reveresedHead);
  // showList(newHead);
  // delete newHead;
  delete myList;
}
void showList(ListNode *head) {
  if (!head) {
    return;
  } else {
    std::cout << head->val << ", ";
    showList(head->next);
  }
}
// TASK 1
// Given a linked list, swap every two adjacent nodes and return its head.
// You must solve the problem without modifying the values in the list's nodes
// (i.e., only nodes themselves may be changed.)

//  Input: head = [1,2,3,4]
// Output: [2,1,4,3]
// special cases:
// if empty or only 1 element
ListNode *swapPairs(ListNode *head) {
  // special cases
  if (!head || !head->next) {
    return head;
  }
  // add empty node to solve problem easier
  ListNode *begin = new ListNode();
  ListNode *prev = begin;
  ListNode *current = head;
  while (current && current->next) {
    // change states
    prev->next = current->next;
    current->next = prev->next->next;
    prev->next->next = current;
    // next step
    prev = current;
    current = current->next;
  }

  return begin->next;
}
// TASK 2
// Given the head of a linked list, reverse the nodes of the list k at a time,
// and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked
// list. If the number of nodes is not a multiple of k then left-out nodes, in
// the end, should remain as it is.

ListNode *reverseKGroup(ListNode *head, int k) {
  int timesToSwap = k - 1;
  ListNode *cur = head;
  ListNode *newHead = head;
  while (timesToSwap > 0) {
    // move element
    // for (int i = timesToSwap; i > 0; i--) {
    //   cur->next = next->next;
    //   next->next = cur->next;
    //   if (i == timesToSwap) {
    //       newHead = next;
    //   }
    //   next = cur->next;
    // }
    ListNode *elemToMove = cur;
    newHead = cur->next;
    for (int i = timesToSwap; i > 0; i--) {
      cur = cur->next;
    }
    elemToMove->next = cur->next;

    timesToSwap--;
    cur = newHead;
    next = cur->next;

    // reduce timeToSwap
    // set cur to head
  }
  return newHead;
}
