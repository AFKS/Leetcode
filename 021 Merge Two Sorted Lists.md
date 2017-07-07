# 021 Merge Two Sorted Lists

## Description
> Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(INT_MIN);
        dummyHead->next = l1;
        
        ListNode* ptr1 = dummyHead;
        ListNode* ptr2 = l2;
        while(ptr1->next!=nullptr&&ptr2!=nullptr){
            
            int lfOfList1Node = ptr1->val;
            int rtOfList1Node = ptr1->next->val;
            if (ptr2->val>=lfOfList1Node&&ptr2->val<=rtOfList1Node){
                //insert new node in list1
                ListNode* newNodeInList1 = new ListNode(ptr2->val);
                newNodeInList1->next = ptr1->next;
                //adjust ptr1 position
                ptr1->next = newNodeInList1;
                ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
        }
        if (ptr2!=nullptr) ptr1->next = ptr2;
        return dummyHead->next;
    }
};
```
