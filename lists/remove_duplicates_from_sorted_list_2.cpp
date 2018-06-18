/*
 *
 https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii
 *
 */


#include <unordered_map>
#include <unordered_set>
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
    unordered_map<int, int> nodes;
    ListNode *cur = head->next;
    while (cur){
        nodes[cur->val]++;
        cur = cur->next;
    }
    ListNode *new_head = nullptr;
    ListNode *new_cur = head;
    cur = head;
    while (cur){
        ListNode *next = cur->next;
        if (nodes[cur->val] == 1){
            if (!new_head){
                new_head = cur;
                new_cur = cur;
            } else {
                new_cur->next = cur;
                new_cur = new_cur->next;
            }
        }
        cur = next;
    }
    return new_head;
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