/*
 *
 https://leetcode.com/problems/merge-two-sorted-lists/
 *
 */


#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = NULL;
        ListNode* cur = NULL;
        if (!l1) {return l2;}
        if (!l2) {return l1;}
        if (l1->val < l2->val){
            res = cur = l1;
            l1 = l1->next;
        } else {
            res = cur = l2;
            l2 = l2->next; 
        }
        while (l1 && l2){
            if (l1->val < l2->val){
                ListNode* prev = l1;             
                l1 = l1->next;
                cur->next = prev;
            } else {
                ListNode*  prev = l2;   
                l2 = l2->next;    
                cur->next = prev;
            }
            cur = cur->next;
        }
        if (l1){
            cur->next = l1;
        }
        if (l2){
            cur->next = l2;
        }
        return res;
    }

int main (){
    ListNode *l1 = new ListNode (1);
    l1->next = new ListNode (1);
    l1->next->next = new ListNode (3); 
    l1->next->next->next = new ListNode (4);
    l1->next->next->next->next = new ListNode (4);
    l1->next->next->next->next->next = new ListNode (4);
    l1->next->next->next->next->next->next = new ListNode (7);

    ListNode *l2 = new ListNode (3);
    l2->next = new ListNode (3);
    l2->next->next = new ListNode (3); 
    l2->next->next->next = new ListNode (5);
    ListNode* result = mergeTwoLists(l1, l2);
    while (result){
        cout << result->val << ' ';
        result = result->next;
    } 
    cout << endl;

    return 0;
}