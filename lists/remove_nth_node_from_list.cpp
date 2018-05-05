/*
 *
 https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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


ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *end = head;
    for (int i=0; i<n; i++){
        end = end->next;
    }
    if (!end) {return head->next;}
    ListNode *nth = head;
    while(end->next){
        nth = nth->next;
        end = end->next;
    }
    if (nth->next){
        nth->next = nth->next->next;
    }
    return head;
}

int main (){
    ListNode *l1 = new ListNode (9);
    l1->next = new ListNode (8);
    l1->next->next = new ListNode (3); 
    l1->next->next->next = new ListNode (6);
    l1->next->next->next->next = new ListNode (4);

    ListNode* result = removeNthFromEnd(l1,3);
    while (result){
        cout << result->val << ' ';
        result = result->next;
    } 
    cout << endl;

    return 0;
}