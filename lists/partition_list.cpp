/*
 *
 CCI 2.4 Partition List
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


ListNode* partitionList(ListNode* head, int partition) {
    ListNode *l1 = nullptr, *l2 = nullptr;
    ListNode *cur = head, *cur_l1 = l1, *cur_l2 = l2;

    while (cur){
        if (cur->val < partition){
            if (l1){
                cur_l1->next = cur;
                cur_l1 = cur_l1->next;
            } else {
                l1 = cur_l1 = cur; 
            }
        } else {
            if (l2){
                cur_l2->next = cur;
                cur_l2 = cur_l2->next;
            } else {
                l2 = cur_l2 = cur; 
            }
        }
        cur = cur->next;
    }
    if (l1){
        cur_l1->next = l2;
        cur_l2->next = nullptr;
    } else {
        l1 = l2;
    }
    return l1;
}

int main (){
    ListNode *l1 = new ListNode (10);
    l1->next = new ListNode (1);
    l1->next->next = new ListNode (3); 
    l1->next->next->next = new ListNode (4);
    l1->next->next->next->next = new ListNode (7);
    l1->next->next->next->next->next = new ListNode (4);
    l1->next->next->next->next->next->next = new ListNode (11);
    l1->next->next->next->next->next->next->next = new ListNode (2);

    ListNode* result = partitionList(l1, 4);
    int i = 0;
    while (result){
        cout << result->val << ' ';
        result = result->next;
        if (i++ > 100) {break;}
    }
    cout << endl;

    return 0;
}