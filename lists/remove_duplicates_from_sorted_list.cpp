/*
 *
 https://leetcode.com/problems/remove-duplicates-from-sorted-list
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


ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next){return head;}
    ListNode *prev = head;
    ListNode *cur = head->next;
    while (cur){
        if (prev->val == cur->val){
            prev->next = cur->next;
        } else {
            prev = cur;
        }
        cur = cur->next;
    }
    return head;
}

int main (){
    ListNode *l1 = new ListNode (1);
    l1->next = new ListNode (1);
    l1->next->next = new ListNode (3); 
    l1->next->next->next = new ListNode (4);
    l1->next->next->next->next = new ListNode (4);
    l1->next->next->next->next->next = new ListNode (4);
    l1->next->next->next->next->next->next = new ListNode (7);

    ListNode* result = deleteDuplicates(l1);
    while (result){
        cout << result->val << ' ';
        result = result->next;
    } 
    cout << endl;

    return 0;
}