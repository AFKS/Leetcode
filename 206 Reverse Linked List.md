# 206 Reverse Linked List
## Description
> Reverse a singly linked list.
>
> click to show more hints.
>
> Hint:
> A linked list can be reversed either iteratively or recursively. Could you
> implement both?

## Solution
- **Linked List**


### Linked List

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //new reverseList initialization with nullptr
        ListNode* res = nullptr;
        
        while(head!=nullptr){
            //recored the next node for reverse
            ListNode* tempNext = head->next;
            head->next = res;
            res = head;
            head = tempNext;
        }
        return res;
    }
};
```

