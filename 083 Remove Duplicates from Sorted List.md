# 083 Remove Duplicates from Sorted List
## Description
> Given a sorted linked list, delete all duplicates such that each element appear only once.
> 
> For example,
> Given 1->1->2, return 1->2.
> Given 1->1->2->3->3, return 1->2->3.

## Solution
- **Linked List**
- ...

### Linked List
```
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummyHead = new ListNode (0);
        dummyHead->next = head;
        
        //@ two pointers method
        ListNode* ptr1 = head;
        while(ptr1!=nullptr&&ptr1->next!=nullptr){
            ListNode* ptr2 = ptr1->next;
            while (ptr2!=nullptr && ptr1->val == ptr2->val)
                ptr2 = ptr2->next;
            ptr1->next = ptr2;
            ptr1 = ptr1->next; 
        }
        return dummyHead->next;
    }
};
```
