/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
 
 void reversekth(ListNode* head) {
    ListNode* cur = head;
    ListNode* prev = NULL;
    while(cur!=NULL){
        ListNode* nex = cur->next;
        cur->next =prev;
        prev = cur;
        cur = nex;
    }
 }
 ListNode* kthNode(ListNode* head,int k) {
    k -= 1;
    while(head != NULL && k>0) {
        k--;
        head = head->next;
    }
    return head;
 }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL) {
            ListNode* kth = kthNode(temp,k);
            if(kth == NULL){
                if(prev) prev->next = temp;
                break;
            }
            ListNode* nex = kth->next;
            kth->next = NULL;
            reversekth(temp);
            if(head == temp) {
                head = kth;
            }
            else{
             prev->next =kth;
            }
            prev = temp;
            temp = nex;
        }
        return head;
    }
};