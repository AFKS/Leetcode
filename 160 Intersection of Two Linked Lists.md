# 160 Intersection of Two Linked Lists

## Description
> Write a program to find the node at which the intersection of two singly 
> linked lists begins.
>
> <pre>
> For example, the following two linked lists:
> A:          a1 → a2
>                    ↘
>                      c1 → c2 → c3
>                    ↗            
> B:     b1 → b2 → b3
> begin to intersect at node c1.
> </pre>
>
> Notes:
>
> If the two linked lists have no intersection at all, return null.
> The linked lists must retain their original structure after the function 
> returns.
> You may assume there are no cycles anywhere in the entire linked structure.
> Your code should preferably run in O(n) time and use only O(1) memory.
>


## Solution
- **Linked List**
- ...


### Linked List
```c++
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
    ListNode* reverseList(ListNode* node){
        ListNode* res = nullptr;
        ListNode* ptr = node;
        while(ptr!=nullptr){
            ListNode* tempNode = new ListNode(ptr->val);
            tempNode->next = res;
            res = tempNode;
            ptr = ptr->next;
        }
        return res;
    }
    
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* headANew = reverseList(headA);
        ListNode* headBNew = reverseList(headB);
        ListNode* res = nullptr;
        
        while(headANew!=nullptr&&headBNew!=nullptr){
            if(headANew->val==headBNew->val){
                ListNode* temp = new ListNode(headANew->val);
                temp->next = res;
                res = temp;
            }
            
            headANew = headANew->next;
            headBNew = headBNew->next;
        }
        return res;
    }
};
```
